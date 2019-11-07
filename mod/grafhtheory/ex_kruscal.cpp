#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=200007;
struct edge{
	int to,w;
	edge(int to,int w):to(to),w(w){
	}
};
int fa[maxn],a[maxn<<1],e1,head[maxn],to[maxn<<1],next[maxn<<1],from[maxn<<1],w[maxn<<1],mx[maxn][17];
int cmp(int x,int y){
	return w[x]<w[y];
}
vector<edge> g[maxn];
void addedge(int u,int v,int w1){
	++e1;next[e1]=head[u];head[u]=e1;to[e1]=v;from[e1]=u;w[e1]=w1;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int lg[maxn],tp[maxn],dep[maxn],st[maxn][27];
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int ans=0;
	for(int i=16;i>=0;i--) if(dep[st[u][i]]>=dep[v]) ans=max(mx[u][i],ans),u=st[u][i];
	if(u==v) return ans;
	for(int i=16;i>=0;i--) if(st[u][i]!=st[v][i]) ans=max(ans,max(mx[u][i],mx[v][i])),u=st[u][i],v=st[v][i];
	return max(ans,mx[u][0]);
}
void dfs(int u,int fa,int val){
	st[u][0]=fa;dep[u]=dep[fa]+1;mx[u][0]=val;
	for(int i=1;i<=16;i++) st[u][i]=st[st[u][i-1]][i-1],mx[u][i]=max(mx[u][i-1],mx[st[u][i-1]][i-1]);
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].to;
		if(v!=fa) dfs(v,u,g[u][i].w);
	}
}
int vis[maxn<<1];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);addedge(u,v,w);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=e1;i++) a[i]=i;
	sort(a+1,a+e1+1,cmp);
	ll ans=0;
	for(int i=1;i<=e1;i++){
		int u=from[i],v=to[i],x=find(u),y=find(v);
		if(x!=y){
			vis[i]=1;fa[x]=y;ans+=w[i];
		}
	}
	ll pre=ans;ans=(1LL<<60);
	for(int i=1;i<=e1;i++){
		if(vis[i]){
			g[from[i]].push_back(edge(to[i],w[i]));
			g[to[i]].push_back(edge(from[i],w[i]));
		}
	}
	for(int i=1;i<=e1;i++){
		if(vis[i]) continue;
		int ans1=lca(from[i],to[i]);
		ans=min(ans,pre-ans1+w[i]);
	}
	printf("%lld",ans);
	return 0;
}

