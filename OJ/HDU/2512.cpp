#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=2007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=1000;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
void del(int x,int y){
    x-=y;
    if(x<0) x+=mod;
}
short int dp[maxn][maxn],f[maxn][maxn];
int main(){
    int N=2000;dp[0][0]=1;
    for(int i=1;i<=N;i++){
        for(int k=1;k<=N;k++){
            dp[i][k]=(dp[i-1][k-1]+mul(k,dp[i-1][k]))%mod;
            f[i][k]=(f[i][k-1]+dp[i][k])%mod;
        }
    }
    int n=read();
    while(n--){
        int x=read();
        printf("%d\n",f[x][x]);
    }
    return 0;
}