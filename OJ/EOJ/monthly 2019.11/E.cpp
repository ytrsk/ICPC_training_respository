#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5000007;
const int N=1000000;
const int mod=998244353;
int e1,mu[maxn],p[maxn],sum1[maxn],phi[maxn];
unordered_map<int,int> a1;
void pre(){
    phi[1]=mu[1]=1;
    for(int i=2;i<=N;i++){
        if(!phi[i]){
            p[++e1]=i;mu[i]=-1;phi[i]=i-1;
        }
        for(int k=1;k<=e1&&p[k]*i<=N;k++){
            if(i%p[k]==0){
                phi[i*p[k]]=phi[i]*p[k];break;
            }
            else mu[i*p[k]]=-mu[i],phi[i*p[k]]=phi[i]*phi[p[k]];
        }
    }
    for(int i=1;i<=N;i++) sum1[i]=sum1[i-1]+mu[i];
}
int djs1(int x){
    if(x<=N) return sum1[x];
    if(a1.count(x)) return a1[x];
    int ans=1;
    for(int l=2,r;l<=x;l=r+1){
        r=x/(x/l);
        ans-=(r-l+1)*djs1(x/l);
    }
    return a1[x]=ans;
}
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
int main(){
    int N=read(),m=read();
    pre();
    djs1(N);n=m+1;init();
    int now=0;
    for(int i=1;i<=m+2;i++){
        add(now,pown(i,m));
        Y[i-1]=now;
    }
    int ans=0;
    for(int l=1,r;l<=N;l=r+1){
        r=N/(N/l);
        int x=djs1(N/l);
        x=(x%mod+mod)%mod;
        add(ans,1LL*x*(0LL+f(r-1)-f(l-2)+mod)%mod);
    }
    cout<<ans;
    return 0;
}
