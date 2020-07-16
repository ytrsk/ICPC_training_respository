#include <bits/stdc++.h>
using namespace std;
const int maxn=100007;
typedef long long ll;
vector<int> g[maxn];
int n,cl,dfn[maxn],low[maxn];;
int e1,head[maxn<<1],to[maxn<<2],nex[maxn<<2];
int dcnt=0;
inline void Addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
inline void Add(int u,int v){
    Addedge(u,v);Addedge(v,u);
}
int S[maxn],Top;
void tarjan(int u,int fa){
    dfn[u]=low[u]=++cl;S[++Top]=u;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                dcnt++;int x;
                Add(n+dcnt,u);
                do{x=S[Top--],Add(n+dcnt,x);} while(x!=v);
            }
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);
    }
}
void init(){
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=0;
    dcnt=cl=e1=Top=0;
    for(int i=1;i<=2*n;i++) head[i]=0;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int sz[maxn<<1],tot,vis[maxn<<1];
ll ans,sz1[maxn<<1];
void Dfs(int u,int fa){
    vis[u]=1;
    sz[u]=(u<=n);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        Dfs(v,u);sz[u]+=sz[v];sz1[u]+=1LL*sz[v]*sz[v];
    }
}
void dfs(int u,int fa){
    int now=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa){
            dfs(v,u);
            if(u>n){
                ans+=1LL*now*sz[v]*2;//儿子，儿子
                ans+=1LL*(tot-sz[fa])*sz[v]*2;//父亲和兄弟，儿子
                ans+=1LL*(sz[u]-sz[v])*(tot-sz[u])*2;//兄弟，父亲
                ans+=1LL*(sz[u]-sz[v])*(sz[u]-sz[v])-sz1[u]+1LL*sz[v]*sz[v];//兄弟，兄弟
                now+=sz[v];
            }
            else{
                ans+=1LL*now*sz[v]*2;
                now+=sz[v];
            }
        }
    }
}
int main(){
	n=read();init();
    int m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        g[u].push_back(v);g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            Dfs(i,0);tot=sz[i];dfs(i,0);
        }
    }
    cout<<ans;
    return 0;
}
