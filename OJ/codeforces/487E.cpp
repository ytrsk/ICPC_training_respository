#include <bits/stdc++.h>
using namespace std;
const int maxn=200007;
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
int S[maxn],Top,a[maxn<<1];
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
multiset<int> s[maxn];
void dfs(int u,int fa){
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa){
            if(u>n) s[u].insert(a[v]);
            dfs(v,u);
        }
    }
    if(u>n) a[u]=*s[u].begin();
}
int f[maxn],sz[maxn],son[maxn],d[maxn],tp[maxn],id[maxn];
void dfs1(int u,int fa){
    f[u]=fa;d[u]=d[fa]+1;
    sz[u]=1;son[u]=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        if(u>n) s[u].insert(a[v]);
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]){
            son[u]=v;
        }
    }
    if(u>n) a[u]=*s[u].begin();
}
void dfs2(int u,int t){
    tp[u]=t;dfn[u]=++cl;id[cl]=u;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=son[u]&&v!=f[u]) dfs2(v,v);
    }
}
int mn[maxn<<2];
void pushup(int o){
    mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void build(int o,int l,int r){
    if(l==r){
        mn[o]=a[id[l]];return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr) return mn[o];
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return min(query(o<<1,l,m,ql,m),query(o<<1|1,m+1,r,m+1,qr));
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr);
}
void modify(int o,int l,int r,int x,int y){
    if(l==r){
        mn[o]=y;return;
    }
    int m=(l+r)>>1;
    if(x<=m) modify(o<<1,l,m,x,y);
    else modify(o<<1|1,m+1,r,x,y);
    pushup(o);
}
int Query(int x,int y){
    int fx=tp[x],fy=tp[y],ans=0x3f3f3f3f;
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            ans=min(ans,query(1,1,n+dcnt,dfn[fx],dfn[x]));
            x=f[fx],fx=tp[x];
        }
        else{
            ans=min(ans,query(1,1,n+dcnt,dfn[fy],dfn[y]));
            y=f[fy],fy=tp[y];
        }
    }
    if(dfn[x]<dfn[y]) ans=min(ans,query(1,1,n+dcnt,dfn[x],dfn[y]));
    else ans=min(ans,query(1,1,n+dcnt,dfn[y],dfn[x]));
    int lca=dfn[x]<dfn[y]?x:y;
    if(lca>n) ans=min(ans,a[f[lca]]);
    return ans;
}
int main(){
    int m,q;
	n=read();init();m=read(),q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        g[u].push_back(v);g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    cl=0;
    dfs1(1,0);dfs2(1,1);build(1,1,n+dcnt);
    for(int i=1;i<=q;i++){
        char ss[5];scanf("%s",ss+1);
        int x=read(),y=read();
        if(ss[1]=='C'){
            modify(1,1,n+dcnt,dfn[x],y);
            if(f[x]){
                s[f[x]].erase(s[f[x]].find(a[x]));
                s[f[x]].insert(y);
                a[f[x]]=*s[f[x]].begin();
                modify(1,1,n+dcnt,dfn[f[x]],a[f[x]]);
            }
            a[x]=y;
        }
        else{
            printf("%d\n",Query(x,y));
        }
    }
    return 0;
}
