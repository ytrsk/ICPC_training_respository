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
int vis[1007][1007];
int gcd(int a,int b){
    if(vis[a][b]) return vis[a][b];
    else {
        int x=(b==0?a:gcd(b,a%b));
        vis[a][b]=x;
        return x;
    }
}
int dp[1007][1007];
int main(){
    int t=read();
    dp[1][1]=1;
    for(int i=1;i<=1000;i++) dp[1][i]=dp[i][1]=i;
    for(int i=2;i<=1000;i++)
    for(int k=2;k<=1000;k++){
        dp[i][k]=max(dp[i][k-1],dp[i-1][k])+(gcd(i,k)==1);
    }
    while(t--){
        int a=read(),b=read();
        printf("%d\n",dp[a][b]);
    }
    return 0;
}