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
double dp[maxn];
int main(){
    int t=read();
    int cnt=0;
    while(t--){
        int n=read();
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            //dp[i]=i/n*dp[i]+(n-i)/n*dp[i+1]+1;
            dp[i]=dp[i+1]+1.0*n/(n-i);
        }
        printf("Case %d: %.8f\n",++cnt,dp[0]);
    }
    return 0;
}
