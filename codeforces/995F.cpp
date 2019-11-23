#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int Pre[maxn],Suf[maxn],n,Y[maxn],fac[maxn],fav[maxn];
inline int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
inline void add(int &x,int y){
    x+=y;if(x>=mod) x-=mod;
}
//从0到n，插n+1次,处理n次多项式
inline int f(int x){
    if(x<0) return 0;
    Suf[n+1]=1;Pre[0]=x;
    for(int i=1;i<=n;i++) Pre[i]=(1LL*Pre[i-1]*(mod+x-i))%mod;
    for(int i=n;~i;i--) Suf[i]=(1LL*Suf[i+1]*(x-i+mod))%mod;
    int ans=0;
    for(int i=0;i<=n;i++) {
        int now=1LL*fav[i]*fav[n-i]%mod*(i?Pre[i-1]:1)%mod*Suf[i+1]%mod*Y[i]%mod;
        (n-i)&1?add(ans,mod-now):add(ans,now);
    }
    return ans;
}
void init(){
    fac[0]=1;for(int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%mod;
    fav[n]=pown(fac[n],mod-2);for(int i=n-1;~i;i--) fav[i]=1LL*fav[i+1]*(i+1)%mod;
}
int head[maxn],to[maxn<<1],nex[maxn<<1],e1,nn;
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int dp[3007][3007];
void dfs(int u){
    for(int i=1;i<=nn+3;i++) dp[u][i]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        dfs(v);
        for(int k=1;k<=nn+3;k++) dp[u][k]=1LL*dp[v][k]*dp[u][k]%mod;
    }
    for(int i=2;i<=nn+3;i++) add(dp[u][i],dp[u][i-1]);
}
int main(){
    nn=read();int m=read();
    for(int i=2;i<=nn;i++){
        int u=read();
        addedge(u,i);
    }
    dfs(1);
    n=nn+2;init();for(int i=0;i<=n;i++) Y[i]=dp[1][i+1];
    printf("%d",f(m-1));
    return 0;
}
