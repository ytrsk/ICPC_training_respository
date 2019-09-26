#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxn=10000007;
typedef long long ll;
int root[100007],e1,tr[maxn][2],sum[10000007];
void pushup(int o){
	sum[o]=sum[tr[o][0]]+sum[tr[o][1]];
}
void ins(int &o,int p,int len,ll x){
	o=++e1;
	for(int i=0;i<2;i++) tr[o][i]=tr[p][i];
	sum[o]=sum[p];
	if(len==-1){
		sum[o]+=1;return;
	}
	ins(tr[o][x>>len&1],tr[p][x>>len&1],len-1,x);
	pushup(o);
}
ll query(int x,int y,int len,ll v){
	if(len==-1) return 0;
    int p=(v>>len&1)^1;
    if(sum[tr[y][p]]-sum[tr[x][p]]) return (1LL<<len)+query(tr[x][p],tr[y][p],len-1,v);
    else return query(tr[x][p^1],tr[y][p^1],len-1,v);
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum1[i+1]=sum1[i]^a[i];
    n++;
    for(int i=1;i<=n;i++){
        ins(root[i],root[i-1],60,sum1[i]);
    }
	return 0;
}
