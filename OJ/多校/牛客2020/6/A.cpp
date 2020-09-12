#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
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
int mul(int a,int b){
    return 1LL*a*b%mod;
}
int add(int a,int b){
    return (a+b)%mod;
}
int inv(int x){
    return pown(x,mod-2);
}
int dp[maxn],a[maxn],sum[maxn],vis[maxn];
int main(){
    int n=read(),m=read();
    sum[1]=dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=mul(add(1,mul(inv(i),sum[i-1])),mul(i,inv(i-1)));
    //    cout<<dp[i]<<endl;
        sum[i]=add(sum[i-1],dp[i]);
    }
    while(m--){
        int ans=0;
        for(int i=1;i<=n;i++) a[i]=read(),vis[i]=0;
        for(int i=1;i<=n;i++){
            int x=i,cnt=0;
            while(!vis[x]){
                vis[x]=1;
                cnt++;
                x=a[x];
            }
            ans=add(ans,mul(cnt,dp[cnt]));
        }
        printf("%d\n",ans);
    }
    return 0;
}