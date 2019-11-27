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
int sz[maxn],val[maxn],e1,fa[maxn],tr[maxn][2],rev[maxn],tag[maxn];
struct node{
    ll mx,l,r,sum;
}nd[maxn];
node merge(node a,node b){
    node New;
    New.mx=max(max(a.mx,b.mx),a.r+b.l);
    New.l=max(a.l,a.sum+b.l);
    New.r=max(b.r,b.sum+a.r);
    New.sum=a.sum+b.sum;
    return New; 
}
inline bool isroot(int o){
    return tr[fa[o]][0]!=o&&tr[fa[o]][1]!=o;
}
inline void pushup(int o){
    if(!o) return;
    int x=max(val[o],0);
    sz[o]=sz[tr[o][0]]+1+sz[tr[o][1]];
    nd[o]=merge(merge(nd[tr[o][0]],node{x,x,x,val[o]}),nd[tr[o][1]]);
}
inline void re(int o){
    if(!o) return;
    rev[o]^=1;swap(tr[o][0],tr[o][1]);
    swap(nd[o].l,nd[o].r);
}
inline void change(int o,int x){
    if(!o) return;
    val[o]=tag[o]=x;ll r=max(val[o],0);
    nd[o]=node{r*sz[o],r*sz[o],r*sz[o],1LL*val[o]*sz[o]};
}
inline void pushdown(int o){
    if(!o) return;
    if(rev[o]){
        re(tr[o][0]);re(tr[o][1]);
        rev[o]=0;
    }
    if(tag[o]!=inf){
        change(tr[o][0],tag[o]);change(tr[o][1],tag[o]);
        tag[o]=inf;
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
int main(){
    int n=read();
    for(int i=1;i<=n;i++){
        val[i]=read();int x=max(val[i],0);
        nd[i]=node{x,x,x,val[i]};sz[i]=1;tag[i]=inf;
    }
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        link(u,v);
    }
    int T=read();
    while(T--){
        int opt=read(),u=read(),v=read();
        if(opt==1){
            split(u,v);printf("%lld\n",nd[v].mx);
        }
        else{
            int x=read();
            split(u,v);change(v,x);
        }
    }
    return 0;
}