#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=400007;
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
int a[maxn];
ll val[21][21];
int cnt[21],id[25];
vector<int> g[27];
int to[maxn];
void addedge(int u,int v){
    g[u].push_back(v);
}
int vis[27];
ll dp[1<<20];
ll you[1<<20][20];
int top=0,q[30];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        for(int k=0;k<20;k++){
            val[a[i]-1][k]+=cnt[k];
        }
        cnt[a[i]-1]++;
    }
    ll ans=0;
    for(int i=1;i<(1<<20);i++){
        dp[i]=(1LL<<60);
        top=0;for(int k=0;k<20;k++) if(i>>k&1) q[++top]=k;
        for(int k=1;k<=top;k++){
            ll sum=0;
            for(int z=1;z<=top;z++){
                if(k!=z) sum+=val[q[z]][q[k]];
            }
            dp[i]=min(dp[i],sum+dp[i^(1<<q[k])]);
        }
    }
    cout<<dp[(1<<20)-1];
    return 0;
}
