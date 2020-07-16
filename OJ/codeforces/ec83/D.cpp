#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=998244353;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int inv[2000007],fac[2000007];
int C(int a,int b){
    if(a<b) return 0;
    return 1LL*fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int a[maxn];
int main(){
    int n=read(),m=read();
    fac[0]=inv[0]=1;
    for(int i=1;i<=1000000;i++) fac[i]=1LL*fac[i-1]*i%mod;
    for(int i=1;i<=1000000;i++) inv[i]=pown(fac[i],mod-2);
    int you=0,ans=0;
    for(int i=0;i<=n;i++){
        if(i>=2&&n>=i+1) you=(you+1LL*inv[n-i-1]*inv[i-2])%mod;
    }
    int now=0;
    for(int i=2;i<=m;i++){
        if(i>=2&&i-n+1>=0) ans=(ans+1LL*(i-1)*fac[i-2]%mod*inv[i-n+1])%mod;
  //      ans=(ans+mod-C(i-1,n-1))%mod;
    }
    cout<<1LL*ans*you%mod;
    return 0;
}