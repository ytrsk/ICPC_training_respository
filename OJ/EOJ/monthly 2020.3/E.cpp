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
const int mod=1e9+7;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
void del(int x,int y){
    x-=y;
    if(x<0) x+=mod;
}
int fac[maxn],inv[maxn];
int C(int a,int b){
    if(a<b) return 0;
    return 1LL*fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int a[maxn];
int main(){
    fac[0]=inv[0]=1;
    int N=1000000;
    for(int i=1;i<=N;i++) fac[i]=1LL*fac[i-1]*i%mod;
    inv[N]=pown(fac[N],mod-2);
    for(int i=N-1;i;i--) inv[i]=1LL*inv[i+1]*(i+1)%mod;
    int t=read();
    while(t--){
        int n=read(),m=read();
        for(int i=1;i<=n;i++) a[i]=read();
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            add(ans,mul(a[i],C(i-1,m-1)));
        }
        printf("%d\n",ans);
    }
    return 0;
}