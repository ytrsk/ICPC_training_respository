#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll dp[2][1<<7][8],pre[2][1<<7];
int a[maxn],id[maxn],you[maxn][7];
bool cmp(int x,int y){
    return a[x]>a[y];
}
int y[1<<7];
int main(){
    int n=read(),p=read(),K=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) id[i]=i;
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<=n;i++) for(int k=0;k<p;k++) you[i][k]=read();
    ll yy=0;
    memset(pre[0],-127/3,sizeof(pre[0]));
    pre[0][0]=0;
    for(int i=1;i<=K;i++){
        yy+=a[id[i]];
        int now=i&1,las=now^1;
        memset(pre[now],-127/3,sizeof(pre[now]));
        for(int k=0;k<(1<<p);k++){ 
            for(int z=0;z<p;z++){   
                if(!(k>>z&1))
                pre[now][k|(1<<z)]=max(pre[now][k|(1<<z)],pre[las][k]-a[id[i]]+you[id[i]][z]);
            }
        }
    }
    memset(dp[K&1],-127/3,sizeof(dp[K&1]));
    for(int i=0;i<(1<<p);i++){
        y[i]=y[i>>1]+(i&1);
        dp[K&1][i][y[i]]=pre[K&1][i];    
      //  cout<<pre[K&1][i]<<endl;
   //     cout<<dp[K&1][i][y[i]]<<endl;
    }
    for(int i=K+1;i<=n;i++){
        int now=i&1,las=now^1;
        memset(dp[now],-127/3,sizeof(dp[now]));
        for(int k=0;k<(1<<p);k++){
            for(int z=0;z<p;z++)  
            if(!(k>>z&1))
            for(int j=0;j<=p;j++){
               dp[now][k|(1<<z)][j]=max(dp[now][k|(1<<z)][j],dp[las][k][j]+you[id[i]][z]);
            }
        }
        for(int k=0;k<(1<<p);k++){
            for(int j=0;j<=p;j++){
                if(j) dp[now][k][j-1]=max(dp[now][k][j-1],dp[las][k][j]+a[id[i]]);
                dp[now][k][j]=max(dp[now][k][j],dp[las][k][j]);
            }
        }
    }
    ll ans=-0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<=p;i++) ans=max(ans,dp[n&1][(1<<p)-1][0]);
    cout<<ans+yy;
    return 0;
}