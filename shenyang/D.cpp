#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int e1,head[maxn],to[maxn<<1],nex[maxn<<1];
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int dfs(int u,int v){
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        dfs(v,u);

    }
}
int f[maxn];
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
vector<int> g[maxn];
int vis[maxn],sz[maxn];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        int n=read(),m=read(),r=read();
        for(int i=1;i<=n;i++) f[i]=i,vis[i]=0,sz[i]=0,g[i].clear();
        for(int i=1;i<=m;i++){
            int u=read(),v=read();
            g[u].push_back(v);g[v].push_back(u);
        }
        e1=0;
        for(int i=1;i<=n;i++) head[i]=0;
        for(int i=1;i<=r;i++){
            int x=read();vis[x]=1;
        }
        for(int i=1;i<=n;i++)
        for(int k=0;k<g[i].size();k++){
            int v=g[i][k];
            if(!vis[i]&&!vis[v]){
                f[find(i)]=find(v);
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]) sz[find(i)]++;
        }
        for(int i=1;i<=n;i++){
            for(int k=0;k<g[i].size();k++){
                int v=g[i][k];
                if(vis[i]+vis[v]){
                    int u=find(i);v=find(v);
                    addedge(u,v);addedge(v,u);
                }
            }
        }
        double mx=0;
        for(int i=head[find(1)];i;i=nex[i]){
            int v=to[i];
            int ans=0,now=0;
            for(int k=head[v];k;k=nex[k]){
                int vv=to[k];
                if(vv!=find(1)){
                    ans+=sz[vv];
                }
                ++now;
            }
            mx=max(mx,ans*1.0/now+sz[find(1)]);
        }
        printf("%.6f\n",mx);
    }
    return 0;
}
