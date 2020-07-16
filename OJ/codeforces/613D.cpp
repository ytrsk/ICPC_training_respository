#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll dp[maxn][2];
int w[maxn<<1],e1,head[maxn],to[maxn<<1],nex[maxn<<1],dfn[maxn],cl,d[maxn],st[maxn][21];
map<int,int> aa[maxn];
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int lca(int u,int v){
	if(d[u]<d[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(d[st[u][i]]>=d[v]) u=st[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--) if(st[u][i]^st[v][i]) u=st[u][i],v=st[v][i];
	return st[u][0];
}
void dfs(int u,int fa){
	st[u][0]=fa;d[u]=d[fa]+1;dfn[u]=++cl;
	for(int i=1;i<=20;i++) st[u][i]=st[st[u][i-1]][i-1];
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v!=fa) dfs(v,u);
	}
}
int s[maxn],top;
vector<int> g[maxn];
void Addedge(int u,int v){
    g[u].push_back(v);
}
void init(int x){
    g[x].clear();
}
int TOT;
void ins(int u){
    init(u);
    if(top==1) {if(u>1) s[++top]=u;}
    else{
        int x=lca(u,s[top]);
        if(x!=s[top]){
            while(top>1&&dfn[s[top-1]]>=dfn[x]) Addedge(s[top-1],s[top]),top--;
            if(x!=s[top]) init(x),Addedge(x,s[top]),s[top]=x;
        }
        s[++top]=u;
    }
}
int you[maxn],sz[maxn],OK=1;
void DP(int u){
    dp[u][0]=0; dp[u][1]=0;
    if(you[u]) dp[u][1]=inf;
    sz[u]=you[u];int ok=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];DP(v);sz[u]+=sz[v];
        if(d[v]==d[u]+1&&you[v]&&you[u]) OK=0;
        if(sz[v]) ok=1;
    }
    if(sz[u]==0||!ok) return;
    if(you[u]){
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(!sz[v]) continue;
            dp[u][0]+=min(dp[v][1],dp[v][0]+1);
        }
    }
    else{
        ll mn1=inf,sum=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(!sz[v]) continue;
            dp[u][0]+=min(dp[v][0]+1,dp[v][1]);mn1=min(mn1,dp[v][0]-min(dp[v][0]+1,dp[v][1]));
            dp[u][1]+=min(dp[v][1],dp[v][0]+1);
            sum+=dp[v][0];
        }
        dp[u][0]+=mn1;dp[u][0]=min(dp[u][0],sum);dp[u][1]=min(dp[u][1],sum);
    }

}
bool cmp(int x,int y){
    return dfn[x]<dfn[y];
}
int a[maxn];
int main(){
    int n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs(1,0);
    int q=read();
    while(q--){
        OK=1;
        int tot=read();s[top=1]=1;init(1);
        for(int i=1;i<=tot;i++){
            a[i]=read();you[a[i]]=1;
        }
        sort(a+1,a+tot+1,cmp);
        for(int i=1;i<=tot;i++) ins(a[i]);TOT=tot;
        while(top>1) Addedge(s[top-1],s[top]),top--;DP(1);
        printf("%lld\n",OK?dp[1][0]:-1);
        for(int i=1;i<=tot;i++) you[a[i]]=0;
    }
    return 0;
}