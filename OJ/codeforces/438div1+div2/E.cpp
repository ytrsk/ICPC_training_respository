#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=51;
const int inf=150007;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
vector<int> g[maxn];
int w[maxn][maxn];
short int sz[maxn];
int dp[maxn][maxn][maxn][maxn];
inline void dfs(int u,int fa){
    for(register int i=0;i<g[u].size();++i){
        int v=g[u][i];
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
inline void solve(int u,int v,int x,int y){
  //  cout<<u<<" "<<v<<" "<<x<<" "<<y<<endl;
    if(dp[u][v][x][y]) return;
    if(x==0&&y==0){
        dp[u][v][x][y]=0;return;
    }
    if(x==0){
        dp[u][v][x][y]=inf;return;
    }
    if(g[v].size()==1){
        solve(v,u,y,0);
        dp[u][v][x][y]=w[u][v]+dp[v][u][y][0];
        return;
    }
    dp[u][v][x][y]=inf;
    register int l=0,r=inf;
    while(l<=r){
        int mid=(l+r)>>1;
        int ok=1,tot=0;
        for(register int i=0;i<g[v].size();++i){
            int e=g[v][i];
            if(e==u) continue;
            int pos=-1;
            register int L=0,R=x;
            while(L<=R){
                int Mid=(L+R)>>1;
                solve(v,e,Mid,x+y-Mid);
                if(dp[v][e][Mid][x+y-Mid]>mid){
                    L=Mid+1;pos=Mid;
                }
                else R=Mid-1;
            }
            if(pos==-1){
                ok=0;break;
            }
            tot+=pos;
        }
        if(ok&&tot>=x) l=mid+1;
        else dp[u][v][x][y]=w[u][v]+mid,r=mid-1;
    }
}
int main(){
   // memset(dp,-1,sizeof(dp));
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read(),x=read();
        g[u].push_back(v);
        g[v].push_back(u);
        w[u][v]=w[v][u]=x;
    }
    if(n==1){
        printf("0");return 0;
    }
    int s=read(),m=read();
    for(register int i=1;i<=m;++i){
        int x=read();sz[x]++;
    }
    dfs(s,0);
    int mn=inf;
    for(register int i=0;i<g[s].size();++i){
        int v=g[s][i];
        solve(s,v,sz[v],m-sz[v]);
        mn=min(mn,dp[s][v][sz[v]][m-sz[v]]);
    }
    cout<<mn;
    return 0;
}
