#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int head[maxn],to[maxn<<1],nex[maxn<<1],e1;
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int d[maxn],vis[maxn];
inline void dijkstra(int s,int n){
    for(int i=1;i<=n;++i) d[i]=inf,vis[i]=0;
    priority_queue<pair<ll,int>> q;d[s]=0;q.push(mp(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(d[v]>d[u]+1){
                d[v]=d[u]+1;
                q.push(mp(-d[v],v));
            }
        }
    }
}
vector<int> g[maxn];int a[maxn];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        addedge(v,u);g[u].push_back(v);
    }
    int tot=read();
    for(int i=1;i<=tot;i++) a[i]=read();
    dijkstra(a[tot],n);
    int mn=0,mx=0;
    for(int i=1;i<tot;i++){
        if(d[a[i+1]]==d[a[i]]-1){
            int x=-1;
            for(int k=0;k<g[a[i]].size();k++){
                int v=g[a[i]][k];
                if(d[v]==d[a[i]]-1) x++;
            }
            if(x>0) mx++;
        }
        else mn++,mx++;
    }
    cout<<mn<<" "<<mx;
    return 0;
}