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
ll dp[maxn];int a[maxn];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(int k=1;2*k<i;k++){
            dp[i]++; 
        }
    }
    if(m>dp[n]) printf("-1");
    else{
        for(int i=1;i<=n;i++){
            if(dp[i]>=m){
                if(dp[i]==m){
                    for(int k=1;k<=i;k++) a[k]=k;
                    for(int k=i+1;k<=n;k++) a[k]=a[k-1]+5001;
                    break;
                }
                m-=dp[i-1];
                for(int k=1;k<=i-1;k++) a[k]=k;
                for(int k=i;;k++){
                    int now=0;
                    for(int z=1;z<=i-1;z++){
                        if(k-z>z&&k-z<=i-1) now++;
                    }
                    if(now==m){
                        a[i]=k;break;
                    }
                }
                for(int k=i+1;k<=n;k++) a[k]=a[k-1]+5001;
                break;
            }
        }
    }
    if(m<=dp[n])
    for(int i=1;i<=n;i++)
    printf("%d ",a[i]);
    return 0;
}