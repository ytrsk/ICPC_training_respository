#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
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
int a[maxn],son[maxn],sum[maxn<<2][2],dp[maxn],you[maxn<<2];
int lz[maxn<<2];
void pushup(int o,int LL,int RR){
    int l=lz[o<<1],r=lz[o<<1|1];
    sum[o][0]=sum[o<<1][r]^sum[o<<1|1][l];
    sum[o][1]=sum[o<<1][r^1]^sum[o<<1|1][l^1];
    cout<<o<<" "<<sum[o][0]<<" "<<sum[o][1]<<" "<<LL<<" "<<RR<<" "<<l<<" "<<r<<endl;
    you[o]=you[o<<1]^you[o<<1|1];
}
void build(int o,int l,int r){  
    lz[o]=(r-l+1)%2;
    if(l==r){
        sum[o][0]=a[id[l]];
        you[o]=a[id[l]];
        sum[o][1]=0;
        return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    pushup(o,l,r);
}
void modify(int o,int l,int r,int x,int y){
    if(l==r){
        sum[o][0]=y;sum[o][1]=0;you[o]=y;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) modify(o<<1,l,m,x,y);
    else modify(o<<1|1,m+1,r,x,y);
    pushup(o,l,r);
}
int query(int o,int l,int r,int ql,int qr,bool p){
    if(l==ql&&r==qr){
        return sum[o][p];
    }
    int m=(l+r)>>1;
    int le=(m-ql+1)%2,ri=(qr-m)%2;
    if(ql<=m&&qr>m) return query(o<<1,l,m,ql,m,p^ri)^query(o<<1|1,m+1,r,m+1,qr,p^le);
    else if(ql<=m) return query(o<<1,l,m,ql,qr,p);
    else return query(o<<1|1,m+1,r,ql,qr,p);
}
int Query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return you[o];
    }
    int m=(l+r)>>1;
    int le=(m-ql+1)%2,ri=(qr-m)%2;
    if(ql<=m&&qr>m) return Query(o<<1,l,m,ql,m)^Query(o<<1|1,m+1,r,m+1,qr);
    else if(ql<=m) return Query(o<<1,l,m,ql,qr);
    else return Query(o<<1|1,m+1,r,ql,qr);
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
        dp[v]=dp[u]^a[v];
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
    int prex=x,prey=y;
    int fx=tp[x],fy=tp[y],ans=0,lca=0;
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            x=f[fx],fx=tp[x];
        }
        else{
            y=f[fy],fy=tp[y];
        }
    }
    lca=dfn[x]<dfn[y]?x:y;
    x=prex;y=prey;
    fx=tp[x],fy=tp[y],ans=0;
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            ans^=query(1,1,n,dfn[fx],dfn[x],(d[prex]&1)^(d[prey]&1));
            ans^=Query(1,1,n,dfn[fx],dfn[x]);
            x=f[fx],fx=tp[x];
        }
        else{
            ans^=query(1,1,n,dfn[fy],dfn[y],(d[prex]&1)^(d[prey]&1)^(d[y]&1)^(d[fy]&1));
            ans^=Query(1,1,n,dfn[fy],dfn[y]);
            y=f[fy],fy=tp[y];
        }
    }
    if(dfn[x]<dfn[y]) ans^=query(1,1,n,dfn[x],dfn[y],(d[prex]&1)^(d[prey]&1)^(d[y]&1)^(d[x]&1));
    else if(dfn[x]>dfn[y]) ans^=(ans,query(1,1,n,dfn[y],dfn[x],(d[prex]&1)^(d[prey]&1)));
    ans^=Query(1,1,n,min(dfn[x],dfn[y]),max(dfn[x],dfn[y]));
    return ans;
}
int U[maxn],V[maxn];
void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    e1=cl=0;
}
int main(){
    int t=1;
    while(t--){
        int q;n=read();q=read();init();
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<n;i++){
            U[i]=read(),V[i]=read();
            addedge(U[i],V[i]);addedge(V[i],U[i]);
        }
        dfs1(1,0);dfs2(1,1);build(1,1,n);
        for(int i=1;i<=q;i++){
            int opt=read(),x=read(),y=read();
            if(opt==1){
                modify(1,1,n,dfn[x],y);
            }
            else{
                printf("%d\n",Query(x,y));
            }
        }
    }
    return 0;
}
