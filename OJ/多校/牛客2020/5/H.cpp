#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100007;
int e1,ls[maxn*200],rs[maxn*200],sum[maxn*200],rt[maxn];
int merge(int x,int y){
	if(!x||!y) return x+y;
	int now=++e1;
	sum[now]=sum[x]+sum[y];
	ls[now]=merge(ls[x],ls[y]);
	rs[now]=merge(rs[x],rs[y]);
	return now;
}
void pushup(int o){
	sum[o]=sum[ls[o]]+sum[rs[o]];
}
void ins(int &o,int l,int r,int x,int y){
	if(!o) o=++e1;
	if(l==r){
		sum[o]+=y;return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) ins(ls[o],l,mid,x,y);
	else ins(rs[o],mid+1,r,x,y);
	pushup(o);
}
int query(int o,int l,int r,int x){
    if(l==r) return l>=x?sum[o]:0;
    int mid=(l+r)>>1;
    if(x<=mid) return query(ls[o],l,mid,x)+sum[rs[o]];
    else return query(rs[o],mid+1,r,x);
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int a[maxn];
int Top=0,top;
struct node{
	int l,r,val;
	node(int l=0,int r=0,int val=0):l(l),r(r),val(val){}
	bool operator < (node x) const{
		if(val^x.val) return val<x.val;
		else if(r^x.r) return r<x.r;
		else return l>x.l; 
	}
}Q[maxn],q[maxn],s[maxn*32],S[maxn*32];
int tot,Tot;
int main(){
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=n;i>=1;i--){
		Top=0;
		q[0]=node(0,i,a[i]);
		for(int k=0;k<=top;k++){
			int x=a[i]&q[k].val;
			if(!Top||x!=Q[Top-1].val) Q[++Top]=node(i,q[k].r,x);
		}
		top=Top;
		for(int k=1;k<=top;k++) q[k]=Q[k],s[++tot]=q[k];
	}
	sort(s+1,s+tot+1);
	int mx;
	for(int i=1;i<=tot;i++){
		if(i==1||s[i].val!=s[i-1].val){
			mx=s[i].l;S[++Tot]=s[i];
		}
		else {
			if(mx<s[i].l) mx=s[i].l,S[++Tot]=s[i];
		}
	}
	for(int i=1;i<=Tot;i++){
        //cout<<i<<" "<<S[i].l<<" "<<S[i].r<<" "<<S[i].val<<endl;
		if(i-1&&S[i].val==S[i-1].val) ins(rt[S[i].r],0,(1<<30)-1,S[i-1].l,-1);
        ins(rt[S[i].r],0,(1<<30)-1,S[i].l,1);
	}
    for(int i=1;i<=n;i++) rt[i]=merge(rt[i],rt[i-1]);
	int q=read(),ans=0;
	for(int i=1;i<=q;i++){
		int l=read(),r=read();
		l=(l^ans)%n+1,r=(r^ans)%n+1;
		if(l>r) swap(l,r);
        printf("%d\n",ans=query(rt[r],0,(1<<30)-1,l));
	}
	return 0;
}