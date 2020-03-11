#include <bits/stdc++.h>
using namespace std;
const int maxn=200007;
typedef long long ll;
vector<int> g[maxn];
int n,cl,dfn[maxn],low[maxn];;
int e1,head[maxn],to[maxn<<1],nex[maxn<<1];
int dcnt=0;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
inline void Add(int u,int v){
    addedge(u,v);addedge(v,u);
}
int S[maxn],Top;
void tarjan(int u,int fa){
    dfn[u]=low[u]=++cl;S[++Top]=u;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                dcnt++;int x;
                Add(n+dcnt,u);
                do{x=S[Top--],Add(n+dcnt,x);} while(x!=v);
            }
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);
    }
}
void Init(){
    for(int i=1;i<=2*n;i++) g[i].clear(),dfn[i]=0;
    dcnt=cl=e1=Top=0;
    for(int i=1;i<=2*n;i++) head[i]=0;
}
int st[maxn][20],d[maxn],D[maxn];
int lca(int u,int v){
	if(d[u]<d[v]) swap(u,v);
    int x=d[u]-d[v];
	for(int i=0;(1<<i)<=x;i++) if(x>>i&1) u=st[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;i--) if(st[u][i]!=st[v][i]) u=st[u][i],v=st[v][i];
	return st[u][0];
}
void dfs(int u,int fa){
    dfn[u]=++cl;st[u][0]=fa;d[u]=d[fa]+1;D[u]=D[fa]+(u<=n);
    for(int i=1;i<=19;i++) st[u][i]=st[st[u][i-1]][i-1];
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v!=fa) dfs(v,u);
	}
}
int s[maxn],top;
void Addedge(int u,int v){
    g[u].push_back(v);
}
void init(int x){
    g[x].clear();
}
void ins(int u){
    init(u);
    if(top==1) {if(u>1) s[++top]=u;}
    else{
        int x=lca(u,s[top]);
        if(x^s[top]){
            while(top>1&&dfn[s[top-1]]>=dfn[x]) Addedge(s[top-1],s[top]),top--;
            if(x^s[top]) init(x),Addedge(x,s[top]),s[top]=x;
        }
        s[++top]=u;
    }
}
int you[maxn],Ans=0,TOT,sz[maxn];
int dp(int u){
    int x=you[u];
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        x+=dp(v);
    }
    sz[u]=x;
    if(u<=n&&!you[u]&&(g[u].size()>1||x&&TOT>x)) Ans++;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        int up=TOT-sz[v],down=sz[v];
        if(up&&down) Ans+=D[st[v][0]]-D[u];
    }
    return x;
}
bool cmp(int x,int y){
    return dfn[x]<dfn[y];
}
int a[maxn];
int main(){
    int T=read();
    while(T--){
        n=read();int m=read();Init();
        for(int i=1;i<=m;i++){
            int u=read(),v=read();
            g[u].push_back(v);g[v].push_back(u);
        }
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
        cl=0;
        dfs(1,0);
        int q=read();
        while(q--){
            Ans=0;
            int tot=read();s[top=1]=1;init(1);TOT=tot;
            for(int i=1;i<=tot;i++){
                a[i]=read();you[a[i]]=1;
            }
            sort(a+1,a+tot+1,cmp);
            for(int i=1;i<=tot;i++) ins(a[i]);
            while(top>1) Addedge(s[top-1],s[top]),top--;
            dp(1);
            printf("%d\n",Ans);
            for(int i=1;i<=tot;i++) you[a[i]]=0;
        }
    }
    return 0;
}