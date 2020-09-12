#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int X[maxn],Y[maxn];
int dp[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read(),K=read();
        for(int i=1;i<=n;i++) X[i]=read();
        for(int i=1;i<=n;i++) Y[i]=read();
        sort(X+1,X+n+1);
        int l=1,r=1,mx=0;
        while(r<=n){
            while(X[r]-X[l]>K) ++l;
            dp[r]=max(dp[r-1],r-l+1);
            mx=max(mx,max(dp[r],dp[l-1]+r-l+1));
            ++r;
        }
        printf("%d\n",mx);
    }
    return 0;
}