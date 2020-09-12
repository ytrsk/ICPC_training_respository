#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=100007;
int e1,ls[maxn*200],rs[maxn*200],sum[maxn*200],rt[maxn];ll tot[maxn*200];
int merge(int x,int y){
	if(!x||!y) return x+y;
	int now=++e1;
	sum[now]=sum[x]+sum[y];
	tot[now]=tot[x]+tot[y];
	ls[now]=merge(ls[x],ls[y]);
	rs[now]=merge(rs[x],rs[y]);
	return now;
}
void pushup(int o){
	sum[o]=sum[ls[o]]+sum[rs[o]];
	tot[o]=tot[ls[o]]+tot[rs[o]];
}
void ins(int &o,int l,int r,int x,int y){
	if(!o) o=++e1,sum[o]=0,tot[o]=0;
	if(l==r){
		sum[o]+=y;tot[o]+=l*y;return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) ins(ls[o],l,mid,x,y);
	else ins(rs[o],mid+1,r,x,y);
	pushup(o);
}
ll query(int x,int l,int r,int z){
	if(l==r) return min(z,sum[x])*l;
	int mid=(l+r)>>1;
	if(sum[ls[x]]>=z) return query(ls[x],l,mid,z);
	else return tot[ls[x]]+query(rs[x],mid+1,r,z-sum[ls[x]]);
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		insert(root[a],1,1e7,c,1);
		insert(root[b+1],1,1e7,c,-1);
	}
	for(int i=1;i<=100000;i++) root[i]=merge(root[i],root[i-1]);
	ll last=1;
	for(int i=1;i<=m;i++){
		int x,a,b,c;scanf("%d%d%d%d",&x,&a,&b,&c);
		int y=1+(1LL*a*last+b)%c;
		printf("%lld\n",last=query(root[x],1,1e7,y));
	}
	return 0;
}
