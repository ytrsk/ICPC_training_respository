#pragma GCC optimize("3")
#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=1e6+7;
const int mod=1e9+7;
const int inf=(1LL<<29);
int p[maxn],ee,e1;
int id1[maxn],id2[maxn],sqr;
int sum[maxn];
ll q[maxn],n;
int g[maxn],h[maxn];
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
inline void pre(){
    for(ll l=1,r;l<=n;l=r+1){
        r=n/(n/l);q[++ee]=n/l;
        if(q[ee]<=sqr) id1[q[ee]]=ee;
        else id2[n/q[ee]]=ee;
        g[ee]=q[ee]-1;
        if(q[ee]&1) h[ee]=(q[ee]+2)%mod*((q[ee]-1)/2%mod)%mod;
        else h[ee]=(q[ee]+2)/2%mod*((q[ee]-1)%mod)%mod;
    }
    for(register int i=1;i<=e1;++i)
    for(register int k=1;k<=ee&&1LL*p[i]*p[i]<=q[k];++k){
        int pos=(q[k]/p[i]<=sqr)?id1[q[k]/p[i]]:id2[n/(q[k]/p[i])];
        g[k]=(g[k]-1LL*(g[pos]-(i-1)+mod)%mod+mod)%mod;
        h[k]=(h[k]-1LL*p[i]*(h[pos]-sum[i-1]+mod)%mod+mod)%mod;
    }
   // cout<<h[1]<<" "<<g[1]<<endl;
}
inline int S(ll x,int y){
    if(x<=1||p[y]>x) return 0;
    int pos=(x<=sqr)?id1[x]:id2[n/x];
    int ans=(0LL+g[pos]+h[pos]-(sum[y-1]+y-1)%mod+mod)%mod;
    for(int i=y;i<=e1&&1LL*p[i]*p[i]<=x;++i){
        ll p1=p[i],p2=1LL*p[i]*p[i];
        for(int e=1;p2<=x;++e,p1=p2,p2*=p[i]){
            (ans+=(1LL*S(x/p1,i+1)*(p1+1)%mod+(p2+1))%mod)%=mod;
        }
    }
    return ans;
}
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
   // cin.tie(0);ios_base::sync_with_stdio(false);
    prime(1e6);
    int t=read();
    while(t--){
        n=read();ee=0;sqr=(int)sqrt(n+0.5);
        pre();
        printf("%d\n",(S(n,1)+1)%mod);
    }
    return 0;
}
