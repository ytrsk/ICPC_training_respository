#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct matrix{
    ll a[4];
    matrix(){
        memset(a,-0x3f,sizeof(a));
    }
    inline matrix operator * (matrix x){
        matrix New;
        New.a[0]=max(a[0],a[1]+x.a[0]);
        New.a[1]=a[1]+x.a[1];
        New.a[2]=max(a[2],max(a[3]+x.a[0],x.a[2]));
        New.a[3]=max(x.a[3],a[3]+x.a[1]);
        return New;
    }
}g[maxn<<2];
int cl,n,dfn[maxn],f[maxn],d[maxn],sz[maxn],id[maxn];
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],tp[maxn];
int son[maxn],bt[maxn];
ll G[maxn][3],F[maxn][3],val[maxn];
inline void pushup(int o){
    g[o]=g[o<<1|1]*g[o<<1];
}
priority_queue<ll> aa[maxn],bb[maxn];
inline void build(int o,int l,int r){
    if(l==r){
        g[o].a[0]=0;g[o].a[1]=g[o].a[3]=G[id[l]][1];
        g[o].a[2]=G[id[l]][0];
        return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    pushup(o);
}
inline void modify(int o,int l,int r,int x){
    if(l==r){
        g[o].a[0]=0;g[o].a[1]=g[o].a[3]=G[id[l]][1];
        g[o].a[2]=G[id[l]][0];
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) modify(o<<1,l,m,x);
    else modify(o<<1|1,m+1,r,x);
    pushup(o);
}
inline matrix query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return g[o];
    }
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return query(o<<1|1,m+1,r,m+1,qr)*query(o<<1,l,m,ql,m);
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr);
}
inline void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
inline void del(int x,ll y){
    bb[x].push(y);
}
inline void ins(int x,ll y){aa[x].push(y);}
inline ll Q(int x){
    while(!aa[x].empty()&&!bb[x].empty()&&aa[x].top()==bb[x].top()) aa[x].pop(),bb[x].pop();
    return aa[x].empty()?-inf:aa[x].top();
}
inline void dfs1(int u,int fa){
    f[u]=fa;
    sz[u]=1;son[u]=0;
    F[u][1]=val[u];F[u][0]=-inf;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        d[v]=d[u]+1;
        dfs1(v,u);
        ins(u,max(F[v][0],F[v][1]));
        F[u][0]=max(F[u][0],max(F[v][1],F[v][0]));
        F[u][1]+=max(F[v][1],0LL);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]){
            son[u]=v;
        }
    }
}
inline void dfs2(int u,int t){
    tp[u]=t;dfn[u]=++cl;id[cl]=u;
    G[u][0]=F[u][0];G[u][1]=F[u][1];
    if(!son[u]){
        bt[u]=u;return;
    }
    G[u][1]-=max(F[son[u]][1],0LL);
    ll x=max(F[son[u]][0],F[son[u]][1]);
    del(u,x);
    G[u][0]=Q(u);
    dfs2(son[u],t);bt[u]=bt[son[u]];
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=son[u]&&v!=f[u]) dfs2(v,v);
    }
}
inline matrix ask(int x){
    return query(1,1,n,dfn[x],dfn[bt[x]]);
}
inline void Update(int x,ll y){
    G[x][1]+=y-val[x];val[x]=y;
    while(x){
        matrix last=ask(tp[x]);
        modify(1,1,n,dfn[x]);
        matrix now=ask(tp[x]);
        x=f[tp[x]];
        if(!x) break;
        G[x][1]+=max(0LL,now.a[3])-max(0LL,last.a[3]);
        del(x,max(last.a[2],last.a[3]));
        ins(x,max(now.a[2],now.a[3]));
        G[x][0]=Q(x);
    }
}
void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    e1=cl=0;
}
int main(){
    n=read();int m=read();init();
    for(int i=1;i<=n;i++) val[i]=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs1(1,0);dfs2(1,1);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        char s[10];scanf("%s",s+1);
        if(s[1]=='Q'){
            int x=read();
            matrix now=ask(x);
            printf("%lld\n",max(max(0LL,now.a[2]),now.a[3]));continue;
        }
        int x=read(),y=read();Update(x,y);
    }
    return 0;
}
