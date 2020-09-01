
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

#include<bits/stdc++.h>
const int maxn = 500005;
const int maxp = maxn*20;
using namespace std;
inline void read(int &a){
    char c;bool f=0;
	while(!isdigit(c=getchar())) if(c=='-') f=1;
    for(a=c-'0';isdigit(c=getchar());a=a*10+c-'0');
	if(f) a=-a;
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
namespace LCT{
	const int N = 1500005;
	int ch[N][2],fa[N],v[N],pos[N],tot,nb[N][2];
	bool rev[N];
	#define il inline
	#define lc ch[x][0]
	#define rc ch[x][1]
	il bool isr(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
	il bool isc(int x){return ch[fa[x]][1]==x;}
	il void upd(int x){
		pos[x]=x;
		if(v[pos[x]]>v[pos[lc]]) pos[x]=pos[lc];
		if(v[pos[x]]>v[pos[rc]]) pos[x]=pos[rc];
	}
	il void pushdown(int x){
		if(rev[x]){
			swap(lc,rc),rev[x]=0;
			if(lc) rev[lc]^=1; if(rc) rev[rc]^=1;
		}
	}
	il void pdpath(int x){if(!isr(x)) pdpath(fa[x]);pushdown(x);}
	il void rot(int x){
		int y=fa[x],z=fa[y],c=isc(x);
		if(!isr(y)) ch[z][isc(y)]=x;
		(ch[y][c]=ch[x][!c])&&(fa[ch[x][!c]]=y);
		fa[ch[x][!c]=y]=x,fa[x]=z;
		upd(y),upd(x);
	}
	il void splay(int x){
		pdpath(x);
		for(;!isr(x);rot(x))
			if(!isr(fa[x])) rot(isc(fa[x])==isc(x)?fa[x]:x); 
	}
	il int access(int x,int y=0){
		for(;x;x=fa[y=x]) splay(x),ch[x][1]=y,upd(x);
		return y;
	}
	il void bert(int x){access(x),splay(x),rev[x]^=1;}
	il int sert(int x){access(x),splay(x);for(;lc;x=lc);return x;}
	il void link(int x,int y){bert(x),fa[x]=y;}
	il void cut(int x,int y){bert(x),access(y),splay(y);fa[x]=ch[y][0]=0,upd(y);}
	il int split(int x,int y){bert(x),access(y),splay(y); return y;}
	il bool judge(int x,int y){bert(x);return sert(y)==x;}
	il int insert(int x,int y,int w){
		int tmp=0;
		if(judge(x,y)){
			int p=pos[split(x,y)]; tmp=v[p];
			cut(nb[p][0],p),cut(p,nb[p][1]);
		}
		v[++tot]=w,pos[tot]=tot,nb[tot][0]=x,nb[tot][1]=y;fa[tot]=0;rev[tot]=0;
        ch[tot][0]=ch[tot][1]=0;
		link(x,tot),link(tot,y);
		return tmp;
	}
	#undef lc 
	#undef rc
}
int n,m,Q,tp,ans;
int a[maxn],mx[maxn<<2];
void pushup(int o){
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void build(int o,int l,int r){
    if(l==r){
        mx[o]=a[l];return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);build(o<<1|1,m+1,r);
    pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr) return mx[o];
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return max(query(o<<1,l,m,ql,m),query(o<<1|1,m+1,r,m+1,qr));
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr); 
}
int main(){
	int x,y,t;
    rd(t);
    while(t--){
	    rd(n);
        rd(m);
        rd(Q);
        LCT::tot=n;
        for(int i=0;i<=n;i++) LCT::pos[i]=0,LCT::v[i]=m+1,LCT::ch[i][0]=LCT::ch[i][1]=0,LCT::rev[i]=LCT::fa[i]=LCT::nb[i][0]=LCT::nb[i][1]=0;
        for(int i=1;i<=m;i++){
            rd(x);rd(y);
        // if(x==y) {rt[i]=rt[i-1];continue;}
            a[i]=LCT::insert(x,y,i);
        }
        build(1,1,m);
        int ans=1;
        while(Q--){
            int x,y;rd(x),rd(y);
            int k1=(x^ans)%m+1;
            int k2=(y^ans)%m+1;
            x=min(k1,k2);y=max(k1,k2);
            if(query(1,1,m,x,y)>=x){
                ans=1;
            }
            else ans=0;
            if(ans==1) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}