#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],w[maxn];
const int mod=998244353;
int dp[3007][3007];
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(1LL*ans*a)%mod;
        }
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int add(int a,int b){
    return (a+b)%mod;
}
int dec(int a,int b){
    return (a-b+mod)%mod;
}
int mul(int a,int b){
    return (1LL*a*b)%mod;
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) w[i]=read();
    int sum=0,sum1=0,sum0=0;
    for(int i=1;i<=n;i++){
        sum=add(sum,w[i]);
        if(a[i]) sum1=add(sum1,w[i]);
        else sum0=add(sum0,w[i]);
    }
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int k=0;k<=i;k++){
            if(sum0<(i-k)) continue;
            dp[i][k]=add(dp[i][k],mul(dp[i-1][k],mul(sum0-(i-1-k),pown(sum+k-(i-1-k),mod-2))));
            if(k) dp[i][k]=add(dp[i][k],mul(dp[i-1][k-1],mul(sum1+k-1,pown(sum+k-1-(i-k),mod-2))));
        }
    }
    int p1=0,p0=0;
    for(int i=0;i<=m;i++){
        p1=add(p1,mul(dp[m][i],add(sum1,i)));
        p0=add(p0,mul(dp[m][i],dec(sum0,m-i)));
    }
    for(int i=1;i<=n;i++){
        if(a[i]) printf("%d\n",mul(mul(w[i],pown(sum1,mod-2)),p1));
        else printf("%d\n",mul(mul(w[i],pown(sum0,mod-2)),p0));
    }
    return 0;
}