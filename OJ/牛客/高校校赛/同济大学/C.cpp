#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int dp[1007][1007][2];
int p[maxn],t[maxn];
int main(){
    int n=read();
    rep(i,1,n) p[i]=read();
    rep(i,1,n) t[i]=read();
    memset(dp,0x3f,sizeof(dp));
    rep(i,1,n){
        if(t[i]==0) dp[i][i][0]=dp[i][i][1]=0;
    }
    dep(i,n,1){
        rep(k,i,n){
            int x;
            if(i){
                x=min(dp[i][k][0]+p[i]-p[i-1],dp[i][k][1]+p[k]-p[i-1]);
                if(x<=t[i-1]) dp[i-1][k][0]=min(dp[i-1][k][0],x);
            }
            if(k+1<=n){
                x=min(dp[i][k][0]+p[k+1]-p[i],dp[i][k][1]+p[k+1]-p[k]);
                if(x<=t[k+1]) dp[i][k+1][1]=min(dp[i][k+1][1],x);
            }
        }
    }
    int x=min(dp[1][n][0],dp[1][n][1]);
    if(x==inf) printf("-1");
    else printf("%d",x);
    return 0;
}