#include <bits/stdc++.h>
#define mp make_pair
#define re register
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
const int mod=1e9+7;
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
int a[1<<16];
int dp[17][17][1<<16];
int dp0[17][17];
void dec(int &x,int y){
    x-=y;
    if(x<0) x+=mod;
}
int dp1[17][17];
int ans[17],now[17];
int you[1<<16];
int mul(int x,int y){
    return 1LL*x*y%mod;
}
int main(){
    int n=16,m=16;
    for(int i=1;i<=n;i++){
        dp[i][0][(1<<i)-1]=1;
        for(int z=0;z<1<<i;z++){
            a[z]=1;
            for(int j=0;j<i;j++){
                if(z>>j&1){
                    if(!(j+1<i&&z>>(j+1)&1)) a[z]=0;
                    else j++;
                }
            }
        }
        for(int k=1;k<=m;k++){
            dp[i][k][0]=dp[i][k-1][(1<<i)-1];
            for(int re j=1;j<(1<<i);++j){
                for(int re z=j;;z=(z-1)&j){
                    if(a[j^z]) add(dp[i][k][j],dp[i][k-1][((1<<i)-1)^z]);
                    if(z==0) break;
                }
            }
            dp0[i][k]=dp[i][k][(1<<i)-1];
        }
    }
    for(int i=1;i<1<<16;i++) you[i]=you[i>>1]+(i&1);
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            int tot=0;
            for(int z=0;z<(1<<(k-1));z++){
                now[0]=1;ans[0]=1;
                for(int j=1;j<=i;j++){
                    now[j]=1;int last=-1;
                    for(int e=0;e<k-1;e++){
                        if(z>>e&1){
                            now[j]=mul(now[j],dp0[j][e-last]);
                            last=e;
                        }
                    }
                    now[j]=mul(now[j],dp0[j][k-1-last]);
                    ans[j]=now[j];
                    for(int e=1;e<j;e++){
                        dec(ans[j],mul(now[j-e],ans[e]));
                    }
                }
                if(you[z]&1) dec(tot,ans[i]);
                else add(tot,ans[i]);
            }
            printf("dp[%d][%d]=%d;\n",i,k,tot);
        }
    }
    return 0;
}