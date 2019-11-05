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
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],tp[maxn],w[maxn<<1];
int tag[maxn<<2],a[maxn],son[maxn],mx[maxn<<2],mn[maxn<<2];
void pushup(int o){
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
    mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void rev(int o){
    tag[o]^=1;
    mn[o]=-mn[o];mx[o]=-mx[o];
    swap(mx[o],mn[o]);
}
void pushdown(int o){
    if(tag[o]){
        rev(o<<1);
        rev(o<<1|1);
        tag[o]=0;
    }
}
void build(int o,int l,int r){
    if(l==r){
        mx[o]=mn[o]=a[id[l]];return;
    }
    tag[o]=0;
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    pushup(o);
}
void modify(int o,int l,int r,int x,int y){
    if(l==r){
        mx[o]=mn[o]=y;
        return;
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(x<=m) modify(o<<1,l,m,x,y);
    else modify(o<<1|1,m+1,r,x,y);
    pushup(o);
}
void update(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        rev(o);return;
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m),update(o<<1|1,m+1,r,m+1,qr);
    else if(ql<=m) update(o<<1,l,m,ql,qr);
    else update(o<<1|1,m+1,r,ql,qr);
    pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return mx[o];
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return max(query(o<<1,l,m,ql,m),query(o<<1|1,m+1,r,m+1,qr));
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr);
}
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
void dfs1(int u,int fa){
    f[u]=fa;
    sz[u]=1;son[u]=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        d[v]=d[u]+1;
        a[v]=w[i];
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
    int fx=tp[x],fy=tp[y],ans=-0x3f3f3f3f;
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            ans=max(ans,query(1,1,n,dfn[fx],dfn[x]));
            x=f[fx],fx=tp[x];
        }
        else{
            ans=max(ans,query(1,1,n,dfn[fy],dfn[y]));
            y=f[fy],fy=tp[y];
        }
    }
    if(dfn[x]<dfn[y]) ans=max(ans,query(1,1,n,dfn[x]+1,dfn[y]));
    else if(dfn[x]>dfn[y]) ans=max(ans,query(1,1,n,dfn[y]+1,dfn[x]));
    return ans;
}
void Update(int x,int y){
    int fx=tp[x],fy=tp[y];
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            update(1,1,n,dfn[fx],dfn[x]);
            x=f[fx],fx=tp[x];
        }
        else{
            update(1,1,n,dfn[fy],dfn[y]);
            y=f[fy],fy=tp[y];
        }
    }
    if(dfn[x]<dfn[y]) update(1,1,n,dfn[x]+1,dfn[y]);
    else if(dfn[x]>dfn[y]) update(1,1,n,dfn[y]+1,dfn[x]);
}
int U[maxn],V[maxn];
void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    e1=cl=0;
}
int main(){
    int t=read();
    while(t--){
        int q;n=read();init();
        for(int i=1;i<n;i++){
            U[i]=read(),V[i]=read();int w=read();
            addedge(U[i],V[i],w);addedge(V[i],U[i],w);
        }
        dfs1(1,0);dfs2(1,1);build(1,1,n);
        while(1){
            char s[11];scanf("%s",s+1);
            if(s[1]=='Q'){
                int x=read(),y=read();
                printf("%d\n",Query(x,y));
            }
            else if(s[1]=='C'){
                int x=read(),y=read();
                modify(1,1,n,dfn[d[U[x]]<d[V[x]]?V[x]:U[x]],y);
            }
            else if(s[1]=='N'){
                int x=read(),y=read();
                Update(x,y);
            }
            else break;
        }
    }
    return 0;
}
