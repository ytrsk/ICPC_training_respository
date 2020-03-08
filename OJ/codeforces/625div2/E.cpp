#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
#define lowbit(x) (x)&(-(x))
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct node{
    ll a,b,c;
    bool operator < (node x) const{
        if(a!=x.a) return a<x.a;
        else return b>x.b;
    }
}A[maxn],B[maxn],C[maxn];
ll val[maxn];
ll tag[maxn<<2],mx[maxn<<2];
void pushdown(int o){
    if(tag[o]){
        mx[o<<1]+=tag[o];mx[o<<1|1]+=tag[o];
        tag[o<<1]+=tag[o];tag[o<<1|1]+=tag[o];
        tag[o]=0;
    }
}
void pushup(int o){
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void build(int o,int l,int r){
    if(l==r){
        mx[o]=val[l];return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    pushup(o);
}

void update(int o,int l,int r,int ql,int qr,int x){
    if(l==ql&&r==qr){
        tag[o]+=x;mx[o]+=x;return;
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m,x),update(o<<1|1,m+1,r,m+1,qr,x);
    else if(ql<=m) update(o<<1,l,m,ql,qr,x);
    else update(o<<1|1,m+1,r,ql,qr,x);
    pushup(o);
}
int main(){
    int n=read(),m=read(),p=read();
    for(int i=1;i<=n;i++) A[i].a=read(),A[i].b=read();
    for(int i=1;i<=m;i++) B[i].a=read(),B[i].b=read();
    for(int i=1;i<=p;i++) C[i].a=read(),C[i].b=read(),C[i].c=read();
    sort(A+1,A+n+1);sort(B+1,B+m+1);sort(C+1,C+p+1);
    memset(val,-0x3f,sizeof(val));
    for(int i=1;i<=m;i++){
        val[B[i].a]=max(val[B[i].a],-B[i].b);
    }
    for(int i=1000000;i;i--) val[i-1]=max(val[i-1],val[i]);
    build(1,1,1000000);
    int now=1;ll ans=-0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++){
        while(now<=p&&A[i].a>C[now].a){
            if(C[now].b<1000000)update(1,1,1000000,C[now].b+1,1000000,C[now].c);
            ++now;
        }
        ans=max(ans,mx[1]-A[i].b);
    }
    cout<<ans;
    return 0;
}