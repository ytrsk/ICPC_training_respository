#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include <math.h>
#define mp make_pair
#define pii pair<int,int>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
const double inf = 1e9;
//d[i]-d[j]>=w add(j,i,w) maxlen min(d[i])
//d[i]-d[j]<=w add(j,i,w) minlen max(d[i])
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
double d[maxn],w[maxn];
int n,e1,nex[maxn],head[maxn],to[maxn],vis[maxn];
inline void addedge(int u,int v,double x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
inline bool dfs(int u){
    vis[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(d[v]<d[u]+w[i]){
            d[v]=d[u]+w[i];
            if(vis[v]) return true;
            if(dfs(v)) return true;
        }
    }
    vis[u]=0;
    return false;
}
inline void init(){
    for(int i=1;i<=n;i++) head[i]=0;e1=0;
}
int main(){
    n=26*26+5;init();
    //无超级原点，d设为0保证从正权值开始更新
    for(rint i=1;i<=n;++i) d[i]=vis[i]=0;
    int OK=0;
    for(int k=1;k<=n;k++){
        if(dfs(k)){
            OK=1;break;
        }
    }
    return 0;
}
