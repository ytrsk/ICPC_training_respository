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
int sz[maxn<<1];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int f[maxn],F[maxn<<1];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void dfs(int u,int fa){
    dfn[u]=1;F[u]=fa;sz[u]=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa) dfs(v,u),sz[u]++;
    }
}
int main(){
    int m,cnt=0,q;
    while(scanf("%d%d%d",&n,&m,&q)==3&&n){
	    init();
        for(int i=1;i<=n;i++) f[i]=i;
        for(int i=1;i<=m;i++){
            int u=read(),v=read();u++;v++;
            f[find(u)]=find(v);
            g[u].push_back(v);g[v].push_back(u);
        }
        printf("Case %d:\n",++cnt);
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
        for(int i=1;i<=n;i++) dfn[i]=0;
        for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i,0);
        for(int i=1;i<=q;i++){
            int u=read(),v=read();u++;v++;
            if(find(u)^find(v)){
                printf("zero\n");
            }
            else if(F[F[u]]==v&&sz[F[u]]>1||F[F[v]]==u&&sz[F[v]]>1||F[u]==F[v]) printf("two or more\n");
            else printf("one\n");
        }
    }
    return 0;
}
