#include <bits/stdc++.h>
using namespace std;
const int maxn=100007;
typedef long long ll;
vector<int> g[maxn];
int n,cl,dfn[maxn],low[maxn],cut[maxn];
int e1,head[maxn<<1],to[maxn<<2],nex[maxn<<2];
int dcnt=0;
const int inf=0x3f3f3f3f;
inline void Addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
inline void Add(int u,int v){
    Addedge(u,v);Addedge(v,u);
}
inline void Add(int u,int v)
int S[maxn],Top;
void tarjan(int u,int fa){
    int rc=0;
    dfn[u]=low[u]=++cl;S[++Top]=u;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!dfn[v]){
            rc++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                dcnt++;cut[u]=1;int x;
                Add(n+dcnt,u);
                do{x=S[Top--],Add(n+dcnt,x);} while(x^v);
            }
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);
    }
    if(!fa&&rc==1) cut[u]=0;
}
int dp[maxn][2],w[maxn],top,you[2][2],Nex[2][2];
void dfs(int u,int fa){
    if(u<=n) dp[u][0]=0,dp[u][1]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];if(v^fa) dfs(v,u);
    }
    if(u>n){
        top=0;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(v^fa){
                w[++top]=v;
            }
        }
        if(top==1) return;
        you[1][1]=dp[fa][1];
        you[0][0]=dp[fa][0];
        you[0][1]=you[1][0]=-inf;
        for(int k=1;k<=top;k++){
            Nex[0][0]=max(you[0][0],you[0][1])+dp[w[k]][0];
            Nex[0][1]=you[0][0]+dp[w[k]][1];
            Nex[1][0]=max(you[1][0],you[1][1])+dp[w[k]][0];
            Nex[1][1]=you[1][0]+dp[w[k]][1];
            memcpy(you,Nex,sizeof(Nex));
        }
        dp[fa][0]=max(you[0][0],you[0][1]);
        dp[fa][1]=you[1][0];
    }
}
void init(){
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=cut[i]=0;
    dcnt=cl=e1=Top=0;
    for(int i=1;i<=2*n;i++) head[i]=0;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
	n=read();int m=read();init();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        g[u].push_back(v);g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1]);
    return 0;
}
