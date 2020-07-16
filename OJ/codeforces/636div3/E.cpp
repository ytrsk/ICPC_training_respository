#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
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
int n,d[3][maxn],vis[maxn];
vector<int> g[maxn];
void bfs(int s,int *d){
    queue<int> q;
    for(int i=1;i<=n;i++) vis[i]=0,d[i]=inf; 
    vis[s]=1;d[s]=0;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(!vis[v]){
                d[v]=d[u]+1;vis[v]=1;q.push(v);
            }
        }
    }
}
ll p[maxn];
ll sum[maxn];
int main(){
    int t=read();
    while(t--){
        n=read();int m=read(),A=read(),B=read(),C=read();
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<=m;i++) p[i]=read();
        sort(p+1,p+m+1);
        for(int i=1;i<=m;i++){
            sum[i]=sum[i-1]+p[i];
        }
        for(int i=1;i<=m;i++){
            int u=read(),v=read();
            g[u].push_back(v);g[v].push_back(u);
        }
        bfs(A,d[0]);bfs(B,d[1]);bfs(C,d[2]);
        ll mn=1LL<<60;
        for(int i=1;i<=n;i++){
            if(0LL+d[0][i]+d[1][i]+d[2][i]>m) continue;
            ll x=sum[d[1][i]]+sum[d[0][i]+d[1][i]+d[2][i]];
            mn=min(x,mn);
        }
        printf("%lld\n",mn);
    }
    return 0;
}