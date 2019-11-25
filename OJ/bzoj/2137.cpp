#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
ll read(){
    ll x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int Pre[maxn],Suf[maxn],n,Y[maxn],fac[maxn],fav[maxn];
inline int pown(int a,ll b){
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
    Suf[n+1]=1;Pre[0]=x%mod;
    for(int i=1;i<=n;i++) Pre[i]=(1LL*Pre[i-1]*(mod+x%mod-i))%mod;
    for(int i=n;~i;i--) Suf[i]=(1LL*Suf[i+1]*(x%mod-i+mod))%mod;
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
int main(){
    int nn=read();ll m=read();
    int now=0;n=min(m+2,100000LL);init();
    for(int i=1;i<=100004;i++){
        add(now,pown(i,m));Y[i-1]=now;
    }
    int ans=1;
    for(int i=1;i<=nn;i++){
        ll x=read();x%=mod;
        ans=(1LL*ans*(x<=100003?Y[x]:f(x)))%mod;
    }
    cout<<ans;
    return 0;
}
