#pragma GCC optimize("3")
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
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
int A[maxn],head[maxn],to[maxn<<1],nex[maxn<<1],e1;
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int d[maxn],pos[maxn],top,n,m;
vector<int> g[maxn];
int be[maxn],bl;
int sum[320][320],cnt[320][maxn],sz[320];

inline void change2(int u,int x,int c){
    cnt[u][x]+=c;
    sum[u][be[x]]+=c;
}
inline void change(int u,int x,int c){
    if(x>n) return;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        change2(pos[v],x,c);
    }
}
int C[maxn];
inline int query2(int u){
    for(int i=1;i<=be[n];i++){
     //   cout<<sz[i]<<" "<<sum[u][i]<<" "<<u<<endl;
        if(sum[u][i]==sz[i]) continue;
        else{
            for(int k=(i-1)*bl+1;k<=min(n,i*bl);k++){
                if(!cnt[u][k]) return k;
            }
        }
    }
    return n+1;
}
inline int query(int u){
    if(pos[u]){
        return query2(pos[u]);
    }
    else{
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(A[v]+1<=n) C[A[v]+1]++;
        }
        int x=0;
        for(int i=1;i<=n+1;i++){
            if(!C[i]){
                x=i;break;
            }
        }
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(A[v]+1<=n) C[A[v]+1]--;
        }
        return x;
    }
}
int main(){
   // freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
    int t;rd(t);
    while(t--){
        rd(n),rd(m);top=0;e1=0,bl=sqrt(n);
        for(int i=1;i<=n;i++) rd(A[i]),d[i]=0,pos[i]=0,g[i].clear(),head[i]=0,be[i]=(i-1)/bl+1;
        for(int i=1;i<=m;i++){
            int u;rd(u);int v;rd(v);
            addedge(u,v);addedge(v,u);
            d[u]++;d[v]++;
        }
        for(int i=1;i<=n;i++){
            if(d[i]>=bl) {
                pos[i]=++top;
                for(int k=1;k<=be[n];k++){
                    sum[pos[i]][k]=0;
                }
                for(int k=1;k<=n;k++) cnt[pos[i]][k]=0;
            }
        }
        for(int i=1;i<be[n];i++) sz[i]=bl;
        sz[be[n]]=n-(be[n]-1)*bl;
        for(int i=1;i<=n;i++){
            for(int k=head[i];k;k=nex[k]){
                int v=to[k];
                if(pos[v]){
                    g[i].push_back(v);
                    if(A[i]+1<=n) change2(pos[v],A[i]+1,1);
                }
            }
        }
        int q;rd(q);
        while(q--){
            int opt;rd(opt);
            if(opt==1){
                int u,x;rd(u),rd(x);
                change(u,A[u]+1,-1);
                change(u,x+1,1);
                A[u]=x;
            }
            else{
                int u;rd(u);
                printf("%d\n",query(u)-1);
            }
        }
    }
    return 0;
}
/*
1
5 10
2 3 4 5 1
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
*/