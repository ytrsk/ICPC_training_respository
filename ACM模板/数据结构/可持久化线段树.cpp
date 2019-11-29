#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=1000007;
int root[100007],e1,a[100007],sum[2000007],ls[2000007],rs[2000007];
void pushup(int o){
	sum[o]=sum[ls[o]]+sum[rs[o]];
}
void ins(int &o,int p,int l,int r,int x){
	o=++e1;ls[o]=ls[p];rs[o]=rs[p];sum[o]=sum[p];
	int m=(l+r)>>1;
	if(l==r){
		sum[o]+=1;return;
	}
	x<=m?ins(ls[o],ls[p],l,m,x):ins(rs[o],rs[p],m+1,r,x);
	pushup(o);
}
void change(int &o,int l,int r,int x,int y){
	if(!o) o=++e1;
	if(l==r){
		sum[o]+=y;
	}
	int m=(l+r)>>1;
	if(x<=m) change(ls[o],l,m,x,y);
	else change(rs[o],m+1,r,x,y);
	pushup(o);
}
int query(int x,int y,int l,int r,int z){
	if(l==r) return a[l];
	int m=(l+r)>>1;
	if(sum[ls[y]]-sum[ls[x]]>=z) return query(ls[x],ls[y],l,m,z);
	else return query(rs[x],rs[y],m+1,r,z-(sum[ls[y]]-sum[ls[x]]));
}
int main(){
	return 0;
}
