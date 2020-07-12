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
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
ll suan(ll x,ll a, ll b){
    ll now=x/b;
    ll ans=(now/a+1)*b;
    if(now%a==0) (ans-=b)+=x%b+1;
    return ans;
}
int main(){
    int t=read();
    while(t--){
        int a=read(),b=read(),q=read();
        if(a>b) swap(a,b);
        ll g=gcd(a,b);
        while(q--){
            ll l=read(),r=read();
            if(a==b){
                printf("0 ");
            }
            else{
                ll ans=a/g;
                printf("%lld ",(r-l+1)-(suan(r,ans,b)-suan(l-1,ans,b)));
            }
        }
        printf("\n");
    }
    return 0;
}