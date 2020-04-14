#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll a[maxn],b[maxn];
ll dp[maxn],Sum;
int p[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) b[i]=read(),Sum+=b[i];
    ll l=-3000000000LL,r=3000000000LL,ans=-inf;
    while(l<=r){
        ll mid=(l+r)>>1;
        memset(dp,0x3f,sizeof(dp));dp[0]=0;
        for(int i=1;i<=n+1;i++) a[i]=b[i]+mid;
        dp[1]=a[1];p[1]=1;
        for(int i=2;i<=n+1;i++){
            if(dp[i-1]==dp[i-2]) p[i]=min(p[i-1],p[i-2])+1;
            else if(dp[i-1]<dp[i-2]) p[i]=p[i-1]+1;
            else  p[i]=p[i-2]+1;
            dp[i]=min(dp[i-1],dp[i-2])+a[i];
        }
        if(p[n+1]<=n-(n/2)+1){
            r=mid-1;
            ll now=Sum-(dp[n+1]-(n-n/2+1)*mid);
            ans=now;
        }
        else if(p[n+1]>=n-(n/2)+1){
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}