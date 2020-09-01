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
void init(){
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<=e1;i++) to[i]=0;e1=1;
}
int a[57][57];
int v[107][107],f[57][57];
int calc(int n){
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++)
		v[i][k]=a[i][k];
	}
	for(int i=1;i<=n;i++)
	for(int k=1;k<=n;k++)
	for(int z=1;z<=n;z++)
	v[k][z]=min(v[k][z],v[k][i]+v[i][z]);
	return v[1][n]; 
}
int Ans=inf;
void dfs(int o,int p,int N){
	if(o==p+1){
		Ans=max(Ans,calc(N));return;
	}
	for(int i=1;i<=N;i++)
	for(int k=i+1;k<=N;k++){
		int pre=a[i][k];
		a[i][k]=a[k][i]=0x3f3f3f3f;
		dfs(o+1,p,N);
		a[i][k]=a[k][i]=pre;
	}
}
int main(){
	int cnt;cin>>cnt;
	while(cnt--){
        int N,m;cin>>N>>m;
		for(int i=1;i<=N*(N-1)/2;i++){
			int u=read(),v=read(),x=read();
			a[u][v]=a[v][u]=x;
		}
		n=2*N+2;s=n-1;t=n;
		int l=0,r=500000,ans=0;
		if(N==4||N==5||N==6||N==7||N==8){
			Ans=0;
			dfs(1,m,N);
			ans=max(ans,Ans);
		}
		else while(l<=r){
			int mid=(l+r)>>1;
			int now=0;
			init();
			for(int i=1;i<=2*N;i++)
			for(int k=1;k<=2*N;k++) v[i][k]=0;
			if(a[1][N]<mid) now++;
			for(int i=1;i<=N;i++) add(s,i,inf),add(N+i,t,inf);
			for(int i=2;i<N;i++){
				if(a[1][i]+a[i][N]<mid){
					v[i][N+i]=1;
				}
			}
			for(int i=2;i<N;i++){
				for(int k=i+1;k<N;k++){
					if(a[1][i]+a[i][k]+a[k][N]<mid){
						v[i][k+N]=1;
					}
					if(a[1][k]+a[k][i]+a[i][N]<mid){
						v[k][i+N]=1;
					}
				}
			}
			for(int i=2;i<N;i++){
				for(int k=i+1;k<N;k++){
					for(int z=k+1;z<N;z++){
						if(a[1][i]+a[i][k]+a[k][z]+a[z][N]<mid){
							v[i][z+N]=1;						
						}
						if(a[1][i]+a[i][z]+a[z][k]+a[k][N]<mid){
							v[i][k+N]=1;
						}
						if(a[1][k]+a[k][i]+a[i][z]+a[z][N]<mid){
							v[k][z+N]=1;
						}
						if(a[1][k]+a[k][z]+a[z][i]+a[i][N]<mid){
							v[k][i+N]=1;
						}
						if(a[1][z]+a[z][i]+a[i][k]+a[k][N]<mid){
							v[z][k+N]=1;
						}
						if(a[1][z]+a[z][k]+a[k][i]+a[i][N]<mid){
							v[z][i+N]=1;
						}
					}
				}
			}
			for(int i=1;i<=N;i++)
			for(int k=N+1;k<=2*N;k++)
			if(v[i][k]) add(i,k,1);
			if(dinic()+now<=m) l=mid+1,ans=mid;
			else r=mid-1;
		}
		//ans=0;

		printf("%d\n",ans);
	}
	return 0;
}
