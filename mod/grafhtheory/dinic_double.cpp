#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=250007;
const double eps=1e-8;
const double inf=1e9;
int cur[maxn],vis[maxn],head[maxn],d[maxn];
int e1,to[maxn<<1],next1[maxn<<1],from[maxn<<1];double cap[maxn<<1];int n;
int s,t;
bool bfs(){
	for(int i=1;i<=n;i++) vis[i]=0,d[i]=-1;
	queue<int> q;
	q.push(s);d[s]=0;vis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=next1[i]){
			int v=to[i];
			if(!vis[v]&&cap[i]>0){
				vis[v]=1;
				d[v]=d[u]+1;q.push(v);
			}
		}
	}
	return vis[t];
}
double dfs(int u,double now){
	if(u==t||now==0) return now;
	double ans=0,f;
	for(int &i=cur[u];i;i=next1[i]){
		int v=to[i];
		if(d[u]+1==d[v]&&(f=dfs(v,min(now,cap[i])))>0){
			cap[i]-=f;
			cap[i^1]+=f;
			ans+=f;
			now-=f;
			if(now==0) break;
		}
	}
	return ans;
}
double dinic(){
	double ans=0;
	while(bfs()){
		for(int i=1;i<=n;i++) cur[i]=head[i];
		ans+=dfs(s,inf);
	}
	return ans;
}
void addedge(int u,int v,double cap1){
	++e1;from[e1]=u;next1[e1]=head[u];head[u]=e1;to[e1]=v;cap[e1]=cap1;
}
void add(int u,int v,double cap1){
	addedge(u,v,cap1);addedge(v,u,0);
}
void init(){
	for(int i=1;i<=n;i++) head[i]=0;for(int i=1;i<=e1;i++) to[i]=0;e1=1;
}
int main(){
    int tt;cin>>tt;
	int nn,m;scanf("%d%d",&nn,&m);
	return 0;
}
