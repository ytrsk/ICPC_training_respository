#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int mod=1e9+7;
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
int rt,e1,sz[maxn],tr[maxn][2],p[maxn][2],pe1,tmp[maxn];
int px[maxn][2],py[maxn][2],tag[maxn],val[maxn];
bool cmpx(int x,int y){
    if(p[x][0]!=p[y][0]) return p[x][0]<p[y][0];
    else return p[x][1]<p[y][1];
}
bool cmpy(int x,int y){
    if(p[x][1]!=p[y][1]) return p[x][1]<p[y][1];
    else return p[x][0]<p[y][0];
}
int newnode(int x,int y,int v){
    ++e1;sz[e1]=1;p[e1][0]=x;p[e1][1]=y;
    px[e1][0]=px[e1][1]=x;py[e1][0]=py[e1][1]=y;
    tag[e1]=0;val[e1]=v;tr[e1][0]=tr[e1][1]=0;
    return e1;
}
void col(int o,int x){
    if(!o) return;
    tag[o]=val[o]=x;
}
void pushdown(int o){
    if(tag[o]){
        col(tr[o][0],tag[o]);col(tr[o][1],tag[o]);
        tag[o]=0;
    }
}
void pushup(int o){
    sz[o]=sz[tr[o][0]]+sz[tr[o][1]]+1;
    px[o][0]=min(p[o][0],min(px[tr[o][0]][0],px[tr[o][1]][0]));
    px[o][1]=max(p[o][0],max(px[tr[o][0]][1],px[tr[o][1]][1]));
    py[o][0]=min(p[o][1],min(py[tr[o][0]][0],py[tr[o][1]][0]));
    py[o][1]=max(p[o][1],max(py[tr[o][0]][1],py[tr[o][1]][1]));
}
void build(int &o,int l,int r,int op){
    if(l>r) return;
    int mid=(l+r)>>1;
    nth_element(tmp+l,tmp+mid,tmp+r+1,op?cmpy:cmpx);
    o=tmp[mid];tr[o][0]=tr[o][1]=0;
    build(tr[o][0],l,mid-1,!op);
    build(tr[o][1],mid+1,r,!op);
    pushup(o);
}
void dfs(int o){
    if(!o) return;
    pushdown(o);
    dfs(tr[o][0]);tmp[++pe1]=o;dfs(tr[o][1]);
}
void sheep(int &o,int op){
    if(max(sz[tr[o][0]],sz[tr[o][1]])>sz[o]*0.85){
        pe1=0;dfs(o);build(o,1,pe1,op);
    }
}
void ins(int &o,int now,int op){
    if(!o){o=now;return;}
    sheep(o,op);pushdown(o);
    ins(tr[o][op?(!cmpy(now,o)):(!cmpx(now,o))],now,!op);
    pushup(o);
}
void update(int o,int lx,int ly,int rx,int ry,int x){
    if(!o) return;
   // printf("%d %d %d %d %d %d %d %d %d %d %d\n",p[o][0],p[o][1],px[o][0],px[o][1],py[o][0],py[o][1],lx,ly,rx,ry,o);
    if(lx<=px[o][0]&&px[o][1]<=rx&&ly<=py[o][0]&&py[o][1]<=ry){
        col(o,x);return;
    }
    pushdown(o);
    if(rx<px[o][0]||lx>px[o][1]||ry<py[o][0]||ly>py[o][1]){
        return;
    }
    if(lx<=p[o][0]&&p[o][0]<=rx&&ly<=p[o][1]&&p[o][1]<=ry)
    val[o]=x;
    update(tr[o][0],lx,ly,rx,ry,x);
    update(tr[o][1],lx,ly,rx,ry,x);
    pushup(o);
}
int cnt;
void query(int o,int lx,int ly,int rx,int ry){
    if(!o) return;
 //   printf("%d %d %d %d %d %d %d %d %d %d %d\n",p[o][0],p[o][1],px[o][0],px[o][1],py[o][0],py[o][1],lx,ly,rx,ry,o);
    if(lx<=px[o][0]&&px[o][1]<=rx&&ly<=py[o][0]&&py[o][1]<=ry){
        cnt=val[o];return;
    }
    pushdown(o);
    if(rx<px[o][0]||lx>px[o][1]||ry<py[o][0]||ly>py[o][1])
    return;
    if(lx<=p[o][0]&&p[o][0]<=rx&&ly<=p[o][1]&&p[o][1]<=ry)
    cnt=val[o];
    query(tr[o][0],lx,ly,rx,ry);
    query(tr[o][1],lx,ly,rx,ry);
}
void init(){
    e1=rt=0;px[0][0]=py[0][0]=inf;px[0][1]=py[0][1]=-inf;
}
int d[maxn];
vector<int> g[maxn];
int cl,L[maxn],R[maxn];
void DFS(int u){
    L[u]=++cl;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        d[v]=d[u]+1;DFS(v);
    }
    R[u]=cl;
}
int main(){
    int T=read();
    while(T--){
        init();
        int n=read(),c=read(),m=read();
        cl=0;for(int i=1;i<=n;i++) g[i].clear();
        for(int i=2;i<=n;i++){
            int u=read();g[u].push_back(i);
        }
        d[1]=1;DFS(1);
        for(int i=1;i<=n;i++) ins(rt,newnode(L[i],d[i],1),0);
        int ans=0;
        for(int i=1;i<=m;i++){
            int u=read(),l=read(),C=read();
            cnt=0;
            if(C) update(rt,L[u],d[u],R[u],d[u]+l,C);
            else{
                query(rt,L[u],d[u],R[u],d[u]);
            }
            ans=(ans+1LL*i*cnt)%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
