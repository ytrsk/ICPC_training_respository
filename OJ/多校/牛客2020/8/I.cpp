#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=800007;
typedef long long ll;
int n,cl,dfn[maxn],low[maxn];
int head[maxn],to[maxn<<1],nex[maxn<<1],e1;
int bans=0,bcc[maxn],bcnt,br[maxn<<1],vis[maxn];
inline void tarjan(int u,int fa){
    dfn[u]=low[u]=++cl;
   // cout<<u<<endl;
    for(register int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!dfn[v]){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
      //     cout<<low[v]<<" "<<u<<" "<<v<<" "<<dfn[u]<<endl;
            if(low[v]>dfn[u]){
                bans++;
                br[i]=br[((i-1)^1)+1]=1;
            }
        }
        else if(!fa||i-1!=((fa-1)^1)) low[u]=min(low[u],dfn[v]);
        //能够处理重边
    }
}
int sz[maxn];
//边双连通
inline void dfs(int u){
    dfn[u]=1;
    bcc[u]=bcnt;sz[bcnt]++;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(br[i]) continue;
        if(!dfn[v]) dfs(v);
    }
}
vector<int> g[maxn];
int you[maxn];
inline void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
inline void init(){
    for(register int i=1;i<=n;++i) head[i]=dfn[i]=0;
    for(int i=1;i<=e1;i++) br[i]=0;
    for(int i=1;i<=bcnt;i++) g[i].clear(),vis[i]=sz[i]=0,you[i]=0;
    cl=e1=bans=bcnt=0;
}
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
map<int,int> aa;
int ans=0;
int DFS(int u,int fa){
    vis[u]=1;
    int now=0;
    for(auto v:g[u]){
        if(v==fa) continue;
        now+=DFS(v,u);
    }
    if(sz[u]>=2||you[u]) {ans+=sz[u];return 1;}
    else{
        if(now){
            ans++;return 1;
        }
        else{
            if(fa) ans++;return 0;
        }
    }
}
int Y[maxn];
int main(){
    int T=read(),cnt=0;
    while(T--){
        n=0;ans=0;
        int m=read();
        aa.clear();
        for(int i=1;i<=m;++i){
            int u=read(),v=read();//scanf("%d%d",&u,&v);
            if(!aa.count(u)) aa[u]=++n;
            if(!aa.count(v)) aa[v]=++n;
            u=aa[u],v=aa[v];
            if(u==v) Y[u]=1;
            else addedge(u,v),addedge(v,u);
        }
        bans=0;
        for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i,0);
        for(int i=1;i<=n;++i) dfn[i]=0;
        for(int i=1;i<=n;++i){
            if(!dfn[i]){
                ++bcnt;dfs(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(sz[bcc[i]]==1&&Y[i]==1) you[bcc[i]]=1;
        }
        for(int i=1;i<=n;i++){
            for(int k=head[i];k;k=nex[k]){
                int v=to[k];
                if(i<v&&bcc[i]!=bcc[v]){
                    g[bcc[i]].push_back(bcc[v]);
                    g[bcc[v]].push_back(bcc[i]);
                }
            }
        }
        for(int i=1;i<=bcnt;i++)
        if(!vis[i]) DFS(i,0);
        printf("Case #%d: %d\n",++cnt,ans);
        for(int i=1;i<=n;i++) Y[i]=0;
        init();
    }
    return 0;
}