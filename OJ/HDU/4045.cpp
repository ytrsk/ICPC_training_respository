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
int dp[maxn][maxn],dp2[maxn][maxn],sum[maxn][maxn],f[maxn][maxn];
int main(){
    fac[0]=inv[0]=1;
    int N=1000;
    for(int i=1;i<=N;i++) fac[i]=1LL*fac[i-1]*i%mod;
    inv[N]=pown(fac[N],mod-2);
    for(int i=N-1;i;i--) inv[i]=1LL*inv[i+1]*(i+1)%mod;
    dp[0][0]=f[0][0]=1;
    for(int i=1;i<=N;i++){
        for(int k=1;k<=N;k++){
            dp[i][k]=(dp[i-1][k-1]+mul(k,dp[i-1][k]))%mod;
            f[i][k]=(f[i][k-1]+dp[i][k])%mod;
        }
    }
    int n,r,K,m;
    while(scanf("%d%d%d%d",&n,&r,&K,&m)==4){
        cout<<mul(C(n-(r-1)*(K-1),r),f[r][m])<<"\n";
    }
    return 0;
}