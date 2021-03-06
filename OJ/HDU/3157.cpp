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
ll A[maxn];
void init(){
	for(int i=1;i<=n;i++) head[i]=0,A[i]=0;
	for(int i=1;i<=e1;i++) to[i]=0;e1=1;
}
void Add(int u,int v,ll l,ll r){
	A[u]-=l;A[v]+=l;add(u,v,r-l);
}
int N;
int solve(char *s){
    if(s[1]=='+') return N-1;
    else if(s[1]=='-') return N;
    else{
        int x;sscanf(s+1,"%d",&x);return x;
    }
}
//要求出具体流量，必须有严格的源汇
int main(){
	int M;
    //asdhasdhaksjdhjkashdkjashdkjhasjkdhkjashdkjasdhashdasdhkj
	while(N=read(),M=read(),N||M){
        int SS,TT,S,T;
        N+=2;
		n=N+4;S=n-3;T=n-2;SS=n-1;TT=n;
		init();    
        for(int i=1;i<=M;i++){
            char ss[23],S[23];ll x;
            scanf("%s%s%lld",ss+1,S+1,&x);
            int u=solve(ss),v=solve(S);
            Add(u,v,x,inf);
        }
        Add(S,N-1,0,inf);Add(N,T,0,inf);
		for(int i=1;i<=n-2;i++)
        if(A[i]>0) add(SS,i,A[i]);
        else if(A[i]<0) add(i,TT,-A[i]);
		add(T,S,inf);
		s=SS;t=TT;
        dinic();//asdasdasd
		int ok=1;for(int i=head[SS];i;i=nex[i]) if(cap[i]) ok=0;
		if(!ok) printf("impossible\n");
		else{
			s=T;t=S;ll ans=cap[e1];cap[e1^1]=cap[e1]=0;
			printf("%lld\n",ans-dinic());
		}
	}
	return 0;
}
