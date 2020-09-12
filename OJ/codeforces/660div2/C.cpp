#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
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
vector<int> g[maxn];
int p[maxn],sz[maxn],h[maxn],ok,A[maxn],B[maxn];
void dfs(int u,int fa){
    sz[u]=p[u];
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    if((h[u]+sz[u])%2) ok=0;
    else{
        ll x=(h[u]+sz[u])/2;
        ll y=(sz[u]-h[u])/2;
        if(x<0||y<0||x>sz[u]|y>sz[u]) ok=0;
        A[u]=x;B[u]=y;
        int totA=0,totB=0;
        for(auto v:g[u]){
            if(v==fa) continue;
            totA+=A[v];
            totB+=B[v];
        }
        ll LA=0,LB=A[u]-totA;
        ll RA=max(0,B[u]-totB),RB=p[u];
      // cout<<x<<" "<<y<<" "<<totA<<" "<<totB<<" "<<LA<<" "<<RA<<" "<<LB<<" "<<RB<<endl;
        ll aa=max(LA,p[u]-RB),bb=min(LB,p[u]-RA);
        if(aa>bb) ok=0;
    }
}
int main(){
    int t=read(); 
    while(t--){
        ok=1;
        int n=read(),m=read();
        rep(i,1,n) p[i]=read();
        rep(i,1,n) h[i]=read();
        rep(i,1,n) g[i].clear();
        rep(i,1,n-1){
            int u=read(),v=read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}