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
int mx[maxn],val[maxn],e1,fa[maxn],tr[maxn][2],rev[maxn];
inline bool isroot(int o){
    return tr[fa[o]][0]!=o&&tr[fa[o]][1]!=o;
}
inline void pushup(int x){
    if(!x) return;
    mx[x]=max(max(mx[tr[x][0]],mx[tr[x][1]]),val[x]);
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
int main(){
    return 0;
}