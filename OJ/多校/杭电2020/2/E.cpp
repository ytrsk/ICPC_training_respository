#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
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
ll ans[51];
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
    ans[af]=ac;
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
    //cout<<u<<" "<<v<<endl;
	addedge(u,v,cap1,cost1);addedge(v,u,0,-cost1);
}
void init(){
	for(int i=1;i<=n;i++) head[i]=0;e1=1;
}
void mincost(ll &flow,ll &cost){
	while(spfa(flow,cost));
}
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
map<ll,int> aa;
ll A[maxn],B[maxn],C[maxn];
int main(){
    int T=read();
    while(T--){
        //init();
        aa.clear();e1=1;
        int N=read(),m=read();
        int cnt=0;
        for(int i=1;i<=N;i++){
            ll a=read(),b=read(),c=read();
            A[i]=a;B[i]=b;C[i]=c;
            int x=-b/(2*a);
            for(ll k=x-(N+1);k<=x+(N+1);k++){
                if(k>=1&&k<=m){
                    if(!aa[k]) aa[k]=++cnt;
                    add(i,N+aa[k],1,a*k*k+b*k+c);
                }
            }
        }
        for(ll i=1;i<=N+1;i++){
            if(i<=m){
                if(!aa[i]) aa[i]=++cnt;
                for(int k=1;k<=N;k++)
                add(k,N+aa[i],1,A[k]*i*i+B[k]*i+C[k]);
            }
        }
        for(ll i=m-N;i<=m;i++){
            if(i>=1){
                if(!aa[i]) aa[i]=++cnt;
                for(int k=1;k<=N;k++)
                add(k,N+aa[i],1,A[k]*i*i+B[k]*i+C[k]);
            }
        }
        n=N+cnt+2;s=n-1;t=n;
        for(int i=1;i<=N;i++) add(s,i,1,0);
        for(int i=1;i<=cnt;i++) add(N+i,t,1,0);
        ll flow=0,cost=0;
        mincost(flow,cost);init();
        for(int i=1;i<=N;i++) printf("%lld%c",ans[i],(i==N)?'\n':' ');
        printf("\n");
    }
	return 0;
}
