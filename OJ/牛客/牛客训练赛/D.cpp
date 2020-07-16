#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[maxn][maxn];
int a[maxn][maxn],dp[maxn][maxn];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(s[i][k]=='0') a[i][k]=1;
        }
    }
    memset(dp,127/3,sizeof(dp));
    dp[1][1]=0;
    for(int i=1;i<=n;i++)
    for(int k=1;k<=m;k++){
        if(i==1&&k==1||!a[i][k]) continue;
        if(i>=2){
            if(k+1<=m) dp[i][k]=dp[i-1][k]+a[i-1][k+1];
            else dp[i][k]=dp[i-1][k];
        }
        if(k>=2){
            dp[i][k]=min(dp[i][k],dp[i][k-1]);
        }
    }
    if(dp[n][m]>2*n*m) printf("-1");
    else printf("%d",dp[n][m]);
    return 0;
}