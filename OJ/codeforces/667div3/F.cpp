#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[207],t[207];
int dp[207][207][207];
int main(){
    int n=read(),K=read();
    scanf("%s",s+1);scanf("%s",t+1);
    for(int i=0;i<=K;i++)
    for(int k=1;k<=n;k++)
    dp[0][i][k]=-inf;
    for(int i=1;i<=n;i++)
    for(int k=0;k<=K;k++)
    for(int z=0;z<=n;z++){
        dp[i][k][z]=-inf;
        if(z&&k>=(s[i]!=t[1])){
            dp[i][k][z]=(t[1]==t[2]?z-1:0)+dp[i-1][k-(s[i]!=t[1])][z-1];
        }
        if(k>=(s[i]!=t[2])){
            dp[i][k][z]=max(dp[i][k][z],dp[i-1][k-(s[i]!=t[2])][z]+z);
        }
        dp[i][k][z]=max(dp[i][k][z],dp[i-1][k][z]);
    }
    cout<<*max_element(dp[n][K],dp[n][K]+n+1);
    return 0;
}