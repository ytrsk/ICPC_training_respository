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
ll q[maxn<<1],n,h[maxn<<1],K;
bool vis[maxn];
ll num;
void prime(int n){
    e1=0;for(int i=1;i<=100000;i++) vis[i]=0;
    for(int i=2;i<=100000;i++){
        if(!vis[i]) p[++e1]=i,sum[e1]=(sum[e1-1]+1)%mod;
        for(int k=1;k<=e1&&p[k]*i<=100000;k++){
            vis[i*p[k]]=1;
            if(i%p[k]==0){
                break;
            }
        }
    }
}
void pre(ll n){
    ee=0;
    for(ll l=1,r;l<=n;l=r+1){
        r=n/(n/l);q[++ee]=n/l;
        if(q[ee]<=sqr) id1[q[ee]]=ee;
        else id2[n/q[ee]]=ee;
        h[ee]=(q[ee]-1)%mod;
    }
    for(int i=1;i<=e1;++i)
    for(int k=1;k<=ee&&1LL*p[i]*p[i]<=q[k];++k){
        int pos=(q[k]/p[i]<=sqr)?id1[q[k]/p[i]]:id2[n/(q[k]/p[i])];
        h[k]=(h[k]-(h[pos]-sum[i-1])%mod+mod)%mod;
    }
}
ll f(ll x,int y){
    return 0;
}
ll f1(ll x,int y){
    return x<=K;
}
int S(ll x,int y){
    if(x<=1||p[y]>x) return 0;
    int pos=(x<=sqr)?id1[x]:id2[n/x];
    ll ans=(h[pos]-sum[y-1]+mod)%mod;
    for(int i=y;i<=e1&&1LL*p[i]*p[i]<=x;++i){
        ll p1=p[i],p2=1LL*p[i]*p[i];
        for(int e=1;p2<=x;++e,p1=p2,p2*=p[i]){
            (ans+=(1LL*S(x/p1,i+1)*f(p[i],e)%mod+f(p[i],e+1))%mod)%=mod;
        }
    }
    return ans;
}
ll S2(ll x,int y){
    if(x<=1||p[y]>x) return 0;
    int pos=(x<=sqr)?id1[x]:id2[n/x];
    ll ans=(h[pos]-sum[y-1]+mod)%mod;
    if(K<p[y]) ans=0;
    else if(K>=p[y]&&K<=x){
        ans=(num-sum[y-1]+mod)%mod;
    }
    //cout<<ans<<endl;
    for(int i=y;i<=e1&&1LL*p[i]*p[i]<=x;++i){
        ll p1=p[i],p2=1LL*p[i]*p[i];
        for(int e=1;p2<=x;++e,p1=p2,p2*=p[i]){
            (ans+=(1LL*S2(x/p1,i+1)*f1(p[i],e)%mod+f1(p[i],e+1))%mod)%=mod;
        }
    }
    return ans;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
   // cin.tie(0);ios_base::sync_with_stdio(false);
    int t=read();
    while(t--){
        n=read(),K=read();
        sqr=(int)sqrt(K+0.5);
        prime(100000);pre(K);
        //cout<<p[3]<<"qq"<<e1<<endl;
        num=h[(K<=sqr)?id1[K]:id2[K/K]];
        //cout<<((K<=sqr)?id1[K]:id2[n/K])<<endl;
        sqr=(int)sqrt(n+0.5);
        pre(n);
        if(n==1||K==1){
            printf("1\n");continue;
        }
        printf("%lld\n",(S2(n,1)+1)%mod);
    }
    return 0;
}