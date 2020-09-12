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
#include <bits/stdc++.h>
using namespace std;
const int maxn=400007;
typedef long long ll;
const int mod=1e9+7;
const ll G=3;
ll A[maxn<<2],B[maxn<<2],pre[maxn<<2];
typedef long long ll;
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
inline int Pown(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}

vector<int> g[maxn];
int n,cl,dfn[maxn],low[maxn];;
int e1,head[maxn<<1],to[maxn<<2],nex[maxn<<2];
int dcnt=0,sz[maxn<<1];
inline void Addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
inline void Add(int u,int v){
    Addedge(u,v);Addedge(v,u);
}
int S[maxn],Top;
inline void tarjan(int u,int fa){
    dfn[u]=low[u]=++cl;S[++Top]=u;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                dcnt++;int x;
                Add(n+dcnt,u);
                do{x=S[Top--],Add(n+dcnt,x);} while(x!=v);
            }
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);
    }
}
void init(){
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=0;
    dcnt=cl=e1=Top=0;
    for(int i=1;i<=2*n;i++) head[i]=0;
}
int Ans=0;
inline int add(int a,int b){
    return a+b>=mod?a+b-mod:a+b;
}
inline int dec(int a,int b){
    return a-b<0?a-b+mod:a-b;
}
inline int mul(int a,int b){
    return 1LL*a*b%mod;
}
inline void dfs(int u,int fa){
    sz[u]=(u<=n);
    int now=0;
    vector<int> pre;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);sz[u]+=sz[v];
        pre.push_back(sz[v]);
        ++now;
    }
    pre.push_back(n-sz[u]);
    now=pre.size();
    if(u>n){
        if(now>2){
            int Pre0=0,Pre1=0,Pre2=0,x=Pown(now,mod-2);
            int ans1=0,ans2=0;
            for(int i=0;i<now;i++){
                int now0=pre[i],now1=1LL*now0*i%mod,now2=1LL*now1*i%mod;
                ans1=add(ans1,mul(Pre0,now1));
                ans1=dec(ans1,mul(Pre1,now0));
                ans2=dec(ans2,mul(now2,Pre0));
                ans2=dec(ans2,mul(now0,Pre2));
                ans2=add(ans2,mul(2,mul(now1,Pre1)));   
                Pre1=add(Pre1,now1);
                Pre0=add(Pre0,now0);
                Pre2=add(Pre2,now2);
            }
            Ans=add(Ans,ans1);
            Ans=add(Ans,mul(ans2,x));
        }
        else Ans=add(Ans,mul(pre[0],pre[1]));
    }
}
int main(){
    int T;rd(T);
    while(T--){
        rd(n);init();Ans=0;
        int m;rd(m);
        while(m--){
            int u,v;rd(u);rd(v);
            g[u].push_back(v);g[v].push_back(u);
        }
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
        dfs(1,0);
        printf("%lld\n",Ans);
    }
    return 0;
}
