#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const double inf=1e9;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const double eps=1e-7;
double w[20][20];
double dp[16][1<<15];
int vis[16][1<<15],n;
bool dfs(int u,int now){
    if(now==(1<<n)-1){
        dp[u][now]=0;return true;
    }
    if(vis[u][now]){
        if(fabs(dp[u][now])<eps) return false;
        else return true;
    }
    vis[u][now]=1;
    int cnt=0;dp[u][now]=0;
    for(int i=0;i<n;i++){
        if(w[u][i]!=-1&&!(now>>i&1)&&dfs(i,now|(1<<i))){
            dp[u][now]+=w[u][i]+dp[i][now|(1<<i)];++cnt;
        }
    }
    if(!cnt) return false;
    dp[u][now]+=5;dp[u][now]/=cnt;
    return true;
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        n=read();int m=read();
        for(int i=0;i<n;i++)
            for(int k=0;k<n;k++)
            w[i][k]=-1;
        for(int i=0;i<(1<<n);i++)
            for(int k=0;k<n;k++)
            vis[k][i]=0;
        for(int i=1;i<=m;i++){
            int u,v;double x;scanf("%d%d%lf",&u,&v,&x);
            w[u][v]=w[v][u]=x;
        }
        dfs(0,1);
        printf("Case %d: %.8f\n",++cnt,dp[0][1]);
    }
    return 0;
}
