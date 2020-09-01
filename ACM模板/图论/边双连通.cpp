#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
const int maxn=800007;
typedef long long ll;
int n,cl,dfn[maxn],low[maxn];
int head[maxn],to[maxn<<1],nex[maxn<<1],e1;
int bans=0,bcc[maxn],bcnt,br[maxn<<1];
inline void tarjan(int u,int fa){
    dfn[u]=low[u]=++cl;
    for(register int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!dfn[v]){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                bans++;
                br[i]=br[((i-1)^1)+1]=1;
            }
        }
        else if(!fa||i-1!=((fa-1)^1)) low[u]=min(low[u],dfn[v]);
        //能够处理重边
    }
}
//边双连通
inline void dfs(int u){
    dfn[u]=1;
    bcc[u]=bcnt;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(br[i]) continue;
        if(!dfn[v]) dfs(v);
    }
}
vector<int> g[maxn];
inline void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
inline void init(){
    for(register int i=1;i<=n;++i) head[i]=dfn[i]=0;
    for(int i=1;i<=e1;i++) br[i]=0;
    for(int i=1;i<=bcnt;i++) g[i].clear();
    cl=e1=bans=bcnt=0;
}
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int u,v;scanf("%d%d",&u,&v);
        addedge(u,v);addedge(v,u);
    }
    bans=0;
    tarjan(1,0);
    for(int i=1;i<=n;++i) dfn[i]=0;
    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            ++bcnt;dfs(i);
        }
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
    init();
    return 0;
}
