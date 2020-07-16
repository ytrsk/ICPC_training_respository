#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1007;
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
void add(ll &x,ll y){
    x+=y;
}
ll mul(ll x,ll y){
    return 1LL*x*y;
}
ll fac[maxn],inv[maxn];
ll dp[maxn][maxn],f[maxn][maxn];
int main(){
    fac[0]=inv[0]=1;
    int N=1000;
    for(int i=1;i<=N;i++) fac[i]=1LL*fac[i-1]*i;
    inv[N]=pown(fac[N],mod-2);
    for(int i=N-1;i;i--) inv[i]=1LL*inv[i+1]*(i+1);
    dp[0][0]=1;
    for(int i=1;i<=20;i++){
        for(int k=1;k<=20;k++){
            dp[i][k]=(dp[i-1][k-1]+mul(i-1,dp[i-1][k]));
            f[i][k]=f[i][k-1]+mul(dp[i-1][k],i-1);
        }
    }
    int t=read();
    while(t--){
        int a=read(),b=read();
        printf("%.4f\n",1.0*f[a][b]/fac[a]);
    }
    return 0;
}