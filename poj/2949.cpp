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
double d[maxn],w[maxn],aver;
int n,e1,nex[maxn],head[maxn],to[maxn],inq[maxn],cnt[maxn],s;
inline void addedge(int u,int v,double x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
int q[200007],vis[200007];
inline bool dfs(int u){
    vis[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(d[v]<d[u]+w[i]-aver){
            d[v]=d[u]+w[i]-aver;
            if(vis[v]) return true;
            if(dfs(v)) return true;
        }
    }
    vis[u]=0;
    return false;
}
/*inline bool spfa(){
    for(int i=1;i<=n;i++) inq[i]=cnt[i]=0,d[i]=-inf;
    int ql=1,qr=0;q[++qr]=n;
    inq[n]=1;d[n]=0;
    while(ql<=qr){
        register int u=q[ql++];inq[u]=0;
        for(register int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(d[v]<d[u]+w[i]){
                d[v]=d[u]+w[i];
                if(!inq[v]){
                    inq[v]=1;q[++qr]=v;
                    cnt[v]++;
                    if(cnt[v]>n){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}*/
inline void init(){
    for(int i=1;i<=n;i++) head[i]=0;e1=0;
    for(int i=1;i<n;i++) addedge(s,i,0);
}
int a[maxn];
char S[maxn];
inline int id(int x,int y){
    return x*26+y+1;
}
struct point{
    int x,y,len;
}p[maxn];
int main(){
  //  cin.tie(0);ios_base::sync_with_stdio(false);
    int N;
    while(scanf("%d",&N)==1&&N){
        for(int i=1;i<=N;i++){
            scanf("%s",S+1);
            int len=strlen(S+1);
            int x=id(S[1]-'a',S[2]-'a'),y=id(S[len-1]-'a',S[len]-'a');
            p[i].x=x;p[i].y=y;p[i].len=len;
        }
        double l=0,r=1007;int ok=0;
        n=26*26+5;for(int i=1;i<=n;i++) head[i]=0;
        for(int i=1;i<=N;++i) addedge(p[i].x,p[i].y,p[i].len);
        for(int i=1;i<=20;i++){
            double mid=(l+r)/2;aver=mid;
            for(register int k=1;k<=n;++k) d[k]=0,vis[k]=0;
            int OK=0;
            for(int k=1;k<=n;k++){
                if(dfs(k)){
                    OK=1;break;
                }
            }
            if(OK) l=mid,ok=1;
            else r=mid;
        }
        if(ok) printf("%.3f\n",l);
        else printf("No solution.\n");
    }
    return 0;
}
