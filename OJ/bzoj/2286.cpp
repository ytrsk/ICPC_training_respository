#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=250007;
const ll inf=0x3f3f3f3f3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll mn[maxn];
int w[maxn<<1],e1,head[maxn],to[maxn<<1],nex[maxn<<1],dfn[maxn],cl,d[maxn],st[maxn][21];
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
void dfs(int u,int fa){
	st[u][0]=fa;d[u]=d[fa]+1;dfn[u]=++cl;
	for(int i=1;i<=20;i++) st[u][i]=st[st[u][i-1]][i-1];
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v!=fa) mn[v]=min(mn[u],(ll)w[i]),dfs(v,u);
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
    if(top==1) s[++top]=u;
    else{
        int x=lca(u,s[top]);
        if(x^s[top]){
            while(top>1&&dfn[s[top-1]]>=dfn[x]) Addedge(s[top-1],s[top]),top--;
            if(x^s[top]) init(x),Addedge(x,s[top]),s[top]=x;
        }
        s[++top]=u;
    }
}
int you[maxn];
ll dp(int u){
    ll sum=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        sum+=dp(v);
    }
    return you[u]?mn[u]:min(sum,mn[u]);
}
bool cmp(int x,int y){
    return dfn[x]<dfn[y];
}
int a[maxn];
int main(){
    mn[1]=inf;
    int n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read(),x=read();
        addedge(u,v,x);addedge(v,u,x);
    }
    dfs(1,0);
    int q=read();
    while(q--){
        int tot=read();s[top=1]=1;init(1);
        for(int i=1;i<=tot;i++){
            a[i]=read();you[a[i]]=1;
        }
        sort(a+1,a+tot+1,cmp);
        for(int i=1;i<=tot;i++) ins(a[i]);
        while(top>1) Addedge(s[top-1],s[top]),top--;
        printf("%lld\n",dp(1));
        for(int i=1;i<=tot;i++) you[a[i]]=0;
    }
    return 0;
}