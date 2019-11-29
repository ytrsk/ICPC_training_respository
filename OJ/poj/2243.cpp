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
int a[maxn],son[maxn],tag[maxn<<2];
struct node{
    int num,l,r;
}nd[maxn<<2];
node merge(node a,node b){
    if(a.num==0) return b;
    if(b.num==0) return a;
    node New;
    New.num=a.num+b.num-(a.r==b.l);
    New.l=a.l;New.r=b.r;
    return New;
}
void pushup(int o){
    nd[o]=merge(nd[o<<1],nd[o<<1|1]);
}
void col(int o,int c){
    tag[o]=c;nd[o].num=1;nd[o].l=nd[o].r=c;
}
void pushdown(int o){
    if(tag[o]!=-1){
        col(o<<1,tag[o]);
        col(o<<1|1,tag[o]);
        tag[o]=-1;
    }
}
void build(int o,int l,int r){
    if(l==r){
        nd[o].num=1;
        nd[o].l=nd[o].r=a[id[l]];return;
    }
    tag[o]=-1;
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    pushup(o);
}
void update(int o,int l,int r,int ql,int qr,int x){
    if(l==ql&&r==qr){
        col(o,x);return;
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m,x),update(o<<1|1,m+1,r,m+1,qr,x);
    else if(ql<=m) update(o<<1,l,m,ql,qr,x);
    else update(o<<1|1,m+1,r,ql,qr,x);
    pushup(o);
}
node query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return nd[o];
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return merge(query(o<<1,l,m,ql,m),query(o<<1|1,m+1,r,m+1,qr));
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
node Query(int x,int y){
    node nowl,nowr;nowl.num=0;nowr.num=0;
    int fx=tp[x],fy=tp[y],ans=-0x3f3f3f3f;
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            node now=query(1,1,n,dfn[fx],dfn[x]);swap(now.l,now.r);
            nowl=merge(nowl,now);
            x=f[fx],fx=tp[x];
        }
        else{
            nowr=merge(query(1,1,n,dfn[fy],dfn[y]),nowr);
            y=f[fy],fy=tp[y];
        }
    }
    if(dfn[x]<=dfn[y]) return merge(merge(nowl,query(1,1,n,dfn[x],dfn[y])),nowr);
    else {
        node now=query(1,1,n,dfn[y],dfn[x]);
        swap(now.l,now.r);
        return merge(merge(nowl,now),nowr);
    }
}
void Update(int x,int y,int c){
    int fx=tp[x],fy=tp[y];
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            update(1,1,n,dfn[fx],dfn[x],c);
            x=f[fx],fx=tp[x];
        }
        else{
            update(1,1,n,dfn[fy],dfn[y],c);
            y=f[fy],fy=tp[y];
        }
    }
    if(dfn[x]<=dfn[y]) update(1,1,n,dfn[x],dfn[y],c);
    else update(1,1,n,dfn[y],dfn[x],c);
}
int main(){
    int q;n=read();q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs1(1,0);dfs2(1,1);build(1,1,n);
    for(int i=1;i<=q;i++){
        char s[11];scanf("%s",s+1);
        if(s[1]=='Q'){
            int x=read(),y=read();
            printf("%d\n",Query(x,y).num);
        }
        else{
            int x=read(),y=read(),c=read();
            Update(x,y,c);
        }
    }
    return 0;
}
