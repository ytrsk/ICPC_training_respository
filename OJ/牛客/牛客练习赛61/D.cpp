#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll d[maxn];
int n,e1,head[maxn],to[maxn<<1],nex[maxn<<1],vis[maxn],w[maxn<<1],R[maxn<<1];
void addedge(int u,int v,int x,int r){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;R[e1]=r;
}
ll D[maxn][2];
inline void dijkstra(int s,int opt){
    for(int i=1;i<=n;++i) d[i]=inf,vis[i]=0;
    priority_queue<pair<ll,int>> q;d[s]=0;q.push(mp(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=nex[i]){
            if(R[i]!=opt) continue;
            int v=to[i];
            if(d[v]>d[u]+w[i]){
                d[v]=d[u]+w[i];
                q.push(mp(-d[v],v));
            }
        }
    }
    for(int i=1;i<=n;i++) D[i][opt]=d[i];
}
int U[maxn],V[maxn],W[maxn];
int main(){
    n=read();int m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),x=read();
        addedge(u,v,x,0);
        addedge(v,u,x,1);
        U[i]=u,V[i]=v;W[i]=x;
    }
    dijkstra(1,0);dijkstra(n,1);
    int q=read();
    ll now=D[n][0];
    while(q--){
        int x=read();
        if(D[V[x]][0]!=inf&&D[U[x]][1]!=inf){
            ll zz=D[V[x]][0]+D[U[x]][1]+W[x];
            if(zz<now){
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
}