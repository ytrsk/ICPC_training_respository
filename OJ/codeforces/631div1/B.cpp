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
int a[maxn];
int dp[37];
int main(){
    int t=read();
    while(t--){
        int top=-1;
        int D=read(),m=read();
        for(int i=30;~i;--i){
            if(D>>i&1){
                top=i;break;
            }
        }
        dp[0]=1;
        int x=1;
        int ans=0;
        for(int i=1;i<=top+1;i++){
            dp[i]=0;
            if(i==top+1) x=(D-x+1);
            for(int k=0;k<i;k++){
                dp[i]=(dp[i]+1LL*x*dp[k])%m;
            }
            ans=(ans+dp[i])%m;
            x=(x*2)%m;
        }
        printf("%d\n",ans);
    }
    return 0;
}