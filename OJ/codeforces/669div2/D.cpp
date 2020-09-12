#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=300007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int top,q[maxn],Top,Q[maxn],h[maxn],dp[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) h[i]=read();
    for(int i=1;i<=n;i++){
        dp[i]=i-1;
        int ok=1;
        while(top&&h[q[top]]>=h[i]){
            if(ok) dp[i]=min(dp[i],dp[q[top]]+1);
            if(h[q[top]]==h[i]) ok=0;
            top--;
        }
        if(top&&ok) dp[i]=min(dp[i],dp[q[top]]+1);
        q[++top]=i;
        ok=1;
        while(Top&&h[Q[Top]]<=h[i]){
            if(ok) dp[i]=min(dp[i],dp[Q[Top]]+1);
            if(h[Q[Top]]==h[i]) ok=0;
            Top--;
        }
        if(Top&&ok) dp[i]=min(dp[i],dp[Q[Top]]+1);
        Q[++Top]=i;
    }
    printf("%d",dp[n]);
    return 0;
}