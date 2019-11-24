#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int pre[57];
int main(){
    int t=read(),cnt=0;
    while(t--){
        ++cnt;
        int n=read(),m=read(),mod=read();
        m=min(n,m);
        pre[0]=1;for(int i=1;i<=n;i++) pre[i]=(1LL*pre[i-1]*i)%mod;
        int ans=1;
        if(n>m){
            if(n-m==2){
                ans=(ans+1)%mod;
            }
            else if(n-m>2) ans=(ans+1LL*(n-m)*(n-m-1)/2%mod+(n-m-1)*(n-m-2)/2%mod)%mod;
            ans=(ans+(1LL*(n-m)%mod)*m%mod)%mod;
            ans=(ans+n-m-1)%mod;
        }
        ans=(1LL*ans*pre[m])%mod;
        printf("Case #%d: %d\n",cnt,ans);
    }
    return 0;
}
