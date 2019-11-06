#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int son[maxn],e1;ll md[maxn],d[maxn],a[maxn];
int head[maxn],to[maxn<<1],nex[maxn<<1];
priority_queue<ll> q;
void dfs1(int u,int fa){
    md[u]=d[u];
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        d[v]=d[u]+a[v];dfs1(v,u);
        md[u]=max(md[u],md[v]);
        if(md[v]>md[son[u]]) son[u]=v;
    }
}
int n,tp[maxn];
void dfs2(int u,int fa){
    if(!son[u]){
        q.push(d[u]-d[tp[u]]+a[tp[u]]);
        return;
    }
    tp[son[u]]=tp[u];dfs2(son[u],u);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==son[u]||v==fa) continue;
        tp[v]=v;
        dfs2(v,u);
    }
}
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    e1=0;
}
int main(){
    n=read();init();int m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    d[1]=a[1];tp[1]=1;
    dfs1(1,0);dfs2(1,0);
    int T=m;
    ll ans=0;
    while((T--)&&!q.empty()){
        ans+=q.top();q.pop();
    }
    printf("%lld",ans);
    return 0;
}
