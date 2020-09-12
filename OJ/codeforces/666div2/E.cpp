#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define ll __int128
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
const int maxn=100007;
const ll inf=0x3f3f3f3f3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll a[1000007],s[1000007],sum[1000007],dp[1000007],pre[1000007];
int main(){
    int n=read();ll r1=read(),r2=read(),r3=read(),d=read();
    ll tot=(n-1)*d;
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        s[i]=2*d+min(r1*(a[i]+1),r2)+r1-r1*a[i]-r3;
        tot+=r1*a[i]+r3;
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+s[i];
    }
    pre[n]=0;
    for(int i=n-1;i>=1;i--) pre[i]=pre[i+1]+min(r1*(a[i]+1),r2)+r1+d-r1*a[i]-r3;
    ll mx=inf,ans=pre[1];
    for(int i=1;i<=n;i++){
        dp[i]=min(dp[i-1],mx-2*d+sum[i]);
        mx=min(mx,dp[i-1]-sum[i-1]);
        ans=min(ans,dp[i]+pre[i+1]);
    }
    cout<<(long long)(tot+ans);
    return 0;
}