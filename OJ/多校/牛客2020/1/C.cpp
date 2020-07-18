#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[1007][1007];
int ans[2][1007][1007];
int you[1007];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        for(int i=0;i<2;i++){
            for(int k=1;k<=n;k++) scanf("%s",s[k]+1);
            for(int k=1;k<=m;k++) you[k]=0;
            ans[i][1][1]=0;
            for(int k=1;k<=n;k++){
                int ok=0;
                for(int z=1;z<=m;z++){
                    if(s[k][z]=='-'){
                        ans[i][k][z+1]=ans[i][k][z]+(k+z&1?1:-1);
                        if(ok==0) ans[i][k+1][z]=ans[i][k][z]+(k+z&1?-1:1);
                        else ans[i][k+1][z]=ans[i][k][z]+(k+z&1?3:-3);
                        ok^=1;
                    }
                    else{
                        ok=0;                     
                        if(!you[z]) ans[i][k][z+1]=ans[i][k][z]+(k+z&1?1:-1);
                        else ans[i][k][z+1]=ans[i][k][z]+(k+z&1?-3:3);
                        ans[i][k+1][z]=ans[i][k][z]+(k+z&1?-1:1);
                        you[z]^=1;
                    }
                }
            }

            ans[i][n+1][m+1]=ans[i][n+1][m]+(n+m&1?-1:1); 
        }
        int Ans=0;
        for(int i=1;i<=n+1;i++){
            for(int k=1;k<=m+1;k++){
                Ans+=abs(ans[0][i][k]-ans[1][i][k]);
            }
        }
        Ans/=4;
        printf("%d\n",Ans);
    }
    return 0;
}