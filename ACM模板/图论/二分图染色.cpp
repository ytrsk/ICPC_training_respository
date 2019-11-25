#include <vector>
using namespace std;
const int maxn=100007;
int vis[maxn],flag;
vector<int> g[maxn];
int dfs(int u){
	if(!vis[u]) vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!vis[v]){
			vis[v]=((vis[u]-1)^1)+1;dfs(v);
		}
		else if(vis[v]!=((vis[u]-1)^1)+1) flag=1;
	}
}
