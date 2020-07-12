#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
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
ll a[maxn<<1];
ll sum[maxn<<1];
int main(){
    int t=read();
    while(t--){
        int n=read();ll m=read();
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=2*m;i++) sum[i]=0;
        for(int i=1;i<=n/2;i++){
            ll x=a[i],y=a[n-i+1];
            sum[x+y]-=2;sum[x+y+1]+=2;
            ll L=1+min(x,y),R=m+max(x,y);
            sum[L]-=1;sum[R+1]+=1;
            if(L<=x+y&&R>=x+y) sum[x+y]+=1,sum[x+y+1]-=1;
        }
        ll now=n,mx=inf;
        for(int i=1;i<=2*m;i++){
            now+=sum[i];
            mx=min(mx,now);
        }
        printf("%lld\n",mx);
    }
    return 0;
}