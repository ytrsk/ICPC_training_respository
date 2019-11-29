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
const int maxn=1000007;
const int inf=1e9;
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
    nd(int x=0,int y=0,int z=0,int v=0):x(x),y(y),z(z){}
    bool operator < (nd a) const{
        if(x!=a.x) return x<a.x;
        else if(y!=a.y) return y<a.y;
        else return z<a.z;
    }
}p[maxn],pr[maxn],P[maxn];
void add(int o,int x){
    for(int i=o;i<=V;i+=lowbit(i)) v[i]=max(v[i],x);
}
void del(int o){
    for(int i=o;i;i-=lowbit(i)) v[i]=-inf;
}
int query(int o){
    int x=0;
    for(int i=o;i;i-=lowbit(i)) x=max(x,v[i]);
    return x;
}
//外部排序时如表达式(第一位第二位第三位)出现相等的情况，需要调整cmp，如果全部相等，则需缩点
//内部排序时第二维第三维可随意处理，第一维如出现不等号（但是数据中有第一维相等的情况），需要加上判断条件(只加入不等于的点)
//注意内存(n+m)
void cdq(int l,int r){
    if(l==r) return;
    int m=(l+r)>>1;
    cdq(l,m);cdq(m+1,r);
    int top=l,now=l;
    for(int i=m+1;i<=r;i++){
        while(top<=m&&p[top].y<=p[i].y) {if(!vis[p[top].x]) add(p[top].z,p[top].y+p[top].z);pr[now++]=p[top++];}
        if(vis[p[i].x]){
            ans[p[i].x]=min(ans[p[i].x],p[i].y+p[i].z-query(p[i].z));
        }
        pr[now++]=p[i];
    }
    for(int i=l;i<top;i++) del(p[top].z);
    while(top<=m) pr[now++]=p[top++];
    for(int i=l;i<=r;i++) p[i]=pr[i];
}
int pos[maxn];
int main(){
    //freopen("test.in","r",stdin);
    return 0;
}
