#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],dp[maxn];
int main(){
    memset(dp,-0x3f,sizeof(dp));
    int t=read();
    while(t--){
        int n=read(),p=read();
        for(int i=1;i<=n;i++) a[i]=read();
        int x=0;dp[x]=0;
        int mx=0;
        for(int i=1;i<=n;i++){
            x=(x+a[i])%p;
            dp[x]=max(dp[x]+1,mx);
            mx=max(dp[x],mx);
        }
        printf("%d\n",mx);
        x=0;dp[x]=-inf;
        for(int i=1;i<=n;i++){
            x=(x+a[i])%p;
            dp[x]=-inf;
        }
    }
    return 0;
}