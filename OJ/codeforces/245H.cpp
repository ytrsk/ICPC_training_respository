#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=5007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
char s[maxn];
bool you[maxn][maxn];
int dp[maxn][maxn];
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=len;i;i--){
        you[i][i]=1;
        if(i<len&&s[i]==s[i+1]) you[i][i+1]=1;
        for(int k=i+2;k<=len;k++){
            if(you[i+1][k-1]&&s[i]==s[k]) you[i][k]=1;
        }
    }
    for(int i=len;i;i--){
        dp[i][i]=1;int x=1;
        for(int k=i+1;k<=len;k++){
            x+=you[i][k];
            dp[i][k]=dp[i+1][k]+x;
        }
    }
    int q=read();
    while(q--){
        int l=read(),r=read();
        printf("%d\n",dp[l][r]);
    }
    return 0;
}