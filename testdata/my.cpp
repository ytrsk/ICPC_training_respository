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
int ans=0,bcc[maxn],bcnt,br[maxn<<1];
inline void tarjan(int u,int fa){
    dfn[u]=low[u]=++cl;
    for(register int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!dfn[v]){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                ans++;
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
inline void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int E1,Nex[maxn<<1],Head[maxn],To[maxn<<1];
inline void Addedge(int u,int v){
    ++E1;Nex[E1]=Head[u];Head[u]=E1;To[E1]=v;
}
int d[maxn],f[maxn];
inline void init(){
    for(register int i=1;i<=n;++i) head[i]=dfn[i]=0;
    for(int i=1;i<=bcnt;++i) Head[i]=0;
    cl=e1=ans=bcnt=E1=0;
}
inline void Dfs(int u,int fa){
    f[u]=fa;
    for(register int i=Head[u];i;i=Nex[i]){
        int v=To[i];
        if(v==fa) continue;
        d[v]=d[u]+1;Dfs(v,u);
    }
}
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int fa[maxn];
inline int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int U[maxn],V[maxn];
int main(){
    freopen("test.in","r",stdin);
    freopen("my.out","w",stdout);
    int cnt=0,m;
	while(scanf("%d%d",&n,&m)==2&&(n||m)){
        init();
        for(register int i=1;i<=2*m;++i) br[i]=0;
        for(register int i=1;i<=m;++i){
            int u,v;scanf("%d%d",&u,&v);
            addedge(u,v);addedge(v,u);
            U[i]=u;V[i]=v;
        }
        ans=0;
        tarjan(1,0);
        for(register int i=1;i<=n;++i) dfn[i]=0;
        for(register int i=1;i<=n;++i){
            if(!dfn[i]){
                ++bcnt;dfs(i);
            }
        }
        for(register int i=1;i<=m;++i)
        if(bcc[U[i]]!=bcc[V[i]]){
            Addedge(bcc[U[i]],bcc[V[i]]);
            Addedge(bcc[V[i]],bcc[U[i]]);
        }
        Dfs(1,0);
        for(register int i=1;i<=bcnt;++i) fa[i]=i;
        int t=read();
        printf("Case %d:\n",++cnt);
        while(t--){
            int u=read(),v=read();
            u=find(bcc[u]);v=find(bcc[v]);
            int cc=0;
            while(u!=v){
                if(d[u]<d[v]) swap(u,v);
                fa[u]=find(f[u]);
                u=fa[u];
                ans--;
            }
            printf("%d\n",ans);
        }
        printf("\n");
	}
    return 0;
}
