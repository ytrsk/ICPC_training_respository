
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=300007;
int rt[2][maxn],e1,sum[maxn*30],ls[maxn*30],rs[maxn*30];
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
int query(int x,int y,int l,int r,int z){
	if(l==r) return l<=z?sum[y]-sum[x]:0;
	int m=(l+r)>>1;
	if(z<=m) return query(ls[x],ls[y],l,m,z);
	else return sum[ls[y]]-sum[ls[x]]+query(rs[x],rs[y],m+1,r,z);
}
int L[maxn],R[maxn];
int pre[maxn];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main(){
	int t=read();
	while(t--){
		e1=0;
		int n=read(),m=read(),q=read();
		for(int i=1;i<=n;i++) pre[n]=0;
		for(int i=1;i<=m;i++){
			L[i]=read();R[i]=read();
			ins(rt[0][i],rt[0][i-1],0,n,pre[L[i]]);
			ins(rt[1][i],rt[1][i-1],0,n,pre[R[i]]);
			pre[L[i]]=i;pre[R[i]]=i;
		}
		int ans=0;
		for(int i=1;i<=q;i++){
			int l=read(),r=read();
			int k1=(l^ans)%m+1;
			int k2=(r^ans)%m+1;
			l=min(k1,k2);r=max(k1,k2);
			int N=query(rt[0][l-1],rt[0][r],0,n,l-1)+query(rt[1][l-1],rt[1][r],0,n,l-1);
			int M=r-l+1;
			if(M>N-1) ans=1;
			else ans=0;
			if(ans) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
