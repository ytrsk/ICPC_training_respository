#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=1700007;
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
int rt[maxn],val[maxn],sz[maxn],e1,fa[maxn],tr[maxn][2],a[maxn],rev[maxn];
void pushup(int x){
    if(!x) return;
    sz[x]=sz[tr[x][0]]+sz[tr[x][1]]+1;
}
void re(int o){
    if(!o) return;
    rev[o]^=1;swap(tr[o][0],tr[o][1]);
}
void pushdown(int o){
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
    pushdown(o);while(o&&val[o]!=x) o=tr[o][val[o]<x],pushdown(o);
    return o;
}
int query_min(int o){
    pushdown(o);while(tr[o][0]) o=tr[o][0],pushdown(o);
    return o;
}
int query_max(int o){
    pushdown(o);while(tr[o][1]) o=tr[o][1],pushdown(o);
    return o;
}
void ins(int &o,int p,int x,int &rt){
    if(!o){
        o=++e1;val[o]=x;fa[o]=p;tr[o][0]=tr[o][1]=0;sz[o]=1;
        splay(o,rt);return;
    }
    ins(tr[o][x>val[o]],o,x,rt);
    pushup(o);
}
int query_Pre(int o,int x){
    pushdown(o);
    if(!o) return -1;
    if(val[o]==x) return o;
    else if(val[o]<x){
        int y=query_Pre(tr[o][1],x);
        if(~y) return y;
        else return o;
    }
    else return query_Pre(tr[o][0],x);
}
int query_Sub(int o,int x){
    pushdown(o);
    if(!o) return -1;
    if(val[o]==x) return o;
    else if(val[o]>x){
        int y=query_Sub(tr[o][0],x);
        if(~y) return y;
        else return o;
    }
    else return query_Sub(tr[o][1],x);
}
int query_pre(int o){
    pushdown(o);return query_max(tr[o][0]);
}
int query_sub(int o){
    pushdown(o);return query_min(tr[o][1]);
}
void build(int &o,int l,int r,int p){
    if(l>r) return;
    int m=(l+r)>>1;
    o=m;fa[o]=p;tr[o][0]=tr[o][1]=0;
    build(tr[o][0],l,m-1,o);build(tr[o][1],m+1,r,o);
    pushup(o);
}


struct node{
    ll l, r;
    mutable ll v;
    node(ll l, ll r, ll v) : l(l), r(r), v(v) {}
    bool operator<(const node &o) const { return l < o.l; }
};
set<node> tree;
auto split(ll pos){
    auto it = tree.lower_bound(node(pos, 0, 0));
    if (it != tree.end() && it->l == pos)
        return it;
    it--;
    ll l = it->l, r = it->r, v = it->v;
    tree.erase(it);
    tree.insert(node(l, pos - 1, v));
    return tree.insert(node(pos, r, v)).first;
}
void assign(int l, int r, int v){
    auto end = split(r + 1), it = split(l), begin = it;
    for (it; it != end; it++){
        if((it->v)^v){
            int x=(it->v);
            int o1=query_Pre(rt[x],(it->l)-1),o2=query_Sub(rt[x],(it->r)+1);
            splay(o1,rt[x]);splay(o2,tr[rt[x]][1]);
            int y=tr[o2][0];tr[o2][0]=0;fa[y]=0;
            ;pushup(o2);pushup(o1);
            int o3=query_Pre(rt[v],(it->l)-1),o4=query_Sub(rt[v],(it->r)+1);
            splay(o3,rt[v]);splay(o4,tr[rt[v]][1]);
            tr[o4][0]=y;fa[y]=o4;
            pushup(o4);pushup(o3);
        }
    }
    tree.erase(begin, end);
    tree.insert(node(l, r, v));
}
int ans[maxn],n;
void dfs(int o,int x){
    if(!o) return;
    //printf("%d\n",o);
    if(val[o]>=1&&val[o]<=n) ans[val[o]]=x;
    pushdown(o);
    dfs(tr[o][0],x);dfs(tr[o][1],x);
}
int main(){
    n=read();
    for(int i=1;i<=300000;i++) ins(rt[i],0,0,rt[i]),ins(rt[i],0,n+1,rt[i]);
    for(int i=1;i<=n;i++) a[i]=read(),tree.insert(node(i,i,a[i])),ins(rt[a[i]],0,i,rt[a[i]]);
    int m=read();
    for(int i=1;i<=m;i++){
        int x=read();
        if(sz[rt[x]]==2) continue;
        else{
            int X=query_Sub(rt[x],1),Y=query_Pre(rt[x],n);
            assign(val[X],val[Y],x);
        }
    }
    for(int i=1;i<=300000;i++){
        dfs(rt[i],i);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
