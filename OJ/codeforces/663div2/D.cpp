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
char s[1000007];
int dp[1000007][1<<3];
int a[1000007];
int num[1<<3];
int ban[1<<3][1<<3];
int main(){
    for(int i=0;i<(1<<3);i++) num[i]=num[i>>1]+(i&1);
    int n=read(),m=read();
    if(n>=4&&m>=4){
        printf("-1");return 0;
    }
    if(n==1||m==1){
        printf("0");return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        if(n>m){
            for(int k=0;k<m;k++) if(s[k]-'0') a[i]^=(1<<k);
        }
        else{
            for(int k=1;k<=m;k++) if(s[k-1]-'0') a[k]^=(1<<(i-1));
        }
    }
    if(n<=m) swap(n,m);
    for(int k=0;k<(1<<m);k++) dp[1][k]=num[k^a[1]];
    for(int i=0;i<(1<<m);i++){
        for(int k=0;k<(1<<m);k++){
            if(m>=2&&num[((i&3)^(k&3))]%2==0) ban[i][k]=1;
            if(m>=3&&num[((i&6)^(k&6))]%2==0) ban[i][k]=1;
            //cout<<i<<" "<<k<<" "<<ban[i][k]<<endl;
        }
    }
    int ans=inf;
    for(int i=2;i<=n;i++){
        for(int k=0;k<(1<<m);k++){
            dp[i][k]=inf;
            for(int z=0;z<(1<<m);z++){
                if(!ban[k][z])
                dp[i][k]=min(dp[i][k],dp[i-1][z]+num[k^a[i]]);
        //        if(dp[i][k]==1&&i==n) printf("asd %d %d %d %d %d\n",k,z,num[k^a[i]],dp[i-1][z],dp[2][4]);
          //      if(i==2&&k==4&&dp[i][k]==1) cout<<z<<endl;
            }
            if(i==n) ans=min(ans,dp[i][k]);
        }
    }
    printf("%d",ans==inf?-1:ans);
    return 0;
}