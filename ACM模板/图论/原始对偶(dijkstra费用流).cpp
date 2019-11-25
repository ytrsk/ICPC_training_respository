#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int from[maxn<<1],head[maxn<<1],to[maxn<<1],nex[maxn<<1],e1,n,vis[maxn],s,t;
ll cost[maxn<<1],cap[maxn<<1],mc,mf,delta,d[maxn];
inline void addedge(int u,int v,ll c,ll w){
    ++e1;nex[e1]=head[u];head[u]=e1;
    from[e1]=u;to[e1]=v;cap[e1]=c;cost[e1]=w;
}
inline void add(int u,int v,ll c,ll w){
    addedge(u,v,c,w);
    addedge(v,u,0,-w);
}
inline void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    e1=1;mc=mf=0;delta=0;
}
bool spfa(){
    queue<int> q;for(int i=1;i<=n;i++) d[i]=inf,vis[i]=0;
    d[s]=0;q.push(s);vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(cap[i]&&d[v]>d[u]+cost[i]){
                d[v]=d[u]+cost[i];
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return d[t]!=inf;
}
inline bool dijkstra(){
    for(int i=1;i<=n;++i) d[i]=inf,vis[i]=0;
    priority_queue<pair<ll,int>> q;d[s]=0;q.push(mp(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(cap[i]&&d[v]>d[u]+cost[i]){
                d[v]=d[u]+cost[i];
                q.push(mp(-d[v],v));
            }
        }
    }
    return d[t]!=inf;
}
/*
#include <ext/pb_ds/priority_queue.hpp>
typedef pair<ll,int> pli;
typedef __gnu_pbds::priority_queue<pli,greater<pli>,__gnu_pbds::pairing_heap_tag> pq;
pq::point_iterator it[maxn];
inline bool dijkstra(){
    for(int i=1;i<=n;++i) d[i]=inf,it[i]=0;
    pq q;d[s]=0;
    it[s]=q.push(mp(0LL,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(cap[i]&&d[v]>d[u]+cost[i]){
                d[v]=d[u]+cost[i];
                if(it[v]==NULL) it[v]=q.push(mp(d[v],v));
                else q.modify(it[v],mp(d[v],v));
            }
        }
    }
    return d[t]!=inf;
}*/
inline ll dfs(int u,ll now){
	if(u==t||now==0) return now;
	vis[u]=1;
	ll ans=0,f;
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(!vis[v]&&cap[i]&&!cost[i]&&(f=dfs(v,min(now,cap[i])))>0){
			cap[i]-=f;cap[i^1]+=f;
			ans+=f;now-=f;
			if(!now) break;
		}
	}
	return ans;
}
inline void augment(){
    for(int i=2;i<=e1;i++) cost[i]+=d[from[i]]-d[to[i]];
    delta+=d[t];
    ll now=0;
    while(memset(vis,0,sizeof(vis)),now=dfs(s,inf)){
        mf+=now;
        mc+=now*delta;
    }
}
inline void primal_dual(){
    if(!spfa()) return;
    augment();
    while(dijkstra()) augment();
}
int main(){
    int m;
    n=read(),m=read(),s=read(),t=read();init();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),x=read(),y=read();
        add(u,v,x,y);
    }
    primal_dual();
    printf("%lld %lld",mf,mc);
    return 0;
}
