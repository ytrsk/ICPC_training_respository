#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
const int inf = 0x3f3f3f3f;
class Union{
private:
	int f[maxn];
public:
	Union(int n) {
		for(int i=1;i<=n;i++) f[i]=i;
	}
	int find(int x) {
        return f[x]==x?x:f[x]=find(f[x]);
	}
	void merge(int x,int y) {
		f[find(x)]=find(y);
	}
	bool check(int x,int y) {
		return find(x)==find(y);
	}
};
class Graph {
private:
	int w[maxn][maxn];
	int n;
	void dfs(bool *vis,vector<int> &res,int u) {
		if (vis[u]) return;
		vis[u]=true;
		res.push_back(u);
		for (int v=1;v<=n;v++) {
			if (vis[v]||w[u][v]==inf) continue;
			dfs(vis,res,v);
		}
	}
public:
	Graph(){
		memset(w,0x3f,sizeof(w));
	}
	Graph(int n):n(n){
		for(int i=1;i<=n;i++) for(int k=1;k<=n;k++) w[i][k]=inf;
	}
	void addedge(int u,int v,int x) {
		w[u][v]=w[v][u]=min(w[u][v],x);
	}
	vector<tuple<int,int,int>> kruskal() {
		Union unionset(n);
		vector<tuple<int,int,int>> edge;
		for (int i=1;i<=n;i++) {
			for (int k=i+1;k<=n;k++) {
				if (w[i][k]==inf) continue;
				edge.push_back({w[i][k],i,k});
			}
		}
		sort(edge.begin(),edge.end());
		vector<tuple<int,int,int> > res;
		for (auto x:edge){
			int w,u,v;
			tie(w,u,v)=x;
			if (!unionset.check(u,v)) {
				res.push_back(x);unionset.merge(u,v);
			}
		}
		return res;
	}
	vector<pair<int,int>> dijkstra(int s) {
		vector<pair<int,int> > dis(n+1,make_pair(inf,0));
		dis[s].first=0;
		priority_queue<pair<int,int>> q;
		q.emplace(0,s);
		while (!q.empty()) {
			int d,u;tie(d,u)=q.top();d=-d;
			q.pop();
			if (d>dis[u].first) continue;
			for (int v=1;v<=n;v++) {
				if(v==u||w[u][v]==inf) continue;
				if(dis[u].first+w[u][v]<dis[v].first){
					dis[v].first=dis[u].first+w[u][v];dis[v].second=u;
					q.emplace(-dis[v].first,v);
				}
			}
		}
		return dis;
	}
	vector<int> BFS(int s) {
		vector <int>ans;
		bool vis[maxn];memset(vis,false,sizeof(vis));
		queue <int> q;
		q.push(s);vis[s]=true;
		while (!q.empty()) {
			int u=q.front();ans.push_back(u);q.pop();
			for (int v=1;v<=n;v++){
				if(vis[v]||w[u][v]==inf) continue;
				q.push(v);vis[v]=true;
			}
		}
		return ans;
	}
	vector<int> DFS(int u) {
		vector<int> res;
		bool vis[maxn];
		memset(vis,false,sizeof(vis));
		dfs(vis,res,u);
		return res;
	}
	void dfs_loop(bool *vis,int u,int fa,bool &flag){
		vis[u]=true;
		for(int i=1;i<=n;i++){
			if(w[u][i]==inf) continue;
			if(!vis[i]) dfs_loop(vis,i,u,flag);
			else{
				if(i!=fa) flag=true;
			}
		}
	}
	bool loop(){
		bool vis[maxn];
		memset(vis,false,sizeof(vis));
		bool ans=false;
		for(int i=1;i<=n;i++) if(!vis[i]) dfs_loop(vis,i,0,ans);
		return ans;
	}
};
int main() {
	int n,m;scanf("%d%d",&n,&m);
	Graph g(n);
	for (int i=0;i<m;i++) {
		int u,v,w;scanf("%d%d%d",&u,&v,&w);g.addedge(u,v,w);
	}
	auto bfsres = g.BFS(1);
	for(int i=0;i<bfsres.size();i++) {
		printf("%d%c",bfsres[i],i==bfsres.size()-1?'\n':' ');
	}
	auto dfsres = g.DFS(1);
	for(int i=0;i<dfsres.size();i++) {
		printf("%d%c",dfsres[i],i==dfsres.size()-1?'\n':' ');
	}
	auto dis = g.dijkstra(1);
	for (int i=2;i<=n;i++) {
		if(dis[i].first==inf) cout<<"0\n";
		else{
			stack<int> S;int x=i;
			while(x){
				S.push(x);x=dis[x].second;
			}
			while(!S.empty()){
				printf("%d ",S.top());S.pop();
			}
			cout<<dis[i].first<<endl;
		}
	}
	auto e=g.kruskal();
	for (auto i:e) {
		int x,u,v;tie(x,u,v)=i;
		cout<<u<<" "<<v<<" "<<x<<endl;
	}
	if (g.loop()) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}