#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int B[maxn],fac[maxn];
set<int> s[maxn];
vector<int> g[maxn];
const int mod=1e9+7;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        b>>=1;
        a=(1LL*a*a)%mod;
    }
    return ans;
}
void add(int &x,int y){
    x+=y;if(x>=mod) x-=mod;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
struct Splay{
    int val[maxn],sz[maxn],e1,fa[maxn],tr[maxn][2],a[maxn],rev[maxn],rt[maxn];
    void init(int n){
        for(int i=1;i<=n;i++) rt[i]=0;
        e1=0;
    }
    void pushup(int x){
        if(!x) return;
        sz[x]=sz[tr[x][0]]+sz[tr[x][1]]+1;
    }
    void rotate(int x,int &o){
        int y=fa[x],z=fa[y],l=(tr[y][1]==x),r=l^1;
        if(y==o) o=x;
        else tr[z][tr[z][1]==y]=x;
        fa[x]=z;fa[y]=x;fa[tr[x][r]]=y;
        tr[y][l]=tr[x][r];tr[x][r]=y;
        pushup(y);pushup(x);
    }
    void splay(int x,int &o){
        int y,z;
        while(x!=o){
            y=fa[x],z=fa[y];
            if(y!=o){
                if(tr[y][0]==x^tr[z][0]==y) rotate(x,o);
                else rotate(y,o);
            }
            rotate(x,o);
        }
    }
    int find(int o,int x){
        while(o&&val[o]!=x) o=tr[o][val[o]<x];
        return o;
    }
    int query_min(int o){
       while(tr[o][0]) o=tr[o][0];
        return o;
    }
    void del(int x,int &rt){
        if(!x) return;
        splay(x,rt);
        if(1LL*tr[x][0]*tr[x][1]==0) rt=tr[x][0]+tr[x][1];
        else{
            int y=query_min(tr[x][1]);
            splay(y,rt);
            tr[y][0]=tr[x][0];
            fa[tr[x][0]]=y;
        }
        fa[rt]=0;pushup(rt);
    }
    void ins(int &o,int p,int x,int &rt){
        if(!o){
            o=++e1;val[o]=x;fa[o]=p;tr[o][0]=tr[o][1]=0;sz[o]=1;
            splay(o,rt);return;
        }
        ins(tr[o][x>val[o]],o,x,rt);
        pushup(o);
    }
    int query(int o,int x){
        if(!o) return 0;
        if(val[o]<x) return sz[tr[o][0]]+1+query(tr[o][1],x);
        else return query(tr[o][0],x);
    }
}S;
int pre=1;
int step,ans,f[maxn];
int inv(int x) {return pown(x,mod-2);}
bool COL(int u,int fa,int up){
    step++;int now=mul(up,f[u]);
    int len=S.sz[S.rt[u]];
    for(int i=1;i<=len;i++){
        int v=B[step];
        int x=S.find(S.rt[u],B[step]);
        if(x){
            S.splay(x,S.rt[u]);int num=S.sz[S.tr[x][0]];
            S.del(x,S.rt[u]);
            now=mul(now,mul(inv(S.sz[S.rt[u]]+1),inv(f[v])));
            add(ans,mul(up,mul(now,mul(f[v],num))));
            if(!COL(v,u,now)) return false;
        }
        else{
            int num=S.query(S.rt[u],B[step]);
            now=mul(now,mul(inv(S.sz[S.rt[u]]),num));
            add(ans,mul(up,mul(now,num)));
            return false;
        }
    }
    return true;
}
void DFS(int u,int fa){
    f[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        DFS(v,u);
        S.ins(S.rt[u],0,v,S.rt[u]);
        f[u]=mul(f[u],f[v]);
    }
    f[u]=mul(fac[S.sz[S.rt[u]]],f[u]);
}
int main(){
    fac[0]=1;
    for(int i=1;i<=1000000;i++) fac[i]=(1LL*fac[i-1]*i)%mod;
    int T=read();
    while(T--){
        ans=step=0;step=1;
        int n=read();S.init(n);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++) B[i]=read();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        DFS(B[1],0);
        for(int i=1;i<B[1];i++) add(ans,mul(f[B[1]],mul(inv(g[B[1]].size()),g[i].size())));
        COL(B[1],0,1);
        printf("%d\n",ans);
    }
    return 0;
}