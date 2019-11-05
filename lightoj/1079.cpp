#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int val[maxn];double w[maxn];
double dp[10007];
int main(){
    int t=read();
    int cnt=0;
    while(t--){
        memset(dp,0,sizeof(dp));
        double p;scanf("%lf",&p);int n=read();
        dp[0]=1;
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d%lf",&val[i],&w[i]);
            sum+=val[i];
        }
        for(int i=1;i<=n;i++){
            for(int k=sum;k>=val[i];k--){
                dp[k]=max(dp[k],dp[k-val[i]]*(1-w[i]));
            }
        }
        p=1-p;
        int ans=0;
        for(int i=1;i<=sum;i++){
            if(dp[i]>p+1e-7) ans=i;
        }
        printf("Case %d: %d\n",++cnt,ans);
    }
    return 0;
}
