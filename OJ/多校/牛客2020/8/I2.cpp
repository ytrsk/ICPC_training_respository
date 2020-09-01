#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=1000007;
const ll inf=(1LL<<60);
int cur[maxn],vis[maxn],head[maxn],d[maxn];
int e1,to[maxn<<1],nex[maxn<<1],from[maxn<<1];ll cap[maxn<<1],n;
int s,t;

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
void init(){
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<=e1;i++) to[i]=0;e1=1;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
map<int,int> aa;
int main(){
	int cnt,now=0;cin>>cnt;
	while(cnt--){
        int nn=0,m;scanf("%d",&m);
        e1=1;aa.clear();
        for(int i=1;i<=m;i++){
            int u=read(),v=read();
            if(!aa.count(u)) aa[u]=++nn;
            if(!aa.count(v)) aa[v]=++nn;
            u=aa[u];v=aa[v];
            add(i,m+u,1);
            add(i,m+v,1);
        }
        n=nn+m+2;s=n-1;t=n;
        for(int i=1;i<=m;i++) add(s,i,1);
        for(int i=1;i<=nn;i++) add(m+i,t,1);
        printf("Case #%d: %d\n",++now,dinic());
        init();
	}
	return 0;
}

