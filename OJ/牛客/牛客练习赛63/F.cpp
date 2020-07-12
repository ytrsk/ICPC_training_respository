#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=500007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int mx[maxn];
vector<int> g[maxn],G[maxn];
int L[maxn],R[maxn],e1;
int val[maxn];
void dfs(int u,int fa){
    mx[u]=0;L[u]=++e1;
    for(auto v:g[u]){
        if(v^fa){
            dfs(v,u);
            mx[u]=max(mx[u],mx[v]+1);
        }
    }
    R[u]=e1;val[L[u]]=mx[u];
}
int query(int x,int y){
    int pos=upper_bound(G[x].begin(),G[x].end(),y)-G[x].begin();
    return pos;
}
int main(){
    int n=read();
    rep(i,1,n-1){
        int u=read(),v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int now=0;
    for(int i=1;i<=n;i++){
        G[val[i]].push_back(i);
        now^=mx[i];
    }
    ll ans=0;
    rep(i,1,n){
        if((now^mx[i])<mx[i]){
            ans+=query(now^mx[i],R[i])-query(now^mx[i],L[i]-1);
        }
    }
    if(ans){
        printf("YES\n%lld",ans);
    }
    else printf("NO");
    return 0;
}