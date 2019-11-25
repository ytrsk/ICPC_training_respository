#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1000007;
int root[1000007],e1,a[1000007],ls[20000007],rs[20000007],val[20000007];
void ins(int &o,int p,int l,int r,int x,int y){
	o=++e1;ls[o]=ls[p];rs[o]=rs[p];
	int m=(l+r)>>1;
	if(l==r){
		val[o]=y;return;
	}
	x<=m?ins(ls[o],ls[p],l,m,x,y):ins(rs[o],rs[p],m+1,r,x,y);
}
void build(int &o,int l,int r){
    if(!o) o=++e1;
    if(l==r){
        val[o]=a[l];return;
    }
    int m=(l+r)>>1;
    build(ls[o],l,m);build(rs[o],m+1,r);
}
int query(int o,int l,int r,int x){
	if(l==r) return val[o];
	int m=(l+r)>>1;
	if(x<=m) return query(ls[o],l,m,x);
	else return query(rs[o],m+1,r,x);
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(root[0],1,n);
    for(int i=1;i<=m;i++){
        int p,opt,x;scanf("%d%d%d",&p,&opt,&x);
        if(opt==1){
            int y;scanf("%d",&y);
            ins(root[i],root[p],1,n,x,y);
        }
        else{
            printf("%d\n",query(root[p],1,n,x));root[i]=root[p];
        }
    }
	return 0;
}
