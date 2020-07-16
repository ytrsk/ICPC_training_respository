#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=150007;
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
int pos[maxn],mx[maxn],val[maxn],e1,fa[maxn],tr[maxn][2],rev[maxn];
ll sum[maxn];
inline bool isroot(int o){
    return tr[fa[o]][0]!=o&&tr[fa[o]][1]!=o;
}
inline void pushup(int x){
    if(!x) return;
    if(val[x]>max(mx[tr[x][0]],mx[tr[x][1]])) mx[x]=val[x],pos[x]=x;
    else if(mx[tr[x][0]]>max(val[x],mx[tr[x][1]])) mx[x]=mx[tr[x][0]],pos[x]=pos[tr[x][0]];
    else mx[x]=mx[tr[x][1]],pos[x]=pos[tr[x][1]];
    sum[x]=val[x]+sum[tr[x][0]]+sum[tr[x][1]];
}
inline void re(int o){
    if(!o) return;
    rev[o]^=1;swap(tr[o][0],tr[o][1]);
}
inline void pushdown(int o){
    if(!o) return;
    if(rev[o]){
        re(tr[o][0]);re(tr[o][1]);
        rev[o]=0;
    }
}
inline void rotate(int x){
    int y=fa[x],z=fa[y],l=(tr[y][1]==x),r=l^1;
    if(!isroot(y)) tr[z][tr[z][1]==y]=x;
    fa[x]=z;fa[y]=x;fa[tr[x][r]]=y;
    tr[y][l]=tr[x][r];tr[x][r]=y;
    pushup(y);pushup(x);
}
int top,q[maxn];
inline void splay(int x){
    top=0;q[++top]=x;
    for(int i=x;!isroot(i);i=fa[i]) q[++top]=fa[i];
    while(top) pushdown(q[top--]);
    int y,z;
    while(!isroot(x)){
        y=fa[x],z=fa[y];
        if(!isroot(y)){
            if(tr[y][0]==x^tr[z][0]==y) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}
inline void access(int x){
    for(int y=0;x;y=x,x=fa[x]){
        splay(x);tr[x][1]=y;pushup(x);
    }
}
inline void makeroot(int x){
    access(x);splay(x);re(x);
}
int findroot(int x){
    access(x);splay(x);
    while(pushdown(x),tr[x][0]) x=tr[x][0];
    return x;
}
void link(int x,int y){
    makeroot(x);fa[x]=y;
}
void split(int x,int y){
    makeroot(x);access(y);splay(y);
}
void cut(int x,int y){
    split(x,y);
    tr[y][0]=fa[x]=0;pushup(y);
}
struct edge{
    int u,v,x;
    bool operator < (edge a) const{
        return x<a.x;
    }
}e[maxn];
int p[maxn];
int find(int x){
    return x==p[x]?x:p[x]=find(p[x]);
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=m;i++){
        e[i].u=read();e[i].v=read();e[i].x=read();
    }
    for(int i=1;i<=n;i++) p[i]=i,pos[i]=i;
    sort(e+1,e+m+1);int ans=inf;
    for(int i=1;i<=m;i++){
        mx[n+i]=val[n+i]=e[i].x;pos[n+i]=n+i;
        if(find(e[i].u)==find(e[i].v)){
            split(e[i].u,e[i].v);
            if(mx[e[i].v]>e[i].x){
                int x=pos[e[i].v];
                cut(e[x-n].u,x);
                cut(e[x-n].v,x);
                link(n+i,e[i].u);
                link(n+i,e[i].v);
            }
        }
        else{
            link(n+i,e[i].u);link(n+i,e[i].v);
        }
        p[find(e[i].u)]=find(e[i].v);
        if(find(1)==find(n)){
            split(1,n);
            ans=min(ans,e[i].x+mx[n]);
        }
    }
    if(ans<inf) cout<<ans;
    else cout<<-1;
    return 0;
}
