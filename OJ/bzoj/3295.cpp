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
const int maxn=200007;
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
struct nd{
    int x,y,z,v;
    nd(int x=0,int y=0,int z=0,int v=0):x(x),y(y),z(z),v(v){}
    bool operator < (nd a) const{
        if(x!=a.x) return x<a.x;
        else if(y!=a.y) return y>a.y;
        else return z<a.z;
    }
}p[maxn],pr[maxn];
int a[maxn],v[maxn];
ll ans[maxn];
int n,vis[maxn];
void add(int o,int x){
    for(int i=o;i<=n;i+=lowbit(i)) v[i]+=x;
}
int query(int o){
    int x=0;
    for(int i=o;i;i-=lowbit(i)) x+=v[i];
    return x;
}
//外部排序时如表达式(第一位第二位第三位)出现相等的情况，需要调整cmp，如果全部相等，则需缩点
//内部排序时第二维第三维可随意处理，第一维如出现不等号（但是数据中有第一维相等的情况），需要加上判断条件(只加入不等于的点)
//注意内存
void cdq(int l,int r){
    if(l==r) return;
    int m=(l+r)>>1;
    cdq(l,m);cdq(m+1,r);
    int top=m;
    for(int i=r;i>m;--i){
        while(top>=l&&p[top].y>p[i].y) add(p[top].z,p[top].v),top--;
        ans[p[i].x]+=query(p[i].z-1);
    }
    for(int i=top+1;i<=m;i++) add(p[i].z,-p[i].v);
    top=l;
    for(int i=m+1;i<=r;i++){
        while(top<=m&&p[top].y<p[i].y) add(p[top].z,p[top].v),top++;
        if(p[i].x) ans[p[i].x]+=query(n)-query(p[i].z);
    }
    for(int i=l;i<top;i++) add(p[i].z,-p[i].v);
    top=l;int now=l;
    for(int i=m+1;i<=r;i++){
        while(top<=m&&p[top].y<=p[i].y) pr[now++]=p[top++];
        pr[now++]=p[i];
    }
    while(top<=m) pr[now++]=p[top++];
    for(int i=l;i<=r;i++) p[i]=pr[i];
}
int pos[maxn];
int main(){
    //freopen("test.in","r",stdin);
    n=read();int m=read();int top=0;
    for(int i=1;i<=n;i++) a[i]=read(),p[++top]=nd(0,a[i],i,1),pos[a[i]]=i;
    for(int i=1;i<=m;i++){
        int x=read();x=pos[x];
        p[++top]=nd(i,a[x],x,-1);
    }
    sort(p+1,p+top+1);
    cdq(1,top);
    for(int i=1;i<=m;i++) ans[i]=ans[i-1]-ans[i],printf("%lld\n",ans[i-1]);
    return 0;
}
