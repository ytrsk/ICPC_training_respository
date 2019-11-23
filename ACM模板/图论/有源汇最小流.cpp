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
int cur[maxn],vis[maxn],head[maxn],d[maxn];
int e1,to[maxn<<1],nex[maxn<<1],from[maxn<<1];ll cap[maxn<<1],n;
int s,t;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
bool bfs(){
	for(int i=1;i<=n;i++) vis[i]=0,d[i]=-1;
	queue<int> q;
	q.push(s);d[s]=0;vis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=nex[i]){
			int v=to[i];
			if(!vis[v]&&cap[i]){
				vis[v]=1;
				d[v]=d[u]+1;q.push(v);
			}
		}
	}
	return vis[t];
}
ll dfs(int u,ll now){
	if(u==t||now==0) return now;
	ll ans=0,f;
	for(int &i=cur[u];i;i=nex[i]){
		int v=to[i];
		if(d[u]+1==d[v]&&(f=dfs(v,min(now,cap[i])))>0){
			cap[i]-=f;
			cap[i^1]+=f;
			ans+=f;
			now-=f;
			if(!now) break;
		}
	}
	return ans;
}
ll dinic(){
	ll ans=0;
	while(bfs()){
		for(int i=1;i<=n;i++)
        cur[i]=head[i];
		ans+=dfs(s,inf);
	}
	return ans;
}
void addedge(int u,int v,ll c){
	++e1;from[e1]=u;nex[e1]=head[u];
	head[u]=e1;to[e1]=v;cap[e1]=c;
}
void add(int u,int v,ll c){
	addedge(u,v,c);addedge(v,u,0);
}
int A[maxn];
void init(){
	for(int i=1;i<=n;i++) head[i]=0,A[i]=0;
	for(int i=1;i<=e1;i++) to[i]=0;e1=1;
}
void Add(int u,int v,ll l,ll r){
	A[u]-=l;A[v]+=l;add(u,v,r-l);
}
int you[maxn],L[maxn],R[maxn];
int main(){
	int cnt=1;
	while(cnt--){
        int N=read(),m=read();
        int SS,TT,S,T;
		n=N+4;S=n-3;T=n-2;SS=n-1;TT=n;
		init();Add(S,1,0,inf);
		Add(N,T,0,inf);
		for(int i=1;i<=m;i++){
			int u=read(),v=read(),x=read(),y=read();
			if(y) Add(u,v,x,x),L[i]=x;
			else Add(u,v,0,x),L[i]=0;
			you[i]=e1;
		}
		for(int i=1;i<=n-2;i++)
        if(A[i]>0) add(SS,i,A[i]);
        else if(A[i]<0) add(i,TT,-A[i]);
		add(T,S,inf);
		s=SS;t=TT;
		dinic();
		int ok=1;for(int i=head[SS];i;i=nex[i]) if(cap[i]) ok=0;
		if(!ok) printf("Impossible\n");
		else{
			s=T;t=S;ll ans=cap[e1];cap[e1^1]=cap[e1]=0;
			printf("%lld\n",ans-dinic());
			for(int i=1;i<=m;i++) printf("%lld%c",L[i]+cap[you[i]],i==m?'\n':' ');
		}
	}
	return 0;
}
