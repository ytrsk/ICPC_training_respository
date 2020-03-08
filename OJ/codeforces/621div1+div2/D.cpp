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
ll d[maxn];
int vis[maxn],n;
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],w[maxn<<1];
void addedge(int u,int v,int x){
    ++e1;
    nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
inline void dijkstra(int s){
    for(int i=1;i<=n;++i) d[i]=inf,vis[i]=0;
    priority_queue<pair<ll,int>> q;d[s]=0;q.push(mp(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(d[v]>d[u]+w[i]){
                d[v]=d[u]+w[i];
                q.push(mp(-d[v],v));
            }
        }
    }
}
int pos[maxn];
ll ds[maxn];
bool cmp(int x,int y){
    return ds[x]<ds[y];
}
int pre[maxn];
int main(){
    n=read();int m=read();int sp=read();
    for(int i=1;i<=sp;i++) pos[i]=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        addedge(u,v,1);addedge(v,u,1);
    }
    dijkstra(1);
    for(int i=1;i<=n;i++) ds[i]=d[i];
    dijkstra(n);
    sort(pos+1,pos+sp+1,cmp);
    pre[sp+1]=-inf;
    for(int i=sp;i;i--){
        pre[i]=max(pre[i+1],(int)d[pos[i]]);
    }
    int ans=0;
    for(int i=1;i<sp;i++) ans=max(ans,(int)ds[pos[i]]+pre[i+1]+1);
    cout<<min(ans,(int)d[1]);
    return 0;
}