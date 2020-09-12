#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
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
ll a[maxn],dp[maxn];
int b[maxn],d[maxn];
int vis[maxn];
vector<int> g[maxn],G[maxn],gg;
void dfs(int u,int fa){
    dp[u]=a[u];
    for(auto v:g[u]){
        dfs(v,u);
        if(dp[v]<0){
            G[u].push_back(v);d[v]++;
        }
        else{
            G[v].push_back(u);d[u]++;
        }
        dp[u]+=max(dp[v],0LL);
    }
}
int main(){
    int n=read();
    rep(i,1,n) a[i]=read(),g[i].clear(),d[i]=0,G[i].clear();
    rep(i,1,n) b[i]=read();
    rep(i,1,n){
        if(b[i]>0) g[b[i]].push_back(i);
    }
    rep(i,1,n){
        if(b[i]==-1) dfs(i,0);
    }
    queue<int> q;
    rep(i,1,n){
        if(d[i]==0) q.push(i);
    }
    ll ans=0;
    gg.clear();
    while(!q.empty()){
        int u=q.front();q.pop();gg.push_back(u);
        ans+=a[u];
        if(b[u]!=-1) a[b[u]]+=a[u];
        for(auto v:G[u]){
            d[v]--;
            if(d[v]==0) q.push(v);
        }
    }
    printf("%lld\n",ans);
    for(auto v:gg) printf("%d ",v);
    return 0;
}