#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],t1[maxn<<2],t2[maxn<<2],sum[maxn<<2];
const int mod=111546435;
int add(int x,int y){
    return x+y>=mod?x+y-mod:x+y;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
void pushup(int o){
    sum[o]=add(sum[o<<1],sum[o<<1|1]);
}
void Add(int o,int l,int r,int x,int y){
    int N=r-l+1;
    sum[o]=add(sum[o],add(mul(N,x),mul(1LL*N*(N-1)/2%mod,y)));
    t1[o]=add(t1[o],x);
    t2[o]=add(t2[o],y);
}
void pushdown(int o,int l,int r){
    if(t1[o]!=0||t2[o]!=0){
        int m=(l+r)>>1;
        Add(o<<1,l,m,t1[o],t2[o]);
        Add(o<<1|1,m+1,r,add(t1[o],mul(t2[o],m+1-l)),t2[o]);
        t1[o]=0;t2[o]=0;
    }
}
void build(int o,int l,int r){
    if(l==r){
        sum[o]=a[l]%mod;return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);build(o<<1|1,m+1,r);
    pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr) return sum[o];
    pushdown(o,l,r);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return add(query(o<<1,l,m,ql,m),query(o<<1|1,m+1,r,m+1,qr));
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr); 
}
int LL=0;
void update(int o,int l,int r,int ql,int qr,int x,int y){
    if(l==ql&&r==qr){
        Add(o,l,r,add(x,mul(y,l-LL)),y);return;
    }
    pushdown(o,l,r);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m,x,y),update(o<<1|1,m+1,r,m+1,qr,x,y);
    else if(ql<=m) update(o<<1,l,m,ql,qr,x,y);
    else update(o<<1|1,m+1,r,ql,qr,x,y);
    pushup(o);
}

int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,1,n);
    int q=read();
    while(q--){
        int opt=read(),L=read(),R=read(),x=read();LL=L;
        if(opt==1){
            int y=read();
            x%=mod;y%=mod;
            update(1,1,n,L,R,x,y);
        }
        else{
            printf("%d\n",query(1,1,n,L,R)%x);
        }
    }    
    return 0;
}