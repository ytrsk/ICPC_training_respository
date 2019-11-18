#include <stdio.h>
#include <algorithm>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=507;
const int inf=2e9;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,wx[maxn],wy[maxn],w[maxn][maxn],vis[maxn],p[maxn],slk[maxn],pre[maxn];
inline ll km(){
    for(int i=1;i<=n;i++){
        wx[i]=-inf;wy[i]=p[i]=0;
        for(int k=1;k<=n;k++)
            wx[i]=max(wx[i],w[i][k]);
    }
    for(int i=1;i<=n;i++){
        for(int k=0;k<=n;k++) vis[k]=pre[k]=0,slk[k]=inf;
        int now,nex=-1;
        for(p[now=0]=i;p[now];now=nex){
            int d=inf;
            vis[now]=1;
            int u=p[now];
            for(int k=1;k<=n;k++){
                if(!vis[k]){
                    int f;
                    if((f=wx[u]+wy[k]-w[u][k])<slk[k]) slk[k]=f,pre[k]=now;
                    if(slk[k]<d) d=slk[k],nex=k;
                }
            }
            for(int k=0;k<=n;k++){
                if(vis[k]) wx[p[k]]-=d,wy[k]+=d;
                else slk[k]-=d;
            }
        }
        for(;now;now=pre[now]) p[now]=p[pre[now]];
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=wx[i]+wy[i];
    return ans;
}
int main(){
   // freopen("test.in","r",stdin);
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++)
            for(int k=1;k<=n;k++)
            scanf("%d",&w[i][k]);
        printf("%lld\n",km());
    }
    return 0;
}
