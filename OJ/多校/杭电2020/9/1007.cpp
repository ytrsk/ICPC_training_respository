#include<bits/stdc++.h>

using namespace std;

inline int Get_Int() {
	int num=0,bj=1;
	char x=getchar();
	while(!isdigit(x)) {if(x=='-')bj=-1;x=getchar();}
	while(isdigit(x)) {num=num*10+x-'0';x=getchar();}
	return num*bj;
}

typedef long long LL;

#define pii pair<int,int>
#define pil pair<int,LL>
mt19937 g(rand());

int max(int a,int b) {return a>b?a:b;}

const int maxn=200005;

bool CHANGE;

struct Treap { //root is interface 
	struct Tree {
		int l,r,size;
		int val,min;
		LL sum;
		Tree(int s=0,int v=0):l(0),r(0),size(s),val(v),min(v),sum(v) {}
	} tree[maxn*2];
#define ls(x) tree[x].l
#define rs(x) tree[x].r
#define val(x) tree[x].val
#define size(x) tree[x].size
	int size;
	void init() {
		for(int i=0; i<=size; i++)tree[i]=Tree();
		size=0;
	}
	int newnode(int v) {tree[++size]=Tree(1,v);return size;}
	void push_up(int x) {
		size(x)=size(ls(x))+size(rs(x))+1;
		tree[x].min=tree[x].sum=val(x);
		if(ls(x))tree[x].min=min(tree[x].min,tree[ls(x)].min),tree[x].sum+=tree[ls(x)].sum;
		if(rs(x))tree[x].min=min(tree[x].min,tree[rs(x)].min),tree[x].sum+=tree[rs(x)].sum;
	}
	pii split(int x,int num) {
		if(!x)return pii(0,0);
		int now;
		if(CHANGE) {now=++size;tree[now]=tree[x];}
		else now=x;
		if(num<=size(ls(x))) {
			pii lt=split(ls(x),num);
			ls(now)=lt.second;
			push_up(now);
			return pii(lt.first,now);
		} else {
			pii rt=split(rs(x),num-size(ls(x))-1);
			rs(now)=rt.first;
			push_up(now);
			return pii(now,rt.second);
		}
	}
	int merge(int a,int b) {
		if(!a||!b)return a+b;
		int now;
		if(g()%(size(a)+size(b))<size(a)) {
			if(CHANGE) {now=++size;tree[now]=tree[a];}
			else now=a;
			rs(now)=merge(rs(a),b);
		} else {
			if(CHANGE) {now=++size;tree[now]=tree[b];}
			else now=b;
			ls(now)=merge(a,ls(b));
		}
		push_up(now);
		return now;
	}
	int find_rank(int x,int k) {
		if(!x)return 0;
		if(k<=size(ls(x)))return find_rank(ls(x),k);
		else if(k==size(ls(x))+1)return x;
		else return find_rank(rs(x),k-size(ls(x))-1);
	}
	int insert(int x,int k,int v) {
		pii tmp=split(x,k-1);
		return merge(merge(tmp.first,newnode(v)),tmp.second);
	}
	int remove(int x,int k) {
		pii a=split(x,k-1);
		pii b=split(a.second,1);
		return merge(a.first,b.second);
	}
	pair<pil,int> find(int x,int v) { //找到最靠右的比v小的结点
		if(tree[x].min>=v)return pair<pil,int>(pil(-1,0),0);
		if(rs(x)&&tree[rs(x)].min<v) {
			pair<pil,int> tmp=find(rs(x),v);
			return pair<pil,int>(tmp.first,tmp.second+size(ls(x))+1);
		} else if(val(x)<v)return pair<pil,int>(pil(x,0),size(ls(x)));
		else if(ls(x)) {
			pair<pil,int> tmp=find(ls(x),v);
			return pair<pil,int>(pil(tmp.first.first,tree[rs(x)].sum+val(x)+tmp.first.second),tmp.second);
		}
		return pair<pil,int>(pil(-1,0),0);
	}
	void dfs(int x) {
		if(ls(x))dfs(ls(x));
		printf("%d ",val(x));
		if(rs(x))dfs(rs(x));
	}
} bbt;

int n,q;

int main() {
	srand(time(NULL));
	int t=Get_Int();
	while(t--) {
		bbt.init();
		n=Get_Int();
		q=Get_Int();
		int root=0;
		for(int i=1; i<=n; i++)root=bbt.insert(root,i,Get_Int());
		while(q--) {
			int opt=Get_Int();
			if(opt==1) {
				int x=Get_Int(),y=Get_Int();
				CHANGE=1;
				int tmp=bbt.split(root,x).first;
				pair<pil,int> result=bbt.find(tmp,y);
				int pos=result.first.first,posrank=result.second+1;
				if(pos==-1) {puts("0");continue;}
				printf("%lld\n",result.first.second-(y-1)*(x-pos));
				CHANGE=0;
				int posd=bbt.find_rank(root,posrank+1);
				int delta=bbt.tree[posd].val-y+1+bbt.tree[pos].val;
				root=bbt.remove(root,posrank);
				root=bbt.insert(root,posrank,delta);
				root=bbt.remove(root,posrank+1);
				root=bbt.insert(root,x,y-1);
			} else printf("%d\n",bbt.tree[bbt.find_rank(root,Get_Int())].val);
		}
		bbt.dfs(root);
		putchar('\n');
	}
	return 0;
}