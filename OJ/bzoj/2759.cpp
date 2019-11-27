#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef int ll;
#define rint register int
const int maxn=200007;
const int inf=(1LL<<29);
const int mod=10007;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int e1,fa[maxn],tr[maxn][2],rev[maxn];
int A[maxn],B[maxn],Now[maxn],tag[maxn],sz[maxn];
struct node{
    int k,b;
}nd[maxn];
inline bool isroot(int o){
    return tr[fa[o]][0]!=o&&tr[fa[o]][1]!=o;
}
node merge(node a,node b){
    return node{(b.k*a.k)%mod,(b.k*a.b+b.b)%mod};
}
inline void pushup(int x){
    if(!x) return;
    sz[x]=sz[tr[x][0]]+sz[tr[x][1]]+1;
    nd[x]=merge(merge(nd[tr[x][0]],node{A[x],B[x]}),nd[tr[x][1]]);
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

void split(int x){
    access(x);splay(x);
}
int findroot(int x){
    split(x);
    while(pushdown(x),tr[x][0]) x=tr[x][0];
    return x;
}
void cut(int x){
    split(x);
    tr[x][0]=fa[tr[x][0]]=0;pushup(x);
}
void link(int x,int y){
    cut(x);fa[x]=y;
}
void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;return;
	}
	exgcd(b,a%b,y,x);y-=x*(a/b);
}
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int calc(int a,int b,int c){
	if(a==0){
		return b==0?-2:-1;
	}
	int x,y;
	if(b%gcd(a,c)!=0) return -1;
	exgcd(a,c,x,y);x*=b/gcd(a,c);
	int s=c/gcd(a,c);
	return (x%s+s)%s;
}
int dep(int x){
    split(x);return sz[x];
}
int pos[maxn];
void Link(int i,int x){
    if(findroot(x)!=i){
        link(i,x);return;
    }
    split(x);
    //nd[x].k*now+nd[x].b=now %mod
    tag[i]=calc((nd[x].k-1+mod)%mod,(mod-nd[x].b)%mod,mod);
    pos[i]=x; 
}
int query_kth(int o,int x){
    if(!o) return -1;
    pushdown(o);
    if(sz[tr[o][0]]+1==x) return o;
    else if(sz[tr[o][0]]>=x) return query_kth(tr[o][0],x);
    else return query_kth(tr[o][1],x-sz[tr[o][0]]-1);
}
int tmp[maxn];
int main(){
    nd[0].k=1;
    int n=read();
    for(int i=1;i<=n;i++){
        sz[i]=1;
        A[i]=read();tmp[i]=read();B[i]=read();
        A[i]%=mod;B[i]%=mod;
        nd[i]=node{A[i],B[i]};
    }
    for(int i=1;i<=n;i++){
        Link(i,tmp[i]);
    }
    int T=read();
    while(T--){
        char s[20];scanf("%s",s+1);
        if(s[1]=='A'){
            int x=read();
            int y=findroot(x);
            if(tag[y]==-1||tag[y]==-2) printf("%d\n",tag[y]);
            else printf("%d\n",(nd[x].k*tag[y]+nd[x].b)%mod);
        }
        else{
            int x=read(),K=read(),p=read(),b=read();
            splay(x);A[x]=K;B[x]=b;pushup(x);
            int y=findroot(x);
            int r=dep(x);
            if(dep(x)>dep(pos[y])||(split(pos[y]),query_kth(pos[y],r)!=x)){
                split(x);
                cut(x);
                Link(x,p);
            }
            else{
                if(x!=y){
                    cut(x);
                    link(y,pos[y]);
                    Link(x,p);
                }
                else{
                    Link(x,p);
                }
            }
        }
    }
    return 0;
}