#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
#pragma GCC optimize(3,"Ofast","inline")
const int maxn=200007;
const ll inf=(1LL<<60);
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
int n,e1,nex[maxn],head[maxn],to[maxn],w[maxn],inq[maxn],cnt[maxn],s;
ll d[maxn];
inline void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
typedef pair<long long ,int> pli;
inline bool spfa(){
    priority_queue<pli,vector<pli>,greater<pli>> q;q.push(mp(0,s));
    for(int i=1;i<=n;i++) inq[i]=0,d[i]=inf;
    d[s]=0;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(inq[u]) continue;
        inq[u]=1;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(d[v]>d[u]+w[i]){
                d[v]=d[u]+w[i];
                q.push(mp(d[v],v));
            }
        }
    }
    return true;
}
inline void init(){
    for(int i=1;i<=n;i++) head[i]=0;e1=0;
    //for(int i=1;i<n;i++) addedge(s,i,0);
}
pii a[maxn];
int now[maxn];
int main(){
    int N=read(),x=read();
    s=1;n=N;init();
    for(int i=1;i<=x;i++){
        int a=read(),b=read(),c=read();
        addedge(a,b,c);
    }spfa();
    printf("%lld\n",d[n]);
    return 0;
}
