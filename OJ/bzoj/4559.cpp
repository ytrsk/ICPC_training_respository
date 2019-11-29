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
int c(int a,int b){
    if(b>a) return 0;
    return 1LL*fac[a]*fav[b]%mod*fav[a-b]%mod;
}
int p(int a,int b){
    return 1LL*fac[a]*fav[a-b]%mod;
}
int a[maxn],b[maxn],tot[maxn],dp[107][107];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int nn=read(),m=read(),r=read();
    nn--;n=300;init();
    for(int i=1;i<=m;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    int ans=0;
    for(int i=1;i<=m;i++) b[i]=nn+1-b[i];
    dp[0][nn]=1;
    for(int i=1;i<=m;i++){
        n=nn+1;int now=0;
        for(int k=1;k<=n+1;k++){
            add(now,1LL*pown(k,b[i])*pown((a[i]-k+mod)%mod,nn-b[i])%mod);
            Y[k-1]=now;
        }
        int to=f(a[i]-1);
        for(int k=0;k<=nn;k++){
            for(int z=k;z<=nn;z++){
                if(k<=b[i]&&z-k<=nn-b[i]) add(dp[i][k],1LL*dp[i-1][z]*c(z,k)%mod*c(nn-z,b[i]-k)%mod);
            }
            dp[i][k]=1LL*dp[i][k]*to%mod;
        }
    }
    cout<<dp[m][r];
    return 0;
}
