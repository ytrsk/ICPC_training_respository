#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=3000007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int n,bl,blc,a[maxn],st[maxn/4][20],val[maxn/4],lg[maxn/4];
inline void rmq(int n){
    for(register int i=1;i<=n;++i) st[i][0]=val[i];
	for(register int i=1;(1<<i)<=n;++i){
		for(register int k=1;k+(1<<i)-1<=n;++k){
			st[k][i]=max(st[k][i-1],st[k+(1<<i-1)][i-1]);
		}
	}
	for(register int i=1;i<=n;++i) lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
}
inline int query(int l,int r){
    if(l>r) return 0;
    int x=lg[r-l+1];
    return max(st[l][x],st[r-(1<<x)+1][x]);
}
int dp[maxn][5],bll[maxn/4],blr[maxn/4],be[maxn];
inline void pre(){
    bl=max(1,(int)(log(n)/log(4)/2));
    for(register int i=1;i<=n;++i) be[i]=(i-1)/bl+1;
    blc=be[n];
    for(int i=1;i<=blc;i++){
        bll[i]=(i-1)*bl+1;
        blr[i]=i*bl;
    }
    for(register int i=1;i<=n;++i) val[be[i]]=max(val[be[i]],a[i]);
    rmq(blc);
    for(register int i=1;i<=n;i++){
        dp[i][0]=a[i];
        for(register int k=1;k<5;k++){
            dp[i][k]=max(dp[i][k-1],a[i+k]);
        }
    }
}
inline int Query(int l,int r){
    if(be[l]==be[r]) return dp[l][r-l];
    else return max(dp[l][blr[be[l]]-l],max(dp[bll[be[r]]][r-bll[be[r]]],query(be[l]+1,be[r]-1)));
}
int main(){
    freopen("test.in","r",stdin);
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    pre();
    return 0;
}
