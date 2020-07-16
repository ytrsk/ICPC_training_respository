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
int dp[57][57][2507];
int p1[57][57][2507],p2[57][57][2507];
int A[57][57],you[57],You[57];
int main(){
    dp[0][0][0]=1;
    for(int i=1;i<=50;i++){
        for(int k=0;k<=i;k++){
            for(int z=0;z<=k*i;z++){
                for(int r=1;r*i<=z&&r<=k;r++){
                    if(dp[i-1][k-r][z-r*i]){
                        dp[i][k][z]=1;
                        p1[i][k][z]=i;
                        p2[i][k][z]=r;
                    }
                }
            }
        }
    }
    int t=read(),cnt=0;
    while(t--){
        printf("Case #%d: ",++cnt);
        int n=read(),K=read();
        memset(A,-1,sizeof(A));
        int top=1;
        if(dp[n][n][K]){
            int x=n,y=n,z=K;
            while(x){
                int now1=p1[x][y][z],now2=p2[x][y][z];
                for(int i=1;i<=n;i++) you[i]=You[i]=0;
                for(int i=top;i<=top+now2-1;i++) A[i][i]=x,you[i]=You[i]=1;
                top+=now2;
                for(int i=1;i<=n;i++){
                    if(!you[i]){
                        for(int k=1;k<=n;k++){
                            printf("%d %d %d %d\n",i,k,x,A[i][k]);
                            if(!You[k]&&A[i][k]==-1&&i!=k){
                                A[i][k]=x;You[k]=1;
                                break;
                            }
                        }
                    }
                }
                x-=1;y-=now2;z-=now1*now2;
            }
            printf("POSSIBLE\n");
            for(int i=1;i<=n;i++){
                for(int k=1;k<=n;k++) printf("%d ",A[i][k]);
                printf("\n");
            }
        }
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}