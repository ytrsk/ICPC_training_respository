#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100007;
int sz[maxn],ans,e1,num[maxn],rt,fa[maxn],tr[maxn][2],a[maxn],rev[maxn],top,q[maxn],p[maxn];
int find(int x){
    return x==p[x]?x:p[x]=find(p[x]);
}
bool isroot(int o){
    return tr[fa[o]][0]!=o&&tr[fa[o]][1]!=o;
}
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
void rotate(int &x){
    int y=fa[x],z=fa[y],l=(tr[y][1]==x),r=l^1;
    if(!isroot(y)) tr[z][tr[z][1]==y]=x;
    fa[x]=z;fa[y]=x;fa[tr[x][r]]=y;
    tr[y][l]=tr[x][r];tr[x][r]=y;
    pushup(y);pushup(x);
}
void splay(int &x){
    top=0;q[++top]=x;
    for(int i=x;!isroot(i);i=fa[i]) q[++top]=fa[i];
    while(top) pushdown(q[top--]);
    while(!isroot(x)){
        int y=fa[x],z=fa[y];
        if(!isroot(y)){
            if(tr[y][0]==x^tr[z][0]==y) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}
void access(int x){
    for(int y=0;x;y=x,x=fa[x]){
        splay(x);tr[x][1]=y;pushup(x);
    }
}
void makeroot(int x){
    access(x);splay(x);re(x);
}
void link(int x,int y){
    makeroot(x);fa[x]=y;
}
void cut(int x,int y){
    makeroot(x);access(y);splay(y);
    tr[y][0]=fa[x]=0;pushup(y);
}
int query(int x,int y){
    makeroot(x);access(y);splay(y);
    return sz[y];
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;p[x]=i;
        sz[i]=1;if(x) link(i,x);
    }
    for(int i=1;i<=m;i++){
        char s[17];scanf("%s",s+1);
        if(s[1]=='Q'){
            int x;cin>>x;
            query(x,1);
        }
        else if(s[1]=='M'){
            int x,y;cin>>x>>y;
            if(p[x]) cut(x,p[x]);
            if(y) link(x,y),y=p[x];
        }
    }
    return 0;
}
