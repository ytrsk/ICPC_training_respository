#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const ll inf=0x3f3f3f3f3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int Maxn=500007;
int w[maxn<<1],e1,head[maxn],to[maxn<<1],nex[maxn<<1],dfn[maxn],cl,d[maxn],st[Maxn][21],ww[Maxn][21];
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
int lca(int u,int v){
	if(d[u]<d[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(d[st[u][i]]>=d[v]) u=st[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--) if(st[u][i]^st[v][i]) u=st[u][i],v=st[v][i];
	return st[u][0];
}
int lcaw(int u,int v){
	if(d[u]<d[v]) swap(u,v);
    int ans=0x3f3f3f3f; 
	for(int i=20;i>=0;i--) if(d[st[u][i]]>=d[v]) ans=min(ans,ww[u][i]),u=st[u][i];
	if(u==v) return ans;
	for(int i=20;i>=0;i--) if(st[u][i]^st[v][i]) ans=min(ans,min(ww[u][i],ww[v][i])),u=st[u][i],v=st[v][i];
	return min(ans,ww[u][0]);
}
void dfs(int u,int fa){
	st[u][0]=fa;d[u]=d[fa]+1;dfn[u]=++cl;
	for(int i=1;i<=20;i++) st[u][i]=st[st[u][i-1]][i-1],ww[u][i]=min(ww[st[u][i-1]][i-1],ww[u][i-1]);
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v!=fa) ww[v][0]=w[i],dfs(v,u);
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
int Ans;
int you[maxn],sz[maxn],tot;
void dp(int u){
    sz[u]=you[u];
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        dp(v);sz[u]+=sz[v];
        int x=lcaw(u,v);
        int down=sz[v],up=tot-sz[v];
        if(down&&up) Ans=max(Ans,x);
    }
}
bool cmp(int x,int y){
    return dfn[x]<dfn[y];
}
int a[maxn];
int U[maxn],V[maxn],W[maxn],id[maxn];
bool Cmp(int x,int y){
    return W[x]>=W[y];
}
int fa[maxn];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
    int n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        U[i]=read(),V[i]=read(),W[i]=read();id[i]=i;
    }
    sort(id+1,id+m+1,Cmp);
    for(int i=1;i<=m;i++){
        int x=U[id[i]],y=V[id[i]];
        if(find(x)!=find(y)){
            fa[find(x)]=find(y);addedge(x,y,W[id[i]]);addedge(y,x,W[id[i]]);
        }
    }
    dfs(1,0);
    int last=0;
    while(q--){
        tot=read();s[top=1]=1;init(1);
        for(int i=1;i<=tot;i++){
            a[i]=read()^last;you[a[i]]=1;
            assert(a[i]<=n);
        }
        Ans=0;
        sort(a+1,a+tot+1,cmp);
        tot=unique(a+1,a+tot+1)-a-1;
        for(int i=1;i<=tot;i++) ins(a[i]);
        while(top>1) Addedge(s[top-1],s[top]),top--;
        dp(1);last=Ans;
        printf("%lld\n",last);
        for(int i=1;i<=tot;i++) you[a[i]]=0;
    }
    return 0;
}