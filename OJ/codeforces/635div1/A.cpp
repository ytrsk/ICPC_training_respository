#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
vector<int> g[maxn];
int d[maxn],L[maxn],e1,R[maxn],sz[maxn];
void dfs(int u,int fa){
    L[u]=++e1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v^fa){
            d[v]=d[u]+1;dfs(v,u);
        }
    }
    R[u]=e1;sz[u]=R[u]-L[u];
}
int cmp(int a,int b){
    return d[a]-sz[a]>d[b]-sz[b];
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    ll ans=0;
    for(int i=1;i<=n;i++) L[i]=i;
    sort(L+1,L+n+1,cmp);
    for(int i=1;i<=m;i++) ans+=d[L[i]]-sz[L[i]];
    cout<<ans;
    return 0;
}