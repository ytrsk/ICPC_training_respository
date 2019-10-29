#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=300007;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
vector<pair<pii,int> > g[maxn];
int Vis[maxn];
ll d[maxn];
const ll inf=(1LL<<60);
int cur[maxn],vis[maxn],head[maxn];
int e1,to[maxn<<1],nex[maxn<<1],from[maxn<<1];
ll cap[maxn<<1],n;
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
        if(d[u]+1==d[v]
           &&(f=dfs(v,min(now,cap[i])))>0){
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
    //printf("%d %d %lld\n",u,v,c);
    addedge(u,v,c);addedge(v,u,0);
}
void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    for(int i=1;i<=e1;i++) to[i]=0;
    e1=1;
}
void spfa(int n,int s){
    queue<int> q;
    for(int i=1;i<=n;i++) d[i]=inf;
    Vis[s]=1;d[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();Vis[u]=0;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].first.first;
            if(d[u]+g[u][i].first.second<d[v]){
                d[v]=d[u]+g[u][i].first.second;
                if(!Vis[v]){
                    Vis[v]=1;q.push(v);
                }
            }
        }
    }
}
void Addedge(int u,int v,int x){
    g[u].push_back(mp(mp(v,1),x));
}
int main(){
    int T=read();
    while(T--){
        int nn=read(),m=read();
        for(int i=1;i<=nn;i++) g[i].clear();
        for(int i=1;i<=m;i++){
            int u=read(),v=read(),x=read();
            Addedge(u,v,x);Addedge(v,u,x);
        }
        spfa(nn,1);
        n=nn+2;s=n-1;t=n;init();
        add(s,1,inf);add(nn,t,inf);
        for(int i=1;i<=nn;i++){
            for(int k=0;k<g[i].size();k++){
                if(d[g[i][k].first.first]==d[i]+g[i][k].first.second){
                    add(i,g[i][k].first.first,g[i][k].second);
                }
            }
        }
        printf("%lld\n",dinic());
    }
    return 0;
}
