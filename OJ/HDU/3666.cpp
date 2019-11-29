#include <stdio.h>
#include <string.h>
#include <algorithm>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
#pragma GCC optimize(3,"Ofast","inline")
const int maxn=400007;
const double inf=1e9;
//d[i]-d[j]>=w add(j,i,w) maxlen min(d[i])
//d[i]-d[j]<=w add(j,i,w) minlen max(d[i])
inline int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
double w[maxn],d[maxn];
int n,e1,nex[maxn],head[maxn],to[maxn],inq[maxn],cnt[maxn],s;
inline void addedge(int u,int v,double x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
int q[407*407];
inline bool spfa(){
    for(register int i=1;i<=n;++i) inq[i]=cnt[i]=0,d[i]=-inf;
    inq[s]=1;d[s]=0;
    int ql=1,qr=0;q[++qr]=s;
    while(ql<=qr){
        int u=q[ql++];inq[u]=0;
        for(register int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(d[v]<d[u]+w[i]){
                d[v]=d[u]+w[i];
                if(!inq[v]){
                    inq[v]=1;q[++qr]=v;
                    cnt[v]++;
                    if(cnt[v]>=4){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
void init(){
    for(register int i=1;i<=n;++i) head[i]=0;e1=0;
    for(register int i=1;i<n;++i) addedge(s,i,0);
}
int a[407][407];
int main(){
    int N,M,L,U;
    while(scanf("%d%d%d%d",&N,&M,&L,&U)==4){
        for(register int i=1;i<=N;++i)
        for(register int k=1;k<=M;++k){
            a[i][k]=read();
        }
        double LL=log(L*1.0),UU=log(U*1.0);
        n=N+M+1;s=n;init();
        for(register int i=1;i<=N;++i)
            for(register int k=1;k<=M;++k){
                double x=log(1.0*a[i][k]);
                addedge(N+k,i,LL-x);
                addedge(i,N+k,x-UU);
            }
        if(spfa()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
