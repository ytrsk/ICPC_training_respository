#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const ll inf=0x3f3f3f3f;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=1e9+7;
vector<int> g[maxn];
int add(int x,int y){
    x+=y;
    if(x>=mod) x-=mod;return x;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
int dec(int x,int y){
    x-=y;if(x<0) x+=mod;
    return x;
}
int dp[maxn][2];
void dfs(int u,int fa){
    dp[u][0]=1;dp[u][1]=1;
    int tot=1;
    int sz=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v^fa){
            dfs(v,u);sz++;
            dp[u][1]=add(dp[u][1],mul(2,dp[v][1]));
            tot=mul(tot,dp[v][1]+1);
            dp[u][1]=dec(dp[u][1],dp[v][1]);
        }
    }
    if(sz) dp[u][1]=dec(dp[u][1],1),dp[u][1]=add(dp[u][1],tot);
}
int main(){
    int n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);g[v].push_back(u);
    }
    dfs(1,0);cout<<add(dp[1][0],dp[1][1]);
    return 0;
}