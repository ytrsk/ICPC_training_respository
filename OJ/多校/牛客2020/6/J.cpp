#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct Splay {
	struct Tree {
		int child[2],father;
		int key,size,cnt;
		int val;
		Tree(int l=0,int r=0,int fa=0,int k=0,int s=0,int v=0):father(fa),key(k),size(s),cnt(s),val(v) {child[0]=l,child[1]=r;}
	} tree[maxn];
	int size,root;
#define ls(x) tree[x].child[0]
#define rs(x) tree[x].child[1]
#define fa(x) tree[x].father
#define cnt(x) tree[x].cnt
#define val(x) tree[x].key
#define size(x) tree[x].size
	void init(int n) {
		size=root=0;
		for(int i=0; i<=n+2; i++)tree[i]=Tree();
		tree[++size]=Tree(0,2,0,INT_MIN,0);
		tree[++size]=Tree(0,0,1,INT_MAX,0);
		root=size;
	}
	void clear(int x) {tree[x]=0;}
	bool checkson(int x) {return rs(fa(x))==x;}
	void push_up(int x) {if(x)size(x)=size(ls(x))+size(rs(x))+cnt(x);}
	void rotate(int x) {
		int f=fa(x),g=fa(f),side=checkson(x);
		if(g)tree[g].child[checkson(f)]=x;
		tree[f].child[side]=tree[x].child[side^1],fa(tree[f].child[side])=f;
		fa(f)=x,tree[x].child[side^1]=f;
		fa(x)=g;
		push_up(f),push_up(x);
	}
	void splay(int x,int tar=0) {
		for(int f; (f=fa(x))!=tar; rotate(x))if(fa(f)!=tar)rotate(checkson(x)==checkson(f)?f:x);
		if(tar==0)root=x;
	}
	inline int insert(int v,int val) {
		int now=root,fa=0;
		while(now&&val(now)!=v) {
			fa=now;
			size(fa)++;
			now=tree[now].child[val(now)<v];
		}
		if(now)cnt(now)++,size(now)++;
		else {
			tree[now=++size]=Tree(0,0,fa,v,1,val);
			if(fa)tree[fa].child[val(fa)<v]=now;
		}
		splay(now);
		return now;
	}
	inline void remove() {
		int now=root,pre=pre_suc(0),suc=pre_suc(1);
		splay(pre);
		splay(suc,pre);
		if(cnt(now)>1) {cnt(now)--;size(now)--;}
		else {clear(now);ls(suc)=0;}
		size(pre)--;
		size(suc)--;
	}
	void delete_index(int x) {splay(x);remove();}
	void delete_val(int v) {if(rank(v)==-1)return;remove();}
	int rank(int v) {
		int now=root,ans=0;
		while(now>0&&val(now)!=v) {
			if(v<val(now))now=ls(now);
			else {ans+=size(ls(now))+cnt(now);now=rs(now);}
		}
		if(now<=0)return -1;
		ans+=size(ls(now));
		splay(now);
		return ans+1;
	}
	int kth(int rank) {
		int now=root;
		while(now>=0&&rank>=0) {
			if(ls(now)&&size(ls(now))>=rank)now=ls(now);
			else {
				int tmp=size(ls(now))+cnt(now);
				if(rank<=tmp)return now;
				rank-=tmp;
				now=rs(now);
			}
		}
		return -1;
	}
	int pre_suc(int bj) {
		int now=tree[root].child[bj];
		while(tree[now].child[bj^1])now=tree[now].child[bj^1];
		return now;
	}
	int pre_suc(int v,int bj) {
		if(rank(v)==-1) {
			insert(v,0);
			int pre=pre_suc(bj);
			delete_index(size);
			return pre;
		} else return pre_suc(bj);
	}
} splay;
#undef ls(x)
#undef rs(x)
#undef fa(x)
#undef cnt(x)
#undef val(x)
#undef size(x)
void Transform(int *a,int n,int k,int *ans) {
	int now=0,remain=n,tot=0;
	splay.init(n);
	for(int i=1; i<=n; i++)splay.insert(i,a[i]);
	while(remain) {
		int kth=(now+k)%remain;
		if(kth==0)kth=remain;
		int node=splay.kth(kth);
		ans[++tot]=splay.tree[node].val;
		splay.delete_index(node);
		remain--;
		now=kth-1;
	}
}
void per_power(int *in,int *out,int n,int k) {
	k --;
	static bool vis[maxn];
	for (int i=1;i<=n;i++) vis[i] = false;
	vector <vector<int> > cycle;
	for (int i=1;i<=n;i++) if (!vis[i]) {
		vector <int> cur;
		cur.push_back(i);
		vis[i] = true;
		int x = in[i];
		while (!vis[x]) {
			cur.push_back(x);
			vis[x] = true;
			x = in[x];
		}
		cycle.push_back(cur);
	}
	for (auto &x:cycle) {
		int sz = x.size();
		for (int i=0;i<sz;i++) out[x[i]] = in[x[(i+k)%sz]];
	}
}
void do_per(int *per,int *in,int *out,int n) {
	for (int i=1;i<=n;i++) {
		out[i] = in[per[i]];
	}
}
int raw[maxn],per_1[maxn],per_k[maxn];
bool vis[maxn];
int ans1[maxn],ans2[maxn];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		raw[i] = i;
		ans1[i] = i;
	}
	bool cur = true;
	while (m --) {
		int k,x;
		scanf("%d%d",&k,&x);
		Transform(raw,n,k,per_1);
		per_power(per_1,per_k,n,x);
		if (cur) {
			do_per(per_k,ans1,ans2,n);
		}
		else {
			do_per(per_k,ans2,ans1,n);
		}
		cur ^= 1;
	}
	if (cur) {
		for (int i=1;i<=n;i++) printf("%d%c",ans1[i],i==n?'\n':' ');
	}
	else {
		for (int i=1;i<=n;i++) printf("%d%c",ans2[i],i==n?'\n':' ');
	}
	return 0;
}
