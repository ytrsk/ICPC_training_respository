#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=100007;
int lg[maxn],tp[maxn],d[maxn],st[maxn][27],head[maxn],to[maxn<<1],nex[maxn<<1],e1;
int lca(int u,int v){
	if(d[u]<d[v]) swap(u,v);
    int x=d[u]-d[v];
	for(int i=0;(1<<i)<=x;i++) if(x>>i&1) u=st[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;i--) if(st[u][i]!=st[v][i]) u=st[u][i],v=st[v][i];
	return st[u][0];
}
void dfs(int u,int fa){
	st[u][0]=fa;d[u]=d[fa]+1;
	for(int i=1;i<=19;i++) st[u][i]=st[st[u][i-1]][i-1];
	tp[u]=fa?tp[fa]:u;
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v!=fa) dfs(v,u);
	}
}
void addedge(int u,int v){
	++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int main(){
	return 0;
}
