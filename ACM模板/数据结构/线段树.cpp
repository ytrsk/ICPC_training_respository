#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],tag[maxn<<2],mx[maxn<<2];
void pushup(int o){
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void pushdown(int o){
    if(tag[o]!=0){
        mx[o<<1]+=tag[o];mx[o<<1|1]+=tag[o];
        tag[o<<1]+=tag[o];tag[o<<1|1]+=tag[o];
        tag[o]=0;
    }
}
void build(int o,int l,int r){
    tag[o]=0;
    if(l==r){
        mx[o]=a[l];return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);build(o<<1|1,m+1,r);
    pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr) return mx[o];
    pushdown(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return max(query(o<<1,l,m,ql,m),query(o<<1|1,m+1,r,m+1,qr));
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr); 
}
void update(int o,int l,int r,int ql,int qr,int x){
    if(l==ql&&r==qr){
        mx[o]+=x;tag[o]+=x;return;
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m,x),update(o<<1|1,m+1,r,m+1,qr,x);
    else if(ql<=m) update(o<<1,l,m,ql,qr,x);
    else update(o<<1|1,m+1,r,ql,qr,x);
    pushup(o);
}
int main(){
    
    return 0;
}