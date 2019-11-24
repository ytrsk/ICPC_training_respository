#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
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
int e1,n,head[maxn],to[maxn<<1],nex[maxn<<1],son[maxn],sz[maxn],num[maxn],a[maxn];
vector<pii> g[maxn];
int ans[maxn];
void dfs1(int u,int fa){
    son[u]=0;sz[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs1(v,u);sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
int sum[maxn<<2];
int query(int o,int l,int r,int x){
    if(l==r) return l>=x?sum[o]:0;
    int m=(l+r)>>1;
    if(x<=m) return sum[o<<1|1]+query(o<<1,l,m,x);
    else return query(o<<1|1,m+1,r,x);
}
void update(int o,int l,int r,int x,int y){
    if(l==r){
        sum[o]+=y;return;
    }
    int m=(l+r)>>1;
    if(x<=m) update(o<<1,l,m,x,y);
    else update(o<<1|1,m+1,r,x,y);
    sum[o]=sum[o<<1]+sum[o<<1|1];
}
void add(int x,int y){
    if(num[x]) update(1,1,n,num[x],-1);
    num[x]+=y;
    if(num[x]) update(1,1,n,num[x],1);
}
void push(int u,int fa){
    add(a[u],1);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=fa){
            push(v,u);
        }
    }
}
void pop(int u,int fa){
    add(a[u],-1);
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
    add(a[u],1);
    for(int i=0;i<g[u].size();i++) ans[g[u][i].second]=query(1,1,n,g[u][i].first);
    if(!kp) pop(u,fa);
}
void init(){
    e1=0;for(int i=1;i<=n;i++) head[i]=0;
}
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int main(){
  //  cin.tie(0);ios_base::sync_with_stdio(false);
    n=read();int m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    for(int i=1;i<=m;i++){
        int u=read(),x=read();g[u].push_back(mp(x,i));
    }
    dfs1(1,0);dfs2(1,0,0);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}
