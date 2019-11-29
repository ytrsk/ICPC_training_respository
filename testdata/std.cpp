#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=998244353;
int c[1007];
int dp[1007][8007];
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
vector<int> g[1007];
int n,m,pre[8007];
void dfs(int u){
    dp[u][c[u]]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];dfs(v);
        for(int k=1;k<=m;k++) pre[k]=dp[u][k];
        for(int k=1;k<=m;k++){
            for(int z=k;z<=m;z+=k){
                add(dp[u][z],mul(pre[z/k],dp[v][k]));
            }
        }
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("std.out","w",stdout);
    n=read();m=read();
    for(int i=2;i<=n;i++){
        int u=read();
        g[u].push_back(i);
    }
    for(int i=1;i<=n;i++) c[i]=read();
    dfs(1);
    for(int i=1;i<=m;i++){
        int sum=0;
        for(int k=1;k<=n;k++)
        add(sum,dp[k][i]);
        printf("%d\n",sum);
    }
    printf("%.5lf\n",1.0*clock()/CLOCKS_PER_SEC);
    return 0;
}