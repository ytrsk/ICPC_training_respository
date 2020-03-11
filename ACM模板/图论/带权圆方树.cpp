#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pii pair<int,int>
const int maxn=100007;
typedef long long ll;
vector<pii> g[maxn];
int n,cl,dfn[maxn],low[maxn];
int e1,head[maxn<<1],to[maxn<<2],nex[maxn<<2];
int dcnt=0;
ll w[maxn<<2],S[maxn<<1];
inline void Addedge(int u,int v,ll x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
inline void Add(int u,int v,ll x){
    Addedge(u,v,x);Addedge(v,u,x);
}
//只有仙人掌才可以用带权方式
int F[maxn],W[maxn];
void solve(int u,int v,int x){
    dcnt++;
    ll Pre=x;
    for(int i=v;i^F[u];i=F[i]){
        S[i]=Pre;Pre+=W[i];
    }
    S[dcnt+n]=S[u];S[u]=0;
    for(int i=v;i^F[u];i=F[i]) Add(n+dcnt,i,min(S[i],S[n+dcnt]-S[i]));
}
void tarjan(int u,int fa){
    dfn[u]=low[u]=++cl;
    for(int i=0;i<g[u].size();i++){
        pii now=g[u][i];int v=now.second;
        if(!dfn[v]){
            F[v]=u;W[v]=now.first;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]) Add(u,v,now.first);
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);
    }
    for(int i=0;i<g[u].size();i++){
        pii now=g[u][i];int v=now.second;
        if(F[v]!=u&&dfn[v]>dfn[u]) solve(u,v,now.first);
    }
}
ll dis[maxn<<1];
int st[maxn<<1][27],d[maxn];
int NX,NY;
int lca(int u,int v){
	if(d[u]<d[v]) swap(u,v);
    int x=d[u]-d[v];
	for(int i=0;(1<<i)<=x;i++) if(x>>i&1) u=st[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;i--) if(st[u][i]!=st[v][i]) u=st[u][i],v=st[v][i];
    NX=u;NY=v;
	return st[u][0];
}
void dfs(int u,int fa){
	st[u][0]=fa;d[u]=d[fa]+1;
	for(int i=1;i<=19;i++) st[u][i]=st[st[u][i-1]][i-1];
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v!=fa) dis[v]=dis[u]+w[i],dfs(v,u);
	}
}
void init(){
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=0;
    dcnt=cl=e1=0;
    for(int i=1;i<=2*n;i++) head[i]=0;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
	n=read();init();    
    int m=read(),q=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),x=read();
        g[u].push_back(mp(x,v));
        g[v].push_back(mp(x,u));
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    dfs(1,0);
    for(int i=1;i<=q;i++){
        int u=read(),v=read();
        int x=lca(u,v);
        if(x<=n){
            printf("%lld\n",dis[u]+dis[v]-2*dis[x]);
        }
        else{
            if(dfn[NX]<dfn[NY]) swap(NX,NY),swap(u,v);
            ll sum=min(S[x]-S[NY]+S[NX],S[NY]-S[NX]);
            printf("%lld\n",dis[u]+dis[v]-dis[NX]-dis[NY]+sum);
        }
    }
    return 0;
}
