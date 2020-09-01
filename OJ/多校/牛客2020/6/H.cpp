#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int len,num[107];
const int mod=1e9+7;
int add(int a,int b){
    return a+b>=mod?a+b-mod:a+b;
}
int dpnn[107][1807],dpny[107][1807],dpyn[107][1807],dpyy[107][1807];
char s[107];
void solve(){
    scanf("%s",s+1);
	len=strlen(s+1);
    for(int i=1;i<=len;i++) num[i]=s[len-i+1]-'0';
    dpnn[0][900]=1;
    dpny[0][900]=1;
    dpyn[0][900]=1;
    dpyy[0][900]=1;
    for(int i=1;i<=len;i++){
        for(int k=0;k<=1800;k++){
            for(int z=0;z<=9;z++)
            for(int j=0;j<=9;j++){
                if(k-(z-j)>=0&&k-(z-j)<=1800) 
                dpnn[i][k]=add(dpnn[i][k],dpnn[i-1][k-(z-j)]);
            }
        }
    }
    //cout<<len<<" "<<dpnn[len][900]<<endl;
    for(int i=1;i<=len;i++){
        for(int k=0;k<=1800;k++){
            for(int z=0;z<=9;z++){
                for(int j=0;j<=z;j++){
                    if(k-(z-j)>=0&&k-(z-j)<=1800){
                        dpny[i][k]=add(dpny[i][k],j==z?dpny[i-1][k-(z-j)]:dpnn[i-1][k-(z-j)]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=len;i++){
        for(int k=0;k<=1800;k++)
        for(int z=0;z<=num[i];z++){
            for(int j=0;j<=9;j++)
            if(k-(z-j)>=0&&k-(z-j)<=1800)
            dpyn[i][k]=add(dpyn[i][k],z==num[i]?dpyn[i-1][k-(z-j)]:dpnn[i-1][k-(z-j)]);
        }
    }
    for(int i=1;i<=len;i++){
        for(int k=0;k<=1800;k++)
        for(int z=0;z<=num[i];z++){
            for(int j=0;j<=z;j++)
            if(k-(z-j)>=0&&k-(z-j)<=1800){
                dpyy[i][k]=add(dpyy[i][k],z==num[i]&&j==z?dpyy[i-1][k-(z-j)]:z!=num[i]&&j==z?dpny[i-1][k-(z-j)]:z==num[i]&&j!=z?dpyn[i-1][k-(z-j)]:dpnn[i-1][k-(z-j)]);
            }
        }
    }
    //cout<<dpny[1][899]<<endl;
    int ans=0;
    for(int k=0;k<900;k++) {
        ans=add(ans,dpyy[len][k]);
    //    if(dpyy[len][k]) cout<<len<<" "<<k-900<<" "<<dpyy[len][k]<<endl;
    }
    cout<<ans;
}
int main(){
    solve();
	return 0;
}