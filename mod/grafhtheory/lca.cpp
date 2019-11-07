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
int lg[maxn],tp[maxn],dep[maxn],st[maxn][27],head[maxn],to[maxn<<1],next1[maxn<<1],e1;
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=16;i>=0;i--) if(dep[st[u][i]]>=dep[v]) u=st[u][i];
	if(u==v) return u;
	for(int i=16;i>=0;i--) if(st[u][i]!=st[v][i]) u=st[u][i],v=st[v][i];
	return st[u][0];
}
void dfs(int u,int fa){
	st[u][0]=fa;dep[u]=dep[fa]+1;
	for(int i=1;i<=16;i++) st[u][i]=st[st[u][i-1]][i-1];
	tp[u]=fa?tp[fa]:u;
	for(int i=head[u];i;i=next1[i]){
		int v=to[i];
		if(v!=fa) dfs(v,u);
	}
}
void addedge(int u,int v){
	++e1;next1[e1]=head[u];head[u]=e1;to[e1]=v;
}
int main(){
	return 0;
}
