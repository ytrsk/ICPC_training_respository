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
struct edge{
    int v,d;
};
vector<edge> g[maxn];
ll dp[maxn];
int n,lim;
void init(){
    for(int i=1;i<=n;i++) g[i].clear();
}
int cmp(ll x,ll y){
    return x>y;
}
void dfs(int u,int fa){
    vector<ll> G;
    dp[u]=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(v==fa) continue;
        dfs(v,u);
        G.push_back(dp[v]+g[u][i].d);
    }
    sort(G.begin(),G.end(),cmp);
    int Lim=min(lim-1,(int)G.size());
    for(int i=0;i<Lim;i++){
        dp[u]+=max(G[i],0LL);
    }
}
int pos[maxn];
ll ans=0;
struct node{
    int u;
    ll d;
    bool operator < (node a) const{
        return d>a.d;
    }
};
void DFS(int u,int fa,ll x){
    vector<node> G;
    G.push_back(node{0,x});
    ll now_ans=0,tmp=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(v==fa) continue;
        G.push_back(node{v,dp[v]+g[u][i].d});
    }
    sort(G.begin(),G.end());
    int Lim=min(lim-1,(int)G.size());
    for(int i=0;i<G.size();i++){
        pos[G[i].u]=i;
        now_ans+=max(G[i].d,0LL);
    }
    ans=max(ans,now_ans);
    for(int i=0;i<Lim;i++){
        tmp+=max(G[i].d,0LL);
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(v==fa) continue;
        ll now_tmp=tmp;
        if(pos[v]<Lim){
            now_tmp-=max(dp[v]+g[u][i].d,0LL);
            if(Lim<G.size())
            now_tmp+=max(G[Lim].d,0LL);
        }
        DFS(v,u,now_tmp+g[u][i].d);
    }
}
int main(){
    int t=read();
    while(t--){
        n=read();lim=read();init();
        ans=0;
        for(int i=1;i<n;i++){
            int u=read(),v=read(),d=read();
            g[u].push_back(edge{v,d});
            g[v].push_back(edge{u,d});
        }
        if(lim==0){
            printf("0\n");continue;
        }
        dfs(1,0);
        DFS(1,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}