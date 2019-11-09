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
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int ans[maxn];
struct Query{
    int l,r,x,pos;
    Query(int l=0,int r=0,int x=0,int pos=0):l(l),r(r),x(x),pos(pos){}
}q[maxn],qL[maxn],qR[maxn];
struct node{
    int x,pos;
    node(int x=0,int pos=0):x(x),pos(pos){}
}num[maxn],numL[maxn],numR[maxn];
int n,v[maxn];
void add(int o,int x){
    for(int i=o;i<=n;i+=lowbit(i)) v[i]+=x;
}
int query(int o){
    int x=0;
    for(int i=o;i;i-=lowbit(i)) x+=v[i];
    return x;
}
inline void solve(int l,int r,int ql,int qr,int nl,int nr){
   // cout<<q.size()<<endl;
    if(l==r){
        for(int i=ql;i<=qr;i++){
            ans[q[i].pos]=l;
        }
        return;
    }
    int m=(l+r)>>1;
    int qst=ql,qed=qr,nst=nl,ned=nr;
    for(int i=nl;i<=nr;i++){
        if(num[i].x<=m) numL[nst++]=num[i],add(num[i].pos,1);
        else numR[ned--]=num[i];
    }
    for(int i=ql;i<=qr;i++){
        int x=query(q[i].r)-query(q[i].l-1);
        if(q[i].x<=x){
            qL[qst++]=q[i];
        }
        else q[i].x-=x,qR[qed--]=q[i];
    }
    for(int i=nl;i<nst;i++){
        add(numL[i].pos,-1);
    }
    for(int i=ql;i<qst;i++) q[i]=qL[i];
    for(int i=qst;i<=qr;i++) q[i]=qR[i];
    for(int i=nl;i<nst;i++) num[i]=numL[i];
    for(int i=nst;i<=nr;i++) num[i]=numR[i];
    if(qst!=ql) solve(l,m,ql,qst-1,nl,nst-1);
    if(qed!=qr) solve(m+1,r,qst,qr,nst,nr);
}
int main(){
   // freopen("test.in","r",stdin);
 //   freopen("my.out","w",stdout);
    n=read();int m=read();
    for(int i=1;i<=n;i++) num[i]=node(read(),i);
    for(int i=1;i<=m;i++){
        int l=read(),r=read(),x=read();
        q[i]=Query(l,r,x,i);
    }
    solve(-1e9,1e9,1,m,1,n);
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
