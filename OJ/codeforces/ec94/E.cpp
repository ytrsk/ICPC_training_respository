#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=5007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int dp[maxn][maxn],a[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    memset(dp,127/3,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++) dp[0][i]=i;
    for(int i=1;i<=n;i++){
        for(int k=0;k<=n;k++){
            if(k<a[i]){
                dp[i][k]=min(dp[i][k],dp[i-1][k]+1);
            }
            else dp[i][a[i]]=min(dp[i][a[i]],dp[i-1][k]);
        }
        int x=inf;
        for(int k=0;k<=n;k++){
            dp[i][k]=min(dp[i][k],x+k);
            x=min(x,dp[i][k]-k);
        }
    }
    int ans=inf;
    for(int i=0;i<=n;i++)
    ans=min(ans,dp[n][i]);
    cout<<ans;
    return 0;
}