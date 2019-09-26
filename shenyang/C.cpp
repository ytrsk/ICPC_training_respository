#include <bits/stdc++.h>
#define make_pair mp
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int maxn=10007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int ans[3],e1,rt,totn,val[4],dep[maxn],w[maxn<<1],f[maxn],head[maxn],to[maxn<<1],nex[maxn<<1],sz[maxn];
int rr[maxn];
bool vis[maxn];
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
int zz[maxn];
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
void add(int &x,int y){
    (x+=y)%=mod;
}
void getdep(int u,int fa){
    add(val[dep[u]%3],dep[u]);
    add(zz[dep[u]%3],1);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!vis[v]&&v!=fa){
            dep[v]=(dep[u]+w[i])%mod;
            getdep(v,u);
        }
    }
}
void del(int &x,int y){
    x=(0LL+x-y+mod)%mod;
}
void calc(int u,int v){
    for(int i=0;i<3;i++) zz[i]=0,val[i]=0;
    dep[u]=v;getdep(u,0);
    if(v==0){
        for(int i=0;i<3;i++){
            for(int k=i;k<3;k++){
                if(i==k){
                    add(ans[(i+k)%3],(1LL*val[i]*zz[k]%mod+1LL*val[k]*zz[i]%mod)%mod);
                }
                else{
                    add(ans[(i+k)%3],(2LL*val[i]*zz[k]%mod+2LL*val[k]*zz[i]%mod)%mod);
                }
            }
        }
    }
    else{
        for(int i=0;i<3;i++)
        for(int k=i;k<3;k++){
            if(i==k){
                del(ans[(i+k)%3],(1LL*val[i]*zz[k]%mod+1LL*val[k]*zz[i]%mod)%mod);
            }
            else{
                del(ans[(i+k)%3],(2LL*val[i]*zz[k]%mod+2LL*val[k]*zz[i]%mod)%mod);
            }
        }
    }
}
void solve(int u){
    calc(u,0);
    vis[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!vis[v]){
            calc(v,w[i]);
            rt=0;totn=sz[v];
            getrt(v,0);
            solve(rt);
        }
    }
}
int main(){
    int n;
    while(scanf("%d",&n)==1){
        e1=0;for(int i=1;i<=n;i++) head[i]=vis[i]=0;
        for(int i=1;i<n;i++){
            int u,v,x;scanf("%d%d%d",&u,&v,&x);++u;++v;
            addedge(u,v,x);addedge(v,u,x);
        } ans[0]=ans[1]=ans[2]=0;
        f[0]=totn=n;
        getrt(1,0);
        solve(rt);

        printf("%d %d %d\n",ans[0],ans[1],ans[2]);
    }
    return 0;
}
