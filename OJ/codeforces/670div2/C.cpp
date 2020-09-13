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
int val[maxn],mx,n,sz[maxn];
void dfs(int u,int fa){
    sz[u]=1;val[u]=0;
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u);sz[u]+=sz[v];
        val[u]=max(val[u],sz[v]);
    }
    val[u]=max(val[u],n-sz[u]);
    mx=min(mx,val[u]);
}
int main(){
    int t=read();
    while(t--){
        n=read();
        mx=inf;
        int L,R;
        rep(i,1,n) g[i].clear();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            g[u].push_back(v);
            g[v].push_back(u);
            L=u,R=v;
        }
        dfs(1,0);
        int now1=0,now2=0;
        rep(i,1,n) if(val[i]==mx){
            if(!now1) now1=i;
            else if(!now2) now2=i;
        }
        if(!now2){
            printf("%d %d\n%d %d\n",L,R,L,R);
        }
        else{
            L=0;
            for(auto v:g[now2]) if(v!=now1){
                L=v;
            }
            printf("%d %d\n%d %d\n",now2,L,now1,L);
        }
    }
    return 0;
}