#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=500007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int e1,n,d[maxn],head[maxn],to[maxn<<1],nex[maxn<<1],son[maxn],sz[maxn],a[maxn];
bool ans[maxn],num[maxn][26];
void dfs1(int u,int fa){
    son[u]=0;sz[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;d[v]=d[u]+1;
        dfs1(v,u);sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void add(int x){
    num[d[x]][a[x]]^=1;
}
vector<pii> g[maxn];
void push(int u,int fa){
    add(u);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=fa){
            push(v,u);
        }
    }
}
void pop(int u,int fa){
    add(u);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=fa){
            pop(v,u);
        }
    }
}
void dfs2(int u,int fa,int kp){
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==son[u]||v==fa) continue;
        dfs2(v,u,0);
    }
    if(son[u]) dfs2(son[u],u,1);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==son[u]||v==fa) continue;
        push(v,u);
    }
    add(u);
    for(int i=0;i<g[u].size();i++){
        int cnt=0;
        for(int k=0;k<26;k++) if(num[g[u][i].first][k]) cnt++;
        if(cnt<=1) ans[g[u][i].second]=true;
    }
    if(!kp) pop(u,fa);
}
void init(){
    e1=0;for(int i=1;i<=n;i++) head[i]=0;
}
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
char s[maxn];
int main(){
  //  cin.tie(0);ios_base::sync_with_stdio(false);
    n=read();int m=read();
    for(int i=2;i<=n;i++){
        int x=read();
        addedge(x,i);addedge(i,x);
    }
    scanf("%s",s+1);d[1]=1;
    for(int i=1;i<=n;i++) a[i]=s[i]-'a';
    for(int i=1;i<=m;i++){
        int u=read(),x=read();
        g[u].push_back(mp(x,i));
    }
    dfs1(1,0);dfs2(1,0,0);
    for(int i=1;i<=m;i++) if(ans[i]) printf("Yes\n");
    else printf("No\n");
    return 0;
}