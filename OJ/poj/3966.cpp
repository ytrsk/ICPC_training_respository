#include <stdio.h>
#include <algorithm>
#include <string.h>
#pragma comment(linker, "/STACK:302400000,302400000")
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int cl,n,dfn[maxn],f[maxn],d[maxn],sz[maxn],id[maxn];
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],tp[maxn];
int tag[maxn<<2],a[maxn],son[maxn];
void pushdown(int o){
    if(tag[o]){
        tag[o<<1]+=tag[o];
        tag[o<<1|1]+=tag[o];
        tag[o]=0;
    }
}
void build(int o,int l,int r){
    if(l==r){
        tag[o]=a[id[l]];return;
    }
    tag[o]=0;
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
}
void update(int o,int l,int r,int ql,int qr,int x){
    if(l==ql&&r==qr){
        tag[o]+=x;
        return;
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m,x),update(o<<1|1,m+1,r,m+1,qr,x);
    else if(ql<=m) update(o<<1,l,m,ql,qr,x);
    else update(o<<1|1,m+1,r,ql,qr,x);
}
int query(int o,int l,int r,int x){
    if(l==r) return tag[o];
    pushdown(o);
    int m=(l+r)>>1;
    if(x<=m) return query(o<<1,l,m,x);
    else return query(o<<1|1,m+1,r,x);
}
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
void dfs1(int u,int fa){
    f[u]=fa;
    sz[u]=1;son[u]=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        d[v]=d[u]+1;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]){
            son[u]=v;
        }
    }
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
void update(int x,int y,int w){
    int fx=tp[x],fy=tp[y];
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            update(1,1,n,dfn[fx],dfn[x],w);
            x=f[fx],fx=tp[x];
        }
        else{
            update(1,1,n,dfn[fy],dfn[y],w);
            y=f[fy],fy=tp[y];
        }
    }
    if(dfn[x]<=dfn[y]) update(1,1,n,dfn[x],dfn[y],w);
    else update(1,1,n,dfn[y],dfn[x],w);
}

int main(){
    int m,p;
    while(scanf("%d%d%d",&n,&m,&p)==3){
        for(int i=1;i<=n;i++) a[i]=read();
        cl=0;e1=0;for(int i=1;i<=n;i++) head[i]=0;
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            addedge(u,v);addedge(v,u);
        }
        dfs1(1,0);dfs2(1,1);build(1,1,n);
        for(int i=1;i<=p;i++){
            char s[5];scanf("%s",s+1);
            if(s[1]=='I'){
                int x=read(),y=read(),w=read();
                update(x,y,w);
            }
            else if(s[1]=='D'){
                int x=read(),y=read(),w=read();
                update(x,y,-w);
            }
            else{
                int x=read();
                printf("%d\n",query(1,1,n,dfn[x]));
            }
        }
    }
    return 0;
}
