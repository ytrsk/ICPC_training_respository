#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll pown(ll a,ll b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*a*ans)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int inv[1000007],pre[1000007];
int main(){
    pre[0]=1;
    for(int i=1;i<=1000003;i++) pre[i]=(1LL*pre[i-1]*i)%mod;
    inv[0]=inv[1]=1;
    for(int i=2;i<=1000003;i++){
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
    }
    int t=read();
    while(t--){
        ll n=read(),K=read();
        int sum=1,now=1;
        for(int i=2;i<=K;i++){
            now=1LL*now*inv[i-1]%mod*(n+i-2)%mod;
            sum=(sum+now)%mod;
        }
        ll ans=pown(K,n);
        ans=(ans-(2LL*sum-K+mod)%mod+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}