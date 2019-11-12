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
inline int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
#define rd(n) FastIO::read(n)

namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], obuf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	bool read(int& x) {
		int n = read(str), bf;

		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
};

struct nd{
    int x,y,z;
    nd(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    bool operator < (nd a) const{
        return x<a.x;
    }
}p[maxn],pr[maxn],P[maxn];
int v[4500007],ans[500007],vis[500007];
int n,m,V;
inline void add(int o,int x){
    for(register int i=o;i<=V;i+=lowbit(i)) v[i]=max(v[i],x);
}
inline void del(int o){
    for(register int i=o;i<=V;i+=lowbit(i)) v[i]=-inf;
}
inline int query(int o){
    int x=-inf;
    for(register int i=o;i;i-=lowbit(i)) x=max(x,v[i]);
    return x;
}
//外部排序时如表达式(第一位第二位第三位)出现相等的情况，需要调整cmp，如果全部相等，则需缩点
//内部排序时第二维第三维可随意处理，第一维如出现不等号（但是数据中有第一维相等的情况），需要加上判断条件(只加入不等于的点)
//注意内存(n+m)
inline void cdq(int l,int r){
    if(l==r) return;
    int m=(l+r)>>1;
    cdq(l,m);cdq(m+1,r);
    register int top=l,now=l;
    for(register int i=m+1;i<=r;++i){
        while(top<=m&&p[top].y<=p[i].y) {if(!vis[p[top].x]) add(p[top].z,p[top].y+p[top].z);pr[now++]=p[top++];}
        if(vis[p[i].x]) ans[p[i].x]=min(ans[p[i].x],p[i].y+p[i].z-query(p[i].z));
        pr[now++]=p[i];
    }
    for(register int i=l;i<top;++i) if(!vis[p[i].x]) del(p[i].z);
    while(top<=m) pr[now++]=p[top++];
    for(register int i=l;i<=r;++i) p[i]=pr[i];
}
int pos[maxn];
int main(){
    freopen("test.in","r",stdin);
    freopen("my.out","w",stdout);
    rd(n);rd(m);int top=0;
    int mx=0;
    for(rint i=1;i<=n;++i) {
        int x,y;rd(x);rd(y);p[++top]=nd(0,x,y);
        mx=max(mx,max(1-x,1-y));
    }
    for(rint i=1;i<=m;++i){
        int opt,x,y;rd(opt);rd(x);rd(y);p[++top]=nd(i,x,y);if(opt-1) vis[i]=1;
        mx=max(mx,max(1-x,1-y));ans[i]=inf;
    }
    int Mx=0;
    for(rint i=1;i<=top;++i) p[i].y+=mx,p[i].z+=mx,Mx=max(Mx,max(p[i].y,p[i].z));
    V=Mx<<1;Mx++;
    for(rint i=1;i<=V;++i) v[i]=-inf;
    for(rint i=1;i<=top;++i) P[i]=p[i];cdq(1,top);
    for(rint i=1;i<=top;++i) p[i]=P[i],p[i].y=Mx-p[i].y;cdq(1,top);
    for(rint i=1;i<=top;++i) p[i]=P[i],p[i].z=Mx-p[i].z,p[i].y=Mx-p[i].y;cdq(1,top);
    for(rint i=1;i<=top;++i) p[i]=P[i],p[i].z=Mx-p[i].z;cdq(1,top);
    for(rint i=1;i<=m;++i){
        if(vis[i]) printf("%d\n",ans[i]);
    }
    return 0;
}
