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
int a[maxn];
int main(){
    int t=read();
    int cnt=0;
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        dp[n]=a[n];
        for(int i=n-1;i>=1;i--){
            dp[i]=0;
            for(int k=1;k<=min(n-i,6);k++){
                dp[i]+=dp[i+k];
            }
            dp[i]/=min(n-i,6);dp[i]+=a[i];
        }
        printf("Case %d: %.8f\n",++cnt,dp[1]);
    }
    return 0;
}
