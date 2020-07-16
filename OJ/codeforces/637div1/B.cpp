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
char s[13][10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
char ss[2007][13];
int df(char *a,char *b){
    int sum=0;
    for(int i=0;i<7;i++){
        if(b[i]=='0'&&a[i]=='1') sum++;
        else if(b[i]=='1'&&a[i]=='0') return -1;
    }
    return sum;
}
int val[2007][2007],dp[2007][2007],p[2007][2007];
int main(){
    int n=read(),K=read();
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        scanf("%s",ss[i]);
        for(int k=0;k<=9;k++) val[i][k]=df(s[k],ss[i]);
    }
    dp[n+1][0]=1;
    for(int i=n;i>=1;i--){
        for(int k=9;k>=0;k--){
            if(val[i][k]==-1) continue;
            for(int z=val[i][k];z<=K;z++){
                if(!dp[i][z]&&dp[i+1][z-val[i][k]]){
                    dp[i][z]=1;p[i][z]=k;
                }
            }
        }
    }
    int x=1,y=K;
    if(!dp[x][y]) printf("-1");
    else{
        while(x!=n+1){
            printf("%d",p[x][y]);
            y-=val[x][p[x][y]];x++;
        }
    }
    return 0;
}