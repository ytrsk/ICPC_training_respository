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
        int n=read(),m=read(),you=0;
        printf("Case %d: ",++cnt);
        int sum1=0,sum2=0,a1=0,a2=0;
        for(int i=1;i<=n;i++){
            int x=read();
            if(x>0) you=1,sum1+=x,a1++;
            else sum2-=x,a2++;
        }
        if(!a1){
            printf("-1\n");continue;
        }
        if(!a2){
            printf("%.8f\n",1.0*sum1/a1);continue;
        }
        double px=1.0*sum1/a1,py=1.0*sum2/a2;
        dp[min(a2,m)]=(a1*px+max(a2-m,0)*py)/(n-a2);
        for(int i=min(a2,m)-1;i>=0;i--){
            dp[i]=a1*px/(n-i)+1.0*(a2-i)/(n-i)*(py+dp[i+1]);
        }
        printf("%.8f\n",dp[0]);
    }

    return 0;
}
