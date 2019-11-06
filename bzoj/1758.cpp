#include <bits/stdc++.h>
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
int md[maxn],d[maxn],son[maxn],e1;
int head[maxn],to[maxn<<1],nex[maxn<<1],w[maxn<<1];
double tot[maxn],now;
double mx[maxn<<2];
inline void pushup(int o){
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
inline void ins(int o,int l,int r,int x,double y){
    if(l==r){
        mx[o]=y;return;
    }
    int m=(l+r)>>1;
    x<=m?ins(o<<1,l,m,x,y):ins(o<<1|1,m+1,r,x,y);
    pushup(o);
}
inline double query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr) return mx[o];
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return max(query(o<<1,l,m,ql,m),query(o<<1|1,m+1,r,m+1,qr));
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr);
}
inline void dfs1(int u,int fa){
    md[u]=d[u];
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        d[v]=d[u]+1;
        tot[v]=tot[u]+w[i]-now;
        dfs1(v,u);
        md[u]=max(md[u],md[v]);
        if(md[v]>md[son[u]]) son[u]=v;
    }
}
int L,U,n;
double *f[maxn],dp[maxn],*cur=dp+1;
double ans;
inline void dfs2(int u,int fa){
    f[u][0]=tot[u];ins(1,1,n,f[u]-dp,tot[u]);
    if(!son[u]) return;
    f[son[u]]=f[u]+1;dfs2(son[u],u);
    if(L<=md[u]-d[u]) ans=max(ans,query(1,1,n,f[u]-dp+L,f[u]-dp+min(U,md[u]-d[u]))-tot[u]);
    int mx=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==son[u]||v==fa) continue;
        f[v]=cur;cur+=md[v]-d[v]+1;dfs2(v,u);
        for(int k=0;k<=md[v]-d[v];k++){
            int a=max(L-k-1,0),b=min(md[u]-d[u],U-k-1);
            if(a<=b) ans=max(ans,f[v][k]+query(1,1,n,f[u]-dp+a,f[u]-dp+b)-2*tot[u]);
        }
        for(int k=0;k<=md[v]-d[v];k++){
            if(f[u][k+1]<f[v][k]){
                f[u][k+1]=f[v][k];
                ins(1,1,n,f[u]-dp+k+1,f[u][k+1]);
            }
        }
    }

}
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    e1=0;cur=dp+1;
}
int main(){
    n=read();init();L=read();U=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read(),x=read();
        addedge(u,v,x);addedge(v,u,x);
    }
    double l=0,r=1e7;
    for(int k=1;k<=50;k++){
        double mid=(l+r)/2.0;now=mid;
        cur=dp+1;
        dfs1(1,0);
        ans=-1;
        f[1]=cur;cur+=md[1]+1;
        dfs2(1,0);
        if(ans>=0) l=mid;
        else r=mid;
    }
    printf("%.3f",l);
    return 0;
}
