#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#define mp make_pair
#define pii pair<int,int>
#define lowbit(x) (x)&(-x)
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
ll read(){
    ll x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int ans[maxn];
struct Query{
    int type,l,r,pos;ll x;
    Query(int type=0,int l=0,int r=0,ll x=0,int pos=0):type(type),l(l),r(r),x(x),pos(pos){}
};
ll tag[maxn<<2],sum[maxn<<2];
void pushup(int o){
    sum[o]=sum[o<<1]+sum[o<<1|1];
}
void add(int o,int l,int r,int x){
    tag[o]+=x;sum[o]+=(r-l+1)*x;
}
void pushdown(int o,int l,int r){
    if(tag[o]){
        int m=(l+r)>>1;
        add(o<<1,l,m,tag[o]);
        add(o<<1|1,m+1,r,tag[o]);
        tag[o]=0;
    }
}
void update(int o,int l,int r,int ql,int qr,int x){
    if(l==ql&&r==qr){
        add(o,l,r,x);return;
    }
    pushdown(o,l,r);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m,x),update(o<<1|1,m+1,r,m+1,qr,x);
    else if(ql<=m) update(o<<1,l,m,ql,qr,x);
    else update(o<<1|1,m+1,r,ql,qr,x);
    pushup(o);
}
ll query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return sum[o];
    }
    pushdown(o,l,r);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return query(o<<1,l,m,ql,m)+query(o<<1|1,m+1,r,m+1,qr);
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr);
}
int n;
inline void solve(int l,int r,vector<Query> q){
    if(l==r){
        for(int i=0;i<q.size();i++){
            if(q[i].type==2)ans[q[i].pos]=l;
        }
        return;
    }
    int m=(l+r)>>1;
    vector<Query> ql,qr;
    for(int i=0;i<q.size();i++){
        if(q[i].type==1){
            if(q[i].x>m){
                qr.push_back(q[i]);update(1,1,n,q[i].l,q[i].r,1);
            }
            else ql.push_back(q[i]);
        }
        else{
            ll x=query(1,1,n,q[i].l,q[i].r);
        //    cout<<x<<endl;
            if(q[i].x>x) q[i].x-=x,ql.push_back(q[i]);
            else qr.push_back(q[i]);
        }
    }
    for(int i=0;i<qr.size();i++){
        if(qr[i].type==1) update(1,1,n,qr[i].l,qr[i].r,-1);
    }
    if(!ql.empty()) solve(l,m,ql);
    if(!qr.empty()) solve(m+1,r,qr);
}
int main(){
    n=read();int m=read();vector<Query> q;int top=0;
    for(int i=1;i<=m;i++){
        int opt=read(),l=read(),r=read();ll x=read();
        if(opt-1) top++;
        q.push_back(Query(opt,l,r,x,top));
    }
    solve(-50000,50000,q);
    for(int i=1;i<=top;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
