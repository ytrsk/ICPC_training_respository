#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=500007;
const int mod=1e9+7;
const int inf=(1LL<<29);
int p[maxn],ee,e1;
int id1[maxn],id2[maxn],sqr,sum[maxn];
ll q[maxn<<1],n,g[maxn<<1],h[maxn<<1];
bool vis[maxn];
void prime(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]) p[++e1]=i,sum[e1]=(sum[e1-1]+i)%mod;
        for(int k=1;k<=e1&&p[k]*i<=n;k++){
            vis[i*p[k]]=1;
            if(i%p[k]==0) break;
        }
    }
}
void pre(){
    for(ll l=1,r;l<=n;l=r+1){
        r=n/(n/l);q[++ee]=n/l;
        if(q[ee]<=sqr) id1[q[ee]]=ee;
        else id2[n/q[ee]]=ee;
        g[ee]=(q[ee]&1)?((q[ee]-1)>>1)%mod*((q[ee]+2)%mod)%mod:((q[ee]+2)>>1)%mod*((q[ee]-1)%mod)%mod;
        h[ee]=(q[ee]-1)%mod;
    }
    for(int i=1;i<=e1;++i)
    for(int k=1;k<=ee&&1LL*p[i]*p[i]<=q[k];++k){
        int pos=(q[k]/p[i]<=sqr)?id1[q[k]/p[i]]:id2[n/(q[k]/p[i])];
        g[k]=(g[k]-p[i]*(g[pos]-sum[i-1])%mod+mod)%mod;
        h[k]=(h[k]-(h[pos]-(i-1))%mod+mod)%mod;
    }
}
ll f(ll x,int y){
    return x^y;
}
int S(ll x,int y){
    if(x<=1||p[y]>x) return 0;
    int pos=(x<=sqr)?id1[x]:id2[n/x];
    ll ans=(g[pos]-h[pos]+mod-sum[y-1]+(y-1)+mod)%mod;
    if(y==1) (ans+=2)%=mod;
    for(int i=y;i<=e1&&1LL*p[i]*p[i]<=x;++i){
        ll p1=p[i],p2=1LL*p[i]*p[i];
        for(int e=1;p2<=x;++e,p1=p2,p2*=p[i]){
            (ans+=(1LL*S(x/p1,i+1)*f(p[i],e)%mod+f(p[i],e+1))%mod)%=mod;
        }
    }
    return ans;
}
int main(){
   // cin.tie(0);ios_base::sync_with_stdio(false);
    cin>>n;sqr=(int)sqrt(n+0.5);
    prime(sqr);pre();
    printf("%d",(S(n,1)+1)%mod);
    return 0;
}
