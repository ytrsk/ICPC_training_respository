#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100007;
int val[maxn],sz[maxn],ans,e1,num[maxn],rt,fa[maxn],tr[maxn][2],a[maxn],rev[maxn];
void pushup(int x){
    if(!x) return;
    sz[x]=sz[tr[x][0]]+sz[tr[x][1]]+1;
}
void re(int o){
    if(!o) return;
    rev[o]^=1;swap(tr[o][0],tr[o][1]);
}
void pushdown(int x){
    if(!x) return;
    if(rev[x]){
        re(tr[x][0]);re(tr[x][1]);
        rev[x]=0;
    }
}
void rotate(int x,int &o){
    int y=fa[x],z=fa[y],l=(tr[y][1]==x),r=l^1;
    pushdown(y);pushdown(x);
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
    pushdown(o);while(o&&num[o]!=x) o=tr[o][num[o]<x],pushdown(o);
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
void del(int x){
    if(!x) return;
    splay(x,rt);pushdown(x);
    if(1LL*tr[x][0]*tr[x][1]==0) rt=tr[x][0]+tr[x][1];
    else{
        int y=query_min(tr[x][1]);
        splay(y,rt);
        tr[y][0]=tr[x][0];
        fa[tr[x][0]]=y;
    }
    fa[rt]=0;pushup(rt);
}
void ins(int &o,int p,int x){
    if(!o){
        o=++e1;num[o]=x;fa[o]=p;splay(o,rt);return;
    }
    if(x<num[o]) ins(tr[o][0],o,x);else ins(tr[o][1],o,x);
    pushup(o);
}
int query_pre(int x){
    x=tr[x][0];pushdown(x);
    while(tr[x][1]) x=tr[x][1],pushdown(x);
    return x;
}
int query_sub(int x){
    x=tr[x][1];pushdown(x);
    while(tr[x][0]) x=tr[x][0],pushdown(x);
    return x;
}
void build(int &o,int l,int r,int p){
    //printf("%d %d\n",o,p);
    if(l>r) return;
    int m=(l+r)>>1;
    o=m;fa[o]=p;sz[o]=1;tr[o][0]=tr[o][1]=0;
    build(tr[o][0],l,m-1,o);build(tr[o][1],m+1,r,o);
    pushup(o);
}
int query_kth(int o,int x){
    if(!o) return -1;
    pushdown(o);
    if(sz[tr[o][0]]+1==x) return o;
    else if(sz[tr[o][0]]>=x) return query_kth(tr[o][0],x);
    else return query_kth(tr[o][1],x-sz[tr[o][0]]-1);
}
int split(int a,int b){
    a=query_kth(rt,a);b=query_kth(rt,b+2);
    splay(a,rt);splay(b,tr[rt][1]);
    int x=tr[b][0];tr[b][0]=0;fa[x]=0;
    pushup(b);pushup(a);
    return x;
}
void rever(int a,int b){
    a=query_kth(rt,a);b=query_kth(rt,b+2);
    splay(a,rt);splay(b,tr[rt][1]);
    int x=tr[b][0];pushdown(x);
    re(x);pushup(b);pushup(a);
}
void dfs(int o){
    if(!o) return;
    pushdown(o);
    dfs(tr[o][0]);printf("%d ",num[o]);dfs(tr[o][1]);
}
int main(){
    return 0;
}
