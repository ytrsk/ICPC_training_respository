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
int dp[maxn];
int main(){
    dp[1]=0;int n=read();
    for(int i=2;i<=n;i++){
        if(i%2) dp[i]=!dp[i/2]||!dp[i/2+1];
        else dp[i]=!dp[i/2];
        printf("%d %d\n",i,dp[i]);
    }
    return 0;
}