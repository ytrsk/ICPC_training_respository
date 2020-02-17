#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
#pragma optimize(3)
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
int A[maxn];
int ls[maxn*20*20],rs[maxn*20*20],sum[maxn*20*20],mx[maxn*20*20];
inline void pushup(int o){
    sum[o]=sum[ls[o]]+sum[rs[o]];
    mx[o]=max(mx[ls[o]],mx[rs[o]]);
}
int e1;
inline void update(int &o,int l,int r,int x,int y){
    if(!o) o=++e1;
    if(l==r){
        sum[o]+=y;
        if(sum[o]==0) mx[o]=-1;
        else mx[o]=x;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) update(ls[o],l,m,x,y);
    else update(rs[o],m+1,r,x,y);
    pushup(o); 
}
vector<pii> g;
int rt[maxn<<2];
int aa=0;
inline void del(int o,int l,int r,int x,int opt){   //cout<<o<<" "<<l<<" "<<r<<" "<<sum[o]<<endl;
    if(!o||sum[o]==0) return;
    int m=(l+r)>>1;
    if(opt){
        if(l==r){
            aa+=sum[o];g.push_back(mp(l,-sum[o]));return;
        }
        del(ls[o],l,m,x,1);del(rs[o],m+1,r,x,1);
    }
    else{
        if(l==r) return;
        if(x<=m) del(ls[o],l,m,x,0),del(rs[o],m+1,r,x,1);
        else del(rs[o],m+1,r,x,0);
    }
}
int G[maxn*20];int tG;
inline void modify(int o,int l,int r,int ql,int qr,int x){
    G[++tG]=o;
    if(l==ql&&r==qr){
        int m=(l+r)>>1;
        if(l!=r){
            if(mx[rt[o<<1]]>x) modify(o<<1,l,m,ql,m,x);
            if(mx[rt[o<<1|1]]>x) modify(o<<1|1,m+1,r,m+1,qr,x);
        }
        else{
            aa=0;
            del(rt[o],1,80000,x,0);
            for(int i=0;i<g.size();i++){
                for(int k=1;k<=tG;k++)
                update(rt[G[k]],1,80000,g[i].first,g[i].second);
            }
            for(int i=1;i<=tG;i++){
                update(rt[G[i]],1,80000,x,aa);
            }
            g.clear();
        }
        tG--;
        return;
    }
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) modify(o<<1,l,m,ql,m,x),modify(o<<1|1,m+1,r,m+1,qr,x);
    else if(ql<=m) modify(o<<1,l,m,ql,qr,x);
    else modify(o<<1|1,m+1,r,ql,qr,x);
    tG--;
}
inline void build(int o,int l,int r){
    for(int i=l;i<=r;i++) update(rt[o],1,80000,A[i],1);
    if(l==r) return;
    int m=(l+r)>>1;
    build(o<<1,l,m);build(o<<1|1,m+1,r);
}
vector<int> Q;
inline void query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        Q.push_back(rt[o]);return;
    }
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) query(o<<1,l,m,ql,m),query(o<<1|1,m+1,r,m+1,qr);
    else if(ql<=m) query(o<<1,l,m,ql,qr);
    else query(o<<1|1,m+1,r,ql,qr);
}
inline int qu(int l,int r,int x){
    if(l==r){
        return l;
    }
    int m=(l+r)>>1;int tot=0;
    for(int i=0;i<Q.size();i++) tot+=sum[ls[Q[i]]];
    if(x<=tot){
        for(int i=0;i<Q.size();i++) Q[i]=ls[Q[i]];
        return qu(l,m,x);
    }
    else{
        for(int i=0;i<Q.size();i++) Q[i]=rs[Q[i]];
        return qu(m+1,r,x-tot);
    }
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) A[i]=read();
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int opt=read(),l=read(),r=read(),x=read();
        if(opt==1){
            modify(1,1,n,l,r,min(x,80000));
        }
        else{
            Q.clear();
            query(1,1,n,l,r);
            printf("%d\n",qu(1,80000,x));
        }
    }
    return 0;
}
