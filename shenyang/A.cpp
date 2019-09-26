#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const ll inf=(1LL<<60);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
ll dp[20007];
ll p[1007],c[1007];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        ll mx=0;
        for(int i=1;i<=n;i++){
            p[i]=read();c[i]=read();
            mx=max(mx,c[i]);
        }
        for(int i=0;i<=m+mx;i++) dp[i]=inf;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int k=c[i];k<=m+mx;k++)
                dp[k]=min(dp[k],dp[k-c[i]]+p[i]);
        }
        int pos=-1;ll ans=inf;
        for(int i=m;i<=m+mx;i++){
            if(dp[i]<=ans){
                ans=dp[i];pos=i;
            }
        }
        printf("%lld %d\n",ans,pos);
    }
    return 0;
}
