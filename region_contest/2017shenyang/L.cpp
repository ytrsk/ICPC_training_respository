#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int sum[maxn];
int sz[maxn];
int dp[maxn];
vector<int> g[maxn];
int mx,m,n;
void pre_dfs(int u,int fa){
    dp[u]=0;sz[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        pre_dfs(v,u);
        dp[u]+=dp[v];
        sz[u]+=sz[v];
    }
    dp[u]+=(sz[u]>=m);
}
void dfs(int u,int fa,int last){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        if(sz[v]>=m&&n-sz[v]>=m) mx=max(mx,2);
        int x=1;
        int cnt=n-sz[v]>=m;
        for(int k=0;k<g[v].size();k++){
            if(g[v][k]!=u){
                x+=dp[g[v][k]];
                if(sz[g[v][k]]>=m) cnt++;
            }
        }
        if(n-sz[v]>=m){
            x+=last-dp[v];
        }
        if(cnt>=2) mx=max(mx,x);
        dfs(v,u,x);
    }
}
int main(){
    int t=read();
    while(t--){
        n=read();m=read();
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n<m){
            printf("0\n");continue;
        }
        pre_dfs(1,0);
        int x=0;
        for(int i=0;i<g[1].size();i++)
        x+=sz[g[1][i]]>=m;
        if(x>=2) mx=dp[1];else mx=0;
        dfs(1,0,dp[1]);
        printf("%d\n",max(mx-1,0));
    }

    return 0;
}
