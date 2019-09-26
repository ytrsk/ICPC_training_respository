#include <bits/stdc++.h>
#define make_pair mp
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int maxn=100007;
const int inf=(1LL<<29);
int ans,e1,rt,totn,val[4],dep[maxn],w[maxn<<1],f[maxn],head[maxn],to[maxn<<1],nex[maxn<<1],sz[maxn];
bool vis[maxn];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void getrt(int u,int fa){
    sz[u]=1;f[u]=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v!=fa&&!vis[v]){
            getrt(v,u);sz[u]+=sz[v];f[u]=max(f[u],sz[v]);
        }
    }
    f[u]=max(f[u],totn-sz[u]);
    if(f[u]<f[rt]) rt=u;
}
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
void getdep(int u,int fa){
    val[dep[u]]++;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!vis[v]&&v!=fa){
            dep[v]=(dep[u]+w[i])%3;
            getdep(v,u);
        }
    }
}
int calc(int u,int v){
    for(int i=0;i<3;i++) val[i]=0;
    dep[u]=v;getdep(u,0);
    return val[1]*val[2]*2+val[0]*val[0];
}
void solve(int u){
    ans+=calc(u,0);
    vis[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!vis[v]){
            ans-=calc(v,w[i]);
            rt=0;totn=sz[v];
            getrt(v,0);
            solve(rt);
        }
    }
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v,x;scanf("%d%d%d",&u,&v,&x);
        x%=3;
        addedge(u,v,x);addedge(v,u,x);
    }
    f[0]=totn=n;
    getrt(1,0);
    solve(rt);
    int t=gcd(ans,n*n);
    printf("%d/%d",ans/t,n*n/t);
    return 0;
}
