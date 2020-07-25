#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=2e5+7;
int n,a[_],ch[_*30][2],siz[_*30],cnt,col,rt[_*30];
ll ans;
vector<pair<int,int>> g[_];
std::vector<int> dsr[_*30];
void insert(int x) {
	int p=0;
	for(int i=29;i>=0;--i) {
		bool k=x&(1LL<<i);
		siz[p]++;
		if(!ch[p][k]) ch[p][k]=++cnt;
		p=ch[p][k];
	} siz[p]++;
	if(!rt[p]) rt[p]=++col;
	dsr[rt[p]].push_back(x);
}
int query(int rt,int init,int x) {
	int p=rt,ans=0;
	for(int i=init;i>=0;--i) {
		bool k=x&(1LL<<i);
		if(ch[p][k]) p=ch[p][k];
		else p=ch[p][!k],ans|=1<<i;
	}
	return ans;
}
void dfs(int p,int dep) {
	if(!ch[p][0]&&!ch[p][1]) return;
	if(!ch[p][0]||!ch[p][1]) {
		dfs(ch[p][0]|ch[p][1],dep-1);
		rt[p]=rt[ch[p][0]|ch[p][1]];
	} else {
		int k=siz[ch[p][0]]<siz[ch[p][1]];
		dfs(ch[p][0],dep-1),dfs(ch[p][1],dep-1);
		rt[p]=rt[ch[p][k]];
		int tmp=0x3f3f3f3f;
		int nb=ch[p][!k];
		ch[p][!k]=0;
		for(auto x:dsr[rt[nb]]) {
			tmp=min(tmp,query(p,dep,x));
			dsr[rt[p]].push_back(x);
		}
		ans+=tmp;
		ch[p][!k]=nb;
	}
}
void DFS(int u,int fa){
    for(auto x:g[u]){
        int w=x.second,v=x.first;
        if(v^fa){
            a[v]=a[u]^w;DFS(v,u);
        }
    }
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main() {
	// freopen("a.in","r",stdin);
	scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u=read(),v=read(),x=read();
        u++;v++;
        g[u].push_back(make_pair(v,x));
        g[v].push_back(make_pair(u,x));
    }
    DFS(1,0);
	for(int i=1;i<=n;++i) insert(a[i]);
	dfs(0,29);
	cout<<ans;
	return 0;
}