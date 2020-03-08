#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

inline int Get_Int() {
	int num=0,bj=1;
	char x=getchar();
	while(!isdigit(x)) {if(x=='-')bj=-1;x=getchar();}
	while(isdigit(x)) {num=num*10+x-'0';x=getchar();}
	return num*bj;
}

const int maxn=1000005;
const LL mod=1e9+7;

#define Size(x) (edges[x].size())

vector<int> edges[maxn];

LL fac[maxn],f[maxn],ans=0;
int n,b[maxn];

LL Quick_Pow(LL a,LL b) {
	LL sum=1;
	for(; b; b>>=1,a=a*a%mod)if(b&1)sum=sum*a%mod;
	return sum;
}

LL inv(LL x) {return Quick_Pow(x,mod-2);}

struct BIT {
	int n;
	vector<int> c;
	#define lowbit(x) (x&(-x))
	void init(int n) {
		this->n=n;
		c.resize(n+1);
		c.clear();
	}
	void add(int x,int v) {
		for(int i=x; i<=n; i+=lowbit(i))c[i]+=v;
	}
	int query(int x) {
		int sum=0;
		for(int i=x; i>=1; i-=lowbit(i))sum+=c[i];
		return sum;
	}
} bit[maxn];

int step=0;

void Cal(int Now,LL up) {
	step++;
	LL mul=1;
	for(int Next:edges[Now])mul=mul*f[Next]%mod;
	for(int i=Size(Now)-1; i>=0; i--) {
		int bNext=lower_bound(edges[Now].begin(),edges[Now].end(),b[step+1])-edges[Now].begin();
		ans=(ans+mul*fac[i]%mod*up%mod*bit[Now].query(bNext)%mod);
		if(bNext==Size(Now)||edges[Now][bNext]!=b[step+1])return; //遍历完了返回父节点
		bit[Now].add(bNext+1,-1);
		mul=mul*inv(f[edges[Now][bNext]])%mod;
		Cal(edges[Now][bNext],mul*up%mod*fac[i]%mod);
	}
}

void Dfs(int Now,int fa) {
	if(fa)edges[Now].erase(find(edges[Now].begin(),edges[Now].end(),fa));
	f[Now]=fac[Size(Now)];
	bit[Now].init(Size(Now));
	for(int i=1; i<=Size(Now); i++)bit[Now].add(i,1);
	if(edges[Now].empty())return;
	sort(edges[Now].begin(),edges[Now].end());
	for(int Next:edges[Now]) {
		Dfs(Next,Now);
		f[Now]=f[Now]*f[Next]%mod;
	}
}

void Clear() {
	step=0;
	for(int i=1; i<=n; i++)edges[i].clear();
}

int main() {
	fac[0]=1;
	for(int i=1; i<maxn; i++)fac[i]=fac[i-1]*i%mod;
	int t=Get_Int();
	while(t--) {
		n=Get_Int();
		Clear();
		for(int i=1; i<=n; i++)b[i]=Get_Int();
		for(int i=1; i<n; i++) {
			int x=Get_Int(),y=Get_Int();
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		ans=0;
		LL mul=1;
		for(int i=1; i<=n; i++)mul=mul*fac[Size(i)-1]%mod;
		for(int i=1; i<b[1]; i++)ans=(ans+mul*Size(i)%mod)%mod;
		Dfs(b[1],0);
		Cal(b[1],1);
		printf("%lld\n",ans%mod);
	}
	return 0;
}
