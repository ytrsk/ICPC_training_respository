#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f3f3f3f3f;
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
ll a[maxn],b[maxn];
pair<long long,long long> dp[507][507];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read(),b[i]=read();
    for(int k=0;k<=n;k++) for(int i=0;i<m;i++) dp[k][i]=mp(-inf,0);
    dp[0][0]=mp(0,0);
    for(int i=1;i<=n;i++){
        for(register int k=0;k<=min(a[i],1LL*m);++k){
            ll x=(a[i]-k)/m,y=b[i],ans,nex,Nex;
            if(y+(a[i]-k)%m>=m) y-=(m-(a[i]-k)%m),x++;
            x+=y/m;y%=m;
            for(register int z=0;z<m;++z){
                ans=x,nex=k+z,Nex=y+dp[i-1][z].second;
                if(Nex>=m) Nex-=m,ans++;
                if(nex>=m) nex-=m,ans++;
                dp[i][nex]=max(dp[i][nex],mp(dp[i-1][z].first+ans,Nex));
            }
        }
    }
    ll mx=0;
    for(int i=0;i<m;i++){
        mx=max(mx,dp[n][i].first);
    }
    cout<<mx;
    return 0;
}