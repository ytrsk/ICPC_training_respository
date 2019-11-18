#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=500007;
int id(int l,int r){
	return (l+r)|(l!=r);
}
int s[maxn],z[20];
struct xxj{
	int a[20];
	void insert(int x){
		for(int i=19;~i;--i){
			if(x&(1<<i)){
				if(a[i]) x^=a[i];
				else{
					a[i]=x;
					break;
				}
			}
		}
	}
	int query(){
		int ans=0;
		for(int i=19;~i;i--){
			if(!(ans&z[i])) ans^=a[i];
		}
		return ans;
	}
}a[maxn<<1];
xxj merge(xxj x,xxj y){
	for(int i=19;i>=0;i--) if(y.a[i]) x.insert(y.a[i]);
	return x;
}
xxj Merge(xxj A,xxj B) {
	xxj All,C,D;
	for (int i=19;~i;--i) {
		All.a[i]=A.a[i];
		D.a[i]=1<<i;
	}
	for(int i=19;~i;--i){
		if(B.a[i]){
			int v=B.a[i],k=0,can=1;
			for(int j=19;~j; --j){
				if(v>>j&1){
					if(All.a[j]){
						v^=All.a[j];
						k^=D.a[j];
					}
					else{
						can=0;
						All.a[j]=v;
						D.a[j]=k;
						break;
					}
				}
			}
			if(can){
				int v=0;
				for(int j=19;~j;--j) {
					if(k>>j&1) {
						v^=A.a[j];
					}
				}
				C.insert(v);
			}
		}
	}
	return C;
}
xxj build(int l,int r){
	if(l==r){
		a[id(l,r)].insert(s[l]);
		return a[id(l,r)];
	}
	int m=(l+r)>>1;
	a[id(l,r)]=merge(build(l,m),build(m+1,r));

	return a[id(l,r)];
}
xxj query(int l,int r,int ql,int qr){
	if(ql==l&&r==qr){
		return a[id(l,r)];
	}
	int m=(l+r)>>1;
	if(ql<=m&&qr>m) return merge(query(l,m,ql,m),query(m+1,r,m+1,qr));
	else if(ql<=m) return query(l,m,ql,qr);
	else return query(m+1,r,ql,qr);
}
int main(){
	for(int i=0;i<=19;i++) z[i]=(1<<i);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&s[i]);
	build(1,n);
	int m;scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",query(1,n,l,r).query());
	}
	return 0;
}
