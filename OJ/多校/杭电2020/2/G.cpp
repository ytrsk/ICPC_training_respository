#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1LL<<60;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],n,m;
ll A[maxn<<1],B[maxn<<1];int sz[maxn];
ll dp[maxn][21],tot,res[21];
void addedge(int u,int v,int a,int b){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;A[e1]=a;B[e1]=b;   
}
void dfs(int u,int fa){
    sz[u]=1;
    dp[u][0]=0;
    for(int i=1;i<=m;i++) dp[u][i]=inf;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        for(int k=0;k<=m;k++) res[k]=inf;
        for(int k=min(sz[u]-1,m);~k;--k)
        for(int j=min(m-k,sz[v]-1);~j;--j){
            if(dp[u][k]+dp[v][j]<=tot){
              //     if(u==2&&v==4&&k==0&&j==0) cout<<dp[v][j]<<" "<<dp[u][k]<<" "<<A[i]<<endl;
                if(dp[u][k]+dp[v][j]+B[i]<=tot) res[k+j]=min(res[k+j],max(dp[u][k],dp[v][j]+B[i]));
                if(k+j+1<=m&&dp[u][k]+dp[v][j]+A[i]<=tot){
                    res[k+j+1]=min(res[k+j+1],max(dp[u][k],dp[v][j]+A[i]));
                //    if(u==2&&v==4&&k==0&&j==0) cout<<"asd"<<endl;
                }
            }
        }
        for(int k=0;k<=m;k++) dp[u][k]=res[k];
        sz[u]+=sz[v];
    }
 //   if(u==3) cout<<dp[2][0]<<endl;
}
int main(){
    int t=read();
    while(t--){
        n=read(),m=read();e1=0;
        for(int i=1;i<=n;i++) head[i]=0;
        for(int i=1;i<n;i++){
            int u=read(),v=read(),a=read(),b=read();
            addedge(u,v,a,b);addedge(v,u,a,b);
        }
        ll l=0,r=1e15,ans=0;
        while(l<=r){
            ll mid=(l+r)>>1;
            tot=mid;
            dfs(1,0);
            if(dp[1][m]!=inf) r=mid-1,ans=mid;
            else l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}