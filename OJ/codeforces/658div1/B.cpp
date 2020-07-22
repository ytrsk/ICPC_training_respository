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
int p[4007];
int q[maxn],top,a[maxn],Top,Q[maxn],dp[maxn],R[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();top=Top=0;
        for(int i=1;i<=2*n;i++) a[i]=read();
        for(int i=2*n;i;i--){
            while(top&&a[i]>=a[q[top]]) top--;
            if(top) R[i]=q[top]-i;
            else R[i]=2*n+1-i;
            q[++top]=i;
        }
        int nex;
        for(int i=1;i<=2*n;i=nex){
            nex=i+1;int lim=i+R[i]-1,cnt=1;
            while(nex<=lim){
                lim=max(lim,nex+R[nex]-1);cnt++;nex++;
            }
            Q[++Top]=cnt;
        }
        for(int k=0;k<=n;k++) dp[k]=0;
        dp[0]=1;
        for(int i=1;i<=Top;i++){
            for(int k=n;~k;--k){
                if(k>=Q[i]) dp[k]|=dp[k-Q[i]];
            }
        }
        if(dp[n]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}