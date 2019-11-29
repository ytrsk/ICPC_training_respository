#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
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
ll col[100007],dp[21][100007],a[100007],ans=0,l1,r1;
void modify(int x,int y){
    int z=a[x];
    ans-=col[z]*(col[z]-1)/2;col[z]+=y;ans+=col[z]*(col[z]-1)/2;
}
void move(int l2,int r2){
    while(r1<r2) modify(r1+1,1),++r1;
    while(l1>l2) modify(l1-1,1),--l1;
    while(r1>r2) modify(r1,-1),--r1;
    while(l1<l2) modify(l1,-1),++l1;
}
inline void solve(int o,int l,int r,int L,int R){
    if(l>r) return;
    int m=(l+r)>>1;
    int pos=-1;
    ll val=(1LL<<60);
    for(int i=L;i<=min(m,R);i++){
        move(i,m);
        if(dp[o-1][i-1]+ans<=val){
            val=dp[o-1][i-1]+ans;pos=i;
        }
    }
    dp[o][m]=val;
    solve(o,l,m-1,L,pos);
    solve(o,m+1,r,pos,R);
}
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=m;i++){
        for(int k=1;k<=n;k++) col[k]=0;
        l1=1,r1=0,ans=0;
        if(i!=1) solve(i,1,n,1,n);
        else solve(i,1,n,1,1);
    }
    cout<<dp[m][n];
    return 0;
}
