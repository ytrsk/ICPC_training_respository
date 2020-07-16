#include <bits/stdc++.h>
using namespace std;
const int maxn=500007;
typedef long long ll;
vector<int> g[maxn];
int n,cl,dfn[maxn],low[maxn],cut[maxn];
int e1,head[maxn<<1],to[maxn<<2],nex[maxn<<2];
int dcnt=0;
inline void Addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
inline void Add(int u,int v){
    Addedge(u,v);Addedge(v,u);
}
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
                do{x=S[Top--],Add(n+dcnt,x);} while(x!=v);
            }
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);
    }
    if(!fa&&rc==1) cut[u]=0;
}
void init(){
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=cut[i]=0;
    cl=e1=Top=dcnt=0;
    for(int i=1;i<=2*n;i++) head[i]=0;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int q[maxn<<1],w[maxn<<1],dp[maxn<<1][2],MX,pre[maxn<<1],suf[maxn<<1],top;
void dfs(int u,int fa){
    int sz=0;
    dp[u][0]=dp[u][1]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=fa) dfs(v,u),sz++;
    }
    if(u>n){
        int pos=0;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(v^fa){
                pre[++pos]=(pos+dp[v][0]);
                suf[pos]=(sz-pos+1+dp[v][0]);
                w[pos]=dp[v][0]-pos;
            }
        }
        pre[0]=suf[sz+1]=0;
        for(int i=1;i<=sz;i++) pre[i]=max(pre[i],pre[i-1]);
        for(int i=sz;i;i--) suf[i]=max(suf[i],suf[i+1]);
        int x=max(pre[sz/2],suf[sz/2+1]);
        if(x>dp[fa][0]) dp[fa][1]=dp[fa][0],dp[fa][0]=x;
        else if(x>dp[fa][1]) dp[fa][1]=x;
        w[++pos]=1-pos;
        if(pos==1) return;
        for(int i=pos+1;i<2*pos;i++) w[i]=w[i-pos]-pos;
        int ql=1,qr=0;
        for(int i=1;i<=pos/2;i++){
            while(ql<=qr&&w[q[qr]]<=w[i])  qr--;
            q[++qr]=i; 
        }
        for(int i=pos/2+1;i<=pos/2+pos;i++){
            while(q[ql]<i-pos/2) ql++;
            MX=max(MX,w[i]+2*i+w[q[ql]]-1);
            while(ql<=qr&&w[q[qr]]<=w[i]) qr--;
            q[++qr]=i;
        }
    }
    else{
        MX=max(MX,dp[u][0]+dp[u][1]-1);
    }
}
int main(){
    int m;
	while(scanf("%d%d",&n,&m)==2){
        MX=0;init();
        for(int i=1;i<=m;i++){
            int x=read();
            int last=read();x-=1;
            while(x--){
                int y=read();g[y].push_back(last);
                g[last].push_back(y);last=y;
            }
        }
        
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
        dfs(1,0);
        printf("%d\n",MX-1);
    }
    return 0;
}
/*
15 3
9 1 2 3 4 5 6 7 8 3
7 2 9 10 11 12 13 10
5 2 14 9 15 10
10 1
10 1 2 3 4 5 6 7 8 9 10
*/