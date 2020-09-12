#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=1e9+7;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
vector<int> g[maxn];
ll a[maxn];
int top,n;
int dfs(int u,int fa){
    int x=1;
    for(auto v:g[u]){
        if(v==fa) continue;
        int now=dfs(v,u);
        x+=now;
        a[++top]=1LL*now*(n-now);
    }
    return x;
}
int p[maxn];
int main(){
    int t=read();
    while(t--){
        top=0;
        n=read();
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        sort(a+1,a+n);
        reverse(a+1,a+n);
        for(int i=1;i<=n-1;i++) a[i]%=mod;
        int ans=0;
        int m=read();
        for(int i=1;i<=m;i++) p[i]=read();
        sort(p+1,p+m+1);
        reverse(p+1,p+m+1);
        if(m<=n-1){
            for(int i=1;i<=n-1;i++){
          //      printf("%d %dasd\n",p[i],a[i]);
                if(i<=m) ans=(ans+1LL*p[i]*a[i])%mod;
                else ans=(ans+a[i])%mod;
            }
        }
        else{
            int now=1;
            for(int i=1;i<=m;i++){
                if(i<=m-(n-1)){
                    now=1LL*now*p[i]%mod;
                }
                else if(i==(m-(n-1))+1){
                    ans=(ans+1LL*now*p[i]%mod*a[i-m+n-1])%mod;
                }
                else ans=(ans+1LL*p[i]*a[i-m+n-1])%mod;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}