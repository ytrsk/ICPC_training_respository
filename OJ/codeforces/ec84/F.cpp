#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=500007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int L[maxn],R[maxn],x[maxn];
int mn[maxn][31];
int mx[maxn][31];
const int mod=998244353;
int dp[maxn],sum[maxn];
int main(){
    int n=read(),K=read(),m=read();
    memset(mn,0x3f,sizeof(mn));
    memset(mx,-0x3f,sizeof(mx));
    for(int i=1;i<=m;i++){
        L[i]=read();R[i]=read();x[i]=read();
        for(int k=0;k<K;k++){
            if(x[i]>>k&1) mx[L[i]][k]=max(mx[L[i]][k],R[i]);
            else mn[L[i]][k]=min(mn[L[i]][k],R[i]);
        }
    }
    int now=0,ans=1;
    for(int i=0;i<K;i++){
        memset(dp,0,sizeof(dp));memset(sum,0,sizeof(sum));
        dp[0]=1;now=-1;
        mn[n+2][i]=inf;
        for(int k=n+1;k>=0;k--) mn[k][i]=min(mn[k][i],mn[k+1][i]);
        int Now=0;
        for(int k=0;k<=n+1;k++){
            Now=(Now+sum[k])%mod;
            now=max(now,mx[k][i]);
            if(now>=k&&k) continue;
            dp[k]=(dp[k]+Now)%mod;
            sum[k+1]=(sum[k+1]+dp[k])%mod;
            if(mn[k+1][i]!=inf) sum[mn[k+1][i]+1]=(sum[mn[k+1][i]+1]+mod-dp[k])%mod;
        }
        ans=(1LL*ans*dp[n+1])%mod;
    }
    printf("%d\n",ans);
    return 0;
}