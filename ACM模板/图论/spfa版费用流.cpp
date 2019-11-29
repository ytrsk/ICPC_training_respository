#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=100007;
const ll inf=(1LL<<60);
int p[maxn],cur[maxn],inq[maxn],head[maxn];
int e1,to[maxn<<1],next1[maxn<<1],from[maxn<<1];
ll cap[maxn<<1],n,cost[maxn<<1],d[maxn],now[maxn];
int s,t;
bool spfa(ll &af,ll &ac){
	now[s]=inf;
	queue<int> q;q.push(s);
	for(int i=1;i<=n;i++) d[i]=inf,inq[i]=0;
	inq[s]=1;d[s]=0;p[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head[u];i;i=next1[i]){
			int v=to[i];
			if(cap[i]&&d[v]>d[u]+cost[i]){
				d[v]=d[u]+cost[i];
				p[v]=i;
				now[v]=min(now[u],cap[i]);
				if(!inq[v]){
					inq[v]=1;q.push(v);
				}
			}
		}
	}
	if(d[t]==inf) return false;
	af+=now[t];ac+=d[t]*now[t];
	int u=t;
	while(u!=s){
		cap[p[u]]-=now[t];
		cap[p[u]^1]+=now[t];
		u=from[p[u]];
	}
	return true;
}
void addedge(int u,int v,ll cap1,ll cost1){
	++e1;next1[e1]=head[u];head[u]=e1;to[e1]=v;cap[e1]=cap1;cost[e1]=cost1;from[e1]=u;
}
void add(int u,int v,ll cap1,ll cost1){
	addedge(u,v,cap1,cost1);addedge(v,u,0,-cost1);
}
void init(){
	for(int i=1;i<=n;i++) head[i]=0;for(int i=1;i<=e1;i++) to[i]=0;e1=1;
}
void mincost(ll &flow,ll &cost){
	while(spfa(flow,cost));
}
int main(){
	ll flow=0,cost=0;
	mincost(flow,cost);
	return 0;
}
