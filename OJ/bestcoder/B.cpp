#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[11]={95,90,85,80,75,70,67,65,62,60,0};
int b[11]={43,40,37,33,30,27,23,20,17,10,0};
int main(){
    int t=read();
    while(t--){
        int x=read(),now=0;
        for(int i=0;i<11;i++){
            for(int k=0;k<11;k++)
            for(int z=0;z<11;z++){
                for(int j=0;j<11;j++){
                    if(a[i]+a[k]+a[z]+a[j]<=x){
                        now=max(now,b[i]+b[k]+b[z]+b[j]);
                    }
                }
            }
        }
        printf("%.1f\n",now/10.0);
    }
    return 0;
}