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
const ll inf=(1ll<<60);
int p[maxn],cur[maxn],inq[maxn],head[maxn];
int e1,to[maxn<<1],next1[maxn<<1],from[maxn<<1];
ll n,cost[maxn<<1],d[maxn];
int s,t;
ll calgcd(ll a,ll b) {
	if (b == 0) return a;
	return calgcd(b,a%b);
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
ll lcm(ll a,ll b) {
return a/calgcd(a,b)*b;
}
ll cc[maxn],CC[maxn];
ll cap[maxn<<1],now[maxn];
int top;
int Now,nn;
int vis[maxn],id[maxn];
ll ac,af;
bool spfa(){
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
	cc[af]=d[t];
	af+=now[t];
	ac+=now[t]*d[t];
	CC[af]=ac;
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
void print(ll a,ll b){
	printf("%lld/%lld\n",a/__gcd(a,b),b/__gcd(a,b));
}
int main(){
	int m;
	while(scanf("%d%d",&nn,&m)==2){
		n=nn+2;s=n-1;t=n;
		init();
		ac=af=0;Now=0;
		add(s,1,inf,0);
		add(nn,t,inf,0);
		for(int i=1;i<=m;i++){
			int u=read(),v=read(),c=read();
			add(u,v,1,c);
		}
		top=read();
		while(spfa());
		for(int i=1;i<=top;i++){

			int a=read(),b=read();			
			if(a==0){
				printf("NaN\n");
				continue;
			}
			int x=b/a;
			if(b%a==0){
				if(x<=af) print(CC[x]*a,b);
				else printf("NaN\n");
			}
			else{
				if(x>=af) printf("NaN\n");
				else{
					print(b%a*cc[x]+a*CC[x],b);
				}
			}
		}
	}
	return 0;
}
