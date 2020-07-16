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
ll a[maxn],b[maxn];
int main(){
    ll ans=-1;
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    ll l=1,r=1e18;
    while(l<=r){
        ll mid=(l+r)>>1;
        ll pos=mid%n;
        rep(i,1,n){
            b[i]=a[i]+(i<=pos);
        }
        nth_element(b+1,b+(n+1)/2,b+n+1);
        ll sum=0;
        rep(i,1,n) sum+=abs(b[i]-b[(n+1)/2]);
        if(sum<=mid) r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}