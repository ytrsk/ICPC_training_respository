#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1LL<<60;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int inq[maxn],head[maxn],to[maxn<<1],nex[maxn<<1];ll w[maxn<<1];
ll d[1<<10][2007];queue<int> q;
int tag[maxn],e1;
void spfa(int S){
    while(!q.empty()){
        int u=q.front();q.pop();inq[u]=0;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(d[S][v]>d[S][u]+w[i]){
                d[S][v]=d[S][u]+w[i];
                if(!inq[v]){
                    inq[v]=1;q.push(v);
                }
            }
        }
    }
}
int n,K;
void init(){
    e1=0;for(int i=1;i<=n;i++) head[i]=0;
    for(int i=0;i<(1<<K);i++)
    for(int k=1;k<=n;k++)
    d[i][k]=inf;
}
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
ll dp[1<<5];
//复杂度为3^n*n+2^n*n*m
int val[maxn];
int main(){
    int N,r,m;
    while(scanf("%d%d%d",&N,&r,&m)==3){
        K=0;n=N+r;
        for(int i=1;i<=n;i++){
            if(i<=N) tag[i]=K++;
            else tag[i]=-1;
        }
        for(int i=1;i<=n;i++) val[i]=read();
        init();
        for(int i=1;i<=m;i++){
            int u=read(),v=read(),x=read();
            addedge(u,v,x);addedge(v,u,x);
        }
        for(int i=1;i<=n;i++) if(~tag[i]) d[1<<tag[i]][i]=0;
        for(int i=1;i<(1<<K);i++){
            for(int k=(i-1)&i;k;k=(k-1)&i){
                for(int z=1;z<=n;z++)
                d[i][z]=min(d[i][z],d[k][z]+d[i^k][z]);
            }
            for(int k=1;k<=n;k++){
                if(d[i][k]!=inf&&!inq[k]) q.push(k),inq[k]=1;
            }
            spfa(i);
        }
        for(int i=1;i<(1<<K);i++){
            dp[i]=inf;
            for(int k=1;k<=n;k++)
            dp[i]=min(dp[i],d[i][k]+val[k]);
        }
        for(int i=1;i<(1<<K);i++){
            for(int k=(i-1)&i;k;k=(k-1)&i){
                dp[i]=min(dp[i],dp[k]+dp[i^k]);
            }
        }
        printf("%lld\n",dp[(1<<K)-1]);
    }    
    return 0;
}