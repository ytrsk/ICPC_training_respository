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
int e1,n,head[maxn],to[maxn<<1],nex[maxn<<1],son[maxn],sz[maxn],num[maxn],a[maxn],mx;
ll sum,ans[maxn];
void dfs1(int u,int fa){
    son[u]=0;sz[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs1(v,u);sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void add(int x){
    num[x]++;
    if(num[x]>mx) mx=num[x],sum=x;
    else if(num[x]==mx) sum+=x;
}
void push(int u,int fa){
    add(a[u]);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=fa){
            push(v,u);
        }
    }
}
void pop(int u,int fa){
    num[a[u]]--;
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
    add(a[u]);ans[u]=sum;
    if(!kp) sum=mx=0,pop(u,fa);
}
void init(){
    e1=0;for(int i=1;i<=n;i++) head[i]=0;
}
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int main(){
  //  cin.tie(0);ios_base::sync_with_stdio(false);
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs1(1,0);dfs2(1,0,0);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    return 0;
}
