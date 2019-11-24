#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
unordered_map<string,int> num[maxn];
string s[maxn];
vector<pii> g[maxn];
int e1,n,head[maxn],to[maxn<<1],nex[maxn<<1],son[maxn],sz[maxn],a[maxn],d[maxn],ans[maxn];
void dfs1(int u,int fa){
    son[u]=0;sz[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;d[v]=d[u]+1;
        dfs1(v,u);sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void add(int u){
    num[d[u]][s[u]]++;
}
void del(int u){
    num[d[u]].clear();
}
void push(int u,int fa){
    add(u);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=fa){
            push(v,u);
        }
    }
}
void pop(int u,int fa){
    del(u);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=fa){
            pop(v,u);
        }
    }
}
void dfs2(int u,int fa,int kp){
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==son[u]||v==fa) continue;
        dfs2(v,u,0);
    }
    if(son[u]) dfs2(son[u],u,1);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==son[u]||v==fa) continue;
        push(v,u);
    }
    add(u);
    for(int i=0;i<g[u].size();i++){
        ans[g[u][i].second]=num[g[u][i].first].size();
    }
    if(!kp) pop(u,fa);
}
void init(){
    e1=0;for(int i=1;i<=n;i++) head[i]=0;
}
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    cin>>n;int rt=0;
    for(int i=1;i<=n;i++){
        int x;cin>>s[i]>>x;
        addedge(x?x:n+1,i);
       // addedge();
    }
    dfs1(n+1,0);
    int m;cin>>m;
    for(int i=1;i<=m;i++){
        int u,x;cin>>u>>x;
        g[u].push_back(mp(d[u]+x,i));
    }
    dfs2(n+1,0,0);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}
