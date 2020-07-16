#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=300007;
const ll inf=1LL<<50;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct matrix{
    ll a,b,c,d;
    matrix operator * (matrix now){
        matrix New;
        New.a=max(a+now.a,b+now.c);
        New.b=max(a+now.b,b+now.d);
        New.c=max(c+now.a,d+now.c);
        New.d=max(c+now.b,d+now.d);
        return New;
    }
}opt[maxn<<2];
void pushup(int o){
    opt[o]=opt[o<<1]*opt[o<<1|1];
}
void build(int o,int l,int r){
    if(l==r){
        opt[o].a=0;opt[o].b=-inf;
        return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);build(o<<1|1,m+1,r);
    pushup(o);
}
matrix query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr) return opt[o];
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return query(o<<1,l,m,ql,m)*query(o<<1|1,m+1,r,m+1,qr);
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr); 
}
void update(int o,int l,int r,int x,int y){
    if(l==r){
        opt[o].a=y;opt[o].b=-inf;return;
    }
    int m=(l+r)>>1;
    if(x<=m) update(o<<1,l,m,x,y);
    else update(o<<1|1,m+1,r,x,y);
    pushup(o);
}
int p[maxn],q[maxn],wei[maxn],a[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) p[i]=read(),wei[p[i]]=i;
    for(int i=1;i<=n;i++) q[i]=read();
    build(1,1,n);
    int pos=n;a[wei[n]]=1;update(1,1,n,wei[n],a[wei[n]]);
    for(int i=1;i<=n;i++){
        printf("%d ",pos);
        a[q[i]]--;
        update(1,1,n,q[i],a[q[i]]);
        while(pos>1&&max(opt[1].a,opt[1].c)<=0){
            a[wei[pos-1]]++;
            update(1,1,n,wei[pos-1],a[wei[pos-1]]);
            pos--;
        }
    }
    return 0;
}