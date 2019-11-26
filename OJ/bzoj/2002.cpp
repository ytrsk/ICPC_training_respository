#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
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
int e1,sz[maxn],fa[maxn],tr[maxn][2],rev[maxn];
inline bool isroot(int o){
    return tr[fa[o]][0]!=o&&tr[fa[o]][1]!=o;
}
inline void pushup(int x){
    if(!x) return;
    sz[x]=sz[tr[x][0]]+sz[tr[x][1]]+1;
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
int findroot(int x){
    access(x);splay(x);
    while(pushdown(x),tr[x][0]) x=tr[x][0];
    return 0;
}
void split(int x){
    access(x);splay(x);
}
void cut(int x){
    split(x);
    tr[x][0]=fa[tr[x][0]]=0;pushup(x);
}
void link(int x,int y){
    cut(x);fa[x]=y;
}
int a[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read(),sz[i]=1;
    for(int i=1;i<=n;i++) if(a[i]+i<=n) link(i,a[i]+i);
    int T=read();
    while(T--){
        int opt=read(),x=read();x++;
        if(opt==1){
            split(x);
            printf("%d\n",sz[x]);
        }
        else{
            int y=read();
            cut(x);if(x+y<=n)link(x,x+y);
        }
    }
    return 0;
}