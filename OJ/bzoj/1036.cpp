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
int a[maxn],son[maxn],mx[maxn<<2],sum[maxn<<2];
void pushup(int o){
    sum[o]=sum[o<<1]+sum[o<<1|1];
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void build(int o,int l,int r){
    if(l==r){
        mx[o]=sum[o]=a[id[l]];return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    pushup(o);
}
void modify(int o,int l,int r,int x,int y){
    if(l==r){
        mx[o]=sum[o]=y;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) modify(o<<1,l,m,x,y);
    else modify(o<<1|1,m+1,r,x,y);
    pushup(o);
}
int query_max(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return mx[o];
    }
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return max(query_max(o<<1,l,m,ql,m),query_max(o<<1|1,m+1,r,m+1,qr));
    else if(ql<=m) return query_max(o<<1,l,m,ql,qr);
    else return query_max(o<<1|1,m+1,r,ql,qr);
}
int query_sum(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return sum[o];
    }
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return query_sum(o<<1,l,m,ql,m)+query_sum(o<<1|1,m+1,r,m+1,qr);
    else if(ql<=m) return query_sum(o<<1,l,m,ql,qr);
    else return query_sum(o<<1|1,m+1,r,ql,qr);
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
int Query_max(int x,int y){
    int fx=tp[x],fy=tp[y],ans=-0x3f3f3f3f;
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            ans=max(ans,query_max(1,1,n,dfn[fx],dfn[x]));
            x=f[fx],fx=tp[x];
        }
        else{
            ans=max(ans,query_max(1,1,n,dfn[fy],dfn[y]));
            y=f[fy],fy=tp[y];
        }
    }
    if(dfn[x]<=dfn[y]) ans=max(ans,query_max(1,1,n,dfn[x],dfn[y]));
    else ans=max(ans,query_max(1,1,n,dfn[y],dfn[x]));
    return ans;
}
int Query_sum(int x,int y){
    int fx=tp[x],fy=tp[y],ans=0;
    while(fx!=fy){
        if(d[fx]>=d[fy]){
            ans+=query_sum(1,1,n,dfn[fx],dfn[x]);
            x=f[fx],fx=tp[x];
        }
        else{
            ans+=query_sum(1,1,n,dfn[fy],dfn[y]);
            y=f[fy],fy=tp[y];
        }
    }
    if(dfn[x]<=dfn[y]) ans+=query_sum(1,1,n,dfn[x],dfn[y]);
    else ans+=query_sum(1,1,n,dfn[y],dfn[x]);
    return ans;
}
void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    e1=cl=0;
}
//notice : init()       a[] in dfs
int main(){
    int t=1;
    while(t--){
        n=read();init();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            addedge(u,v);addedge(v,u);
        }
        for(int i=1;i<=n;i++) a[i]=read();
        dfs1(1,0);dfs2(1,1);build(1,1,n);
        int q=read();
        while(q--){
            char s[12];scanf("%s",s+1);
            if(s[1]=='C'){
                int x=read(),y=read();
                modify(1,1,n,dfn[x],y);
            }
            else if(s[1]=='Q'&&s[2]=='M'){
                int u=read(),v=read();
                printf("%d\n",Query_max(u,v));
            }
            else{
                int u=read(),v=read();
                printf("%d\n",Query_sum(u,v));
            }
        }
    }
    return 0;
}
