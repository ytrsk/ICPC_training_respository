#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=400007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int md[maxn],d[maxn],son[maxn],e1;
int head[maxn],to[maxn<<1],nex[maxn<<1];
void dfs1(int u,int fa){
    md[u]=d[u];son[u]=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        d[v]=d[u]+1;dfs1(v,u);
        md[u]=max(md[u],md[v]);
        if(md[v]>md[son[u]]) son[u]=v;
    }
}
ll n,*f[maxn],dp[maxn],ans[maxn],*cur=dp+1,pos=1,val[maxn<<2],a[maxn];
int L[maxn],R[maxn];

int tag[maxn<<2];
void pushdown(int o){
    tag[o<<1]+=tag[o];tag[o<<1|1]+=tag[o];
    tag[o]=0;
}
void update(int o,int l,int r,int ql,int qr){
    if(ql==l&&r==qr){
        tag[o]--;return;
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m),update(o<<1|1,m+1,r,m+1,qr);
    else if(ql<=m) update(o<<1,l,m,ql,qr);
    else update(o<<1|1,m+1,r,ql,qr);
}
void up(int o,int l,int r,int x,ll y){
    if(r==l){
        tag[o]=0;val[o]=y;return;    
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(x<=m) up(o<<1,l,m,x,y);
    else up(o<<1|1,m+1,r,x,y);
}
ll query(int o,int l,int r,int x){
    if(l==r){
        val[o]=min(val[o],max(1LL,val[o]+tag[o]));
        tag[o]=0;return val[o];
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(x<=m) return query(o<<1,l,m,x);
    else return query(o<<1|1,m+1,r,x);
}
ll query(int u,int x){
    ll now=query(1,1,200003,L[u]+x);
    return now;
}
void dfs2(int u,int fa){
    up(1,1,200003,L[u],a[u]);
    if(!son[u]){
        update(1,1,200003,L[u],R[u]);
        return;
    }
    f[son[u]]=f[u]+1;L[son[u]]=L[u]+1;R[son[u]]=R[u];
    dfs2(son[u],u);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==son[u]||v==fa) continue;
        f[v]=cur;cur+=md[v]-d[v]+1;
        L[v]=pos;pos+=md[v]-d[v]+1;R[v]=pos-1;
        dfs2(v,u);
        for(int k=0;k<=md[v]-d[v];k++){
            up(1,1,200003,k+1+L[u],query(u,k+1)+query(v,k));
        }
    }
    update(1,1,200003,L[u],R[u]);
}
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    e1=0;cur=dp+1;pos=1;
}
int main(){
    n=read();init();int rt=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs1(rt,0);
    f[rt]=cur;cur+=md[rt]+1;L[rt]=pos;pos+=md[rt]+1;R[rt]=pos-1;
    dfs2(rt,0);
    ll ans=0;
    for(int i=0;i<=md[rt];i++) ans+=query(rt,i);
    cout<<ans;
    return 0;
}
