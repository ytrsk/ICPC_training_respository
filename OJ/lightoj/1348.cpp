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
void pushup(int o){
    tag[o]=tag[o<<1]+tag[o<<1|1];
}
void build(int o,int l,int r){
    if(l==r){
        tag[o]=a[id[l]];return;
    }
    tag[o]=0;
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    pushup(o);
}
void update(int o,int l,int r,int x,int y){
    if(l==r){
        tag[o]=y;return;
    }
    int m=(l+r)>>1;
    if(x<=m) update(o<<1,l,m,x,y);
    else update(o<<1|1,m+1,r,x,y);
    pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return tag[o];
    }
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return query(o<<1,l,m,ql,m)+query(o<<1|1,m+1,r,m+1,qr);
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr);
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
int Query(int x,int y){
    int fx=tp[x],fy=tp[y],ans=0;
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            ans+=query(1,1,n,dfn[fx],dfn[x]);
            x=f[fx],fx=tp[x];
        }
        else{
            ans+=query(1,1,n,dfn[fy],dfn[y]);
            y=f[fy],fy=tp[y];
        }
    }
    int g=dfn[x]<=dfn[y]?x:y;
    if(dfn[x]<=dfn[y]) ans+=query(1,1,n,dfn[x],dfn[y]);
    else ans+=query(1,1,n,dfn[y],dfn[x]);
    return ans;
}
void init(){
    for(int i=1;i<=n;i++) head[i]=0;e1=cl=0;
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        init();
        for(int i=1;i<n;i++){
            int u=read(),v=read();++u;++v;
            addedge(u,v);addedge(v,u);
        }
        printf("Case %d:\n",++cnt);
        int q=read();
        dfs1(1,0);dfs2(1,1);build(1,1,n);
        for(int i=1;i<=q;i++){
            int opt=read();
            if(opt==0){
                int x=read(),y=read();++x;++y;
                printf("%d\n",Query(x,y));
            }
            else{
                int x=read(),y=read();++x;
                update(1,1,n,dfn[x],y);
            }
        }
    }
    return 0;
}
