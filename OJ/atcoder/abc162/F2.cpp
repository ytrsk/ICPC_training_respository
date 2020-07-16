#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll a[maxn];
ll dp[maxn][11],Sum;
int main(){

    int n=read();
    for(int i=1;i<=n;i++) a[i]=read(),Sum+=a[i];
    memset(dp,0x3f,sizeof(dp));  
    dp[0][5]=0;
    dp[1][6]=a[1];
    for(int i=2;i<=n+1;i++){
        for(int k=0;k<=10;k++){
            int now=i/2+k-5;
            if(now>=1){
                int p1=now-1-(i-1)/2+5;
                int p2=now-1-(i-2)/2+5;
                if(p1>10||p2>10||p1<0||p2<0) continue;
                dp[i][k]=min(dp[i-1][p1],dp[i-2][p2])+a[i];
            }
        }
    }
    int you=n-(n/2)+1;
    int p=you-(n+1)/2+5;
    cout<<Sum-dp[n+1][p];
    return 0;
}