#include <stdio.h>
#include <algorithm>
#include <iostream>
#define make_pair mp
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int maxn=1000007;
int a[maxn],mx[maxn<<2],mn[maxn<<2],cnt[maxn<<2],se[maxn<<2];ll sum[maxn<<2];
void read(int &x){
    x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;
}
char q[67];int top;
void write(ll x){
    if(x==0){
        putchar('0');
    }
    else{
        if(x<0) putchar('-');
        x=x<0?-x:x;
        while(x){
            q[++top]=x%10+'0';x/=10;
        }
        while(top) putchar(q[top--]);
     }
    putchar('\n');
}
void pushup(int o){
    int ls=o<<1,rs=ls|1;
    if(mx[ls]>mx[rs]) mx[o]=mx[ls],cnt[o]=cnt[ls],se[o]=max(mx[rs],se[ls]);
    else if(mx[rs]>mx[ls]) cnt[o]=cnt[rs],mx[o]=mx[rs],se[o]=max(mx[ls],se[rs]);
    else cnt[o]=cnt[ls]+cnt[rs],mx[o]=mx[ls],se[o]=max(se[ls],se[rs]);
    sum[o]=sum[ls]+sum[rs];
}
void Min(int o,int x){
    if(mn[o]!=-1) mn[o]=min(mn[o],x);
    else mn[o]=x;
    if(mx[o]>x){
        sum[o]-=1LL*cnt[o]*(mx[o]-x);mx[o]=x;
    }
}
void pushdown(int o){
    if(mn[o]!=-1){
        Min(o<<1,mn[o]);Min(o<<1|1,mn[o]);mn[o]=-1;
    }
}
void build(int o,int l,int r){
    mn[o]=-1;
    if(l==r){
        sum[o]=mx[o]=a[l];se[o]=-1;cnt[o]=1;return;
    }
    int mid=(l+r)>>1;
    build(o<<1,l,mid);build(o<<1|1,mid+1,r);
    pushup(o);
}
void update(int o,int l,int r,int ql,int qr,int x){
    if(x>=mx[o]) return;
    int m=(l+r)>>1;
    if(l!=r) pushdown(o);
    if(l==ql&&r==qr){
        if(x>se[o]||l==r) Min(o,x);
        else update(o<<1,l,m,ql,m,x),update(o<<1|1,m+1,r,m+1,qr,x),pushup(o);
        return;
    }
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m,x),update(o<<1|1,m+1,r,m+1,qr,x);
    else if(ql<=m) update(o<<1,l,m,ql,qr,x);
    else update(o<<1|1,m+1,r,ql,qr,x);
    pushup(o);
}
ll query(int o,int l,int r,int ql,int qr){
    if(l!=r) pushdown(o);
    if(l==ql&&r==qr) return sum[o];
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return query(o<<1,l,m,ql,m)+query(o<<1|1,m+1,r,m+1,qr);
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr);
}
int query_max(int o,int l,int r,int ql,int qr){
    if(l!=r) pushdown(o);
    if(l==ql&&r==qr) return mx[o];
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return max(query_max(o<<1,l,m,ql,m),query_max(o<<1|1,m+1,r,m+1,qr));
    else if(ql<=m) return query_max(o<<1,l,m,ql,qr);
    else return query_max(o<<1|1,m+1,r,ql,qr);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++) read(a[i]);
        build(1,1,n);
        for(int i=1;i<=m;i++){
            int opt;read(opt);int x,y,z;
            read(x);read(y);
            if(opt==0){
                read(z);update(1,1,n,x,y,z);
            }
            else if(opt==1){
                write(query_max(1,1,n,x,y));
            }
            else{
                write(query(1,1,n,x,y));
            }
        }
    }
    return 0;
}
