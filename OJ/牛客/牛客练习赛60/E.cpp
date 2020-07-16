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
ll n,*f[maxn],dp[maxn],ans[maxn],*cur=dp+1,a[maxn],K;
ll dp2[maxn],*g[maxn],*cur2=dp2+1;
void dfs2(int u,int fa){
    f[u][0]=a[u];ans[u]=0;g[u][0]=1;
    if(!son[u]) return;
    f[son[u]]=f[u]+1;g[son[u]]=g[u]+1;
    dfs2(son[u],u);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==son[u]||v==fa) continue;
        f[v]=cur;g[v]=cur2;
        cur+=md[v]-d[v]+1;cur2+=md[v]-d[v]+1;
        dfs2(v,u);
        for(int k=0;k<=md[v]-d[v];k++){
            int x=K-(k+1);
            if(x>=1&&x<=md[u]-d[u]) ans[u]+=f[u][x]*g[v][k]+g[u][x]*f[v][k];
        }
        for(int k=0;k<=md[v]-d[v];k++){
            f[u][k+1]+=f[v][k];
            g[u][k+1]+=g[v][k];
        }
    }
}
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    e1=0;cur=dp+1;cur2=dp2+1;
}
int main(){
    n=read();init();K=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs1(1,0);
    f[1]=cur;cur+=md[1]+1;
    g[1]=cur2;cur2+=md[1]+1;
    dfs2(1,0);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    return 0;
}
