#include <bits/stdc++.h>
#define make_pair mp
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int maxn=100007;
const int inf=(1LL<<29);
int ans,e1,rt,totn,val[4],dep[maxn],w[maxn<<1],f[maxn],head[maxn],to[maxn<<1],nex[maxn<<1],sz[maxn];
bool vis[maxn];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void getrt(int u,int fa){
    sz[u]=1;f[u]=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=fa&&!vis[v]){
            getrt(v,u);sz[u]+=sz[v];f[u]=max(f[u],sz[v]);
        }
    }
    f[u]=max(f[u],totn-sz[u]);
    if(f[u]<f[rt]) rt=u;
}
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
int ee;
int mn[maxn*220],ls[maxn*220],rs[maxn*220],val[maxn*220];
void pushup(int o){
    mn[o]=min(mn[ls[o]],mn[rs[o]]);
}
void ins(int o,int l,int r,int x,int y,int opt){
    if(!o) o=++ee,mn[o]=inf;
    if(l==r){
        if(opt==1) mn[o]=min(mn[o],)
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) ins(ls[o],l,mid,x,y);
    else ins(rs[o],mid+1,r,x,y);
    pushup(o);
}
void getdep(int u,int fa,int F){
    val[dep[u]]++;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!vis[v]&&v!=fa){
            dep[v]=(dep[u]+w[i])%3;
            getdep(v,u);
        }
    }
}
void getDep(int u,int fa,int F){
    ins(rt[F],1,10000,a[u],d[u]);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!vis[v]&&v!=fa){
            dep[v]=(dep[u]+w[i])%3;
            getdep(v,u);
        }
    }
}
int calc(int u,int v){
    dep[u]=v;getdep(u,0);
}
int Fa[maxn];
void solve(int u){
    ans+=calc(u,0);
    vis[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!vis[v]){
            ans-=calc(v,w[i]);
            rt=0;totn=sz[v];
            getrt(v,0);
            solve(rt);
            Fa[rt]=u;
        }
    }
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v,x;scanf("%d%d%d",&u,&v,&x);
        addedge(u,v,x);addedge(v,u,x);
    }
    f[0]=totn=n;
    getrt(1,0);
    solve(rt);
    return 0;
}
