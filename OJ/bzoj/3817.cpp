#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
const int mod=998244353;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll f(ll a,ll b,ll c,ll n){
    if(a==0){
        return b/c*(n+1);
    }
    if(a<c&&b<c){
        ll m=(a*n+b)/c;
        return n*m-f(c,c-b-1,a,m-1);
    }
    return (a/c)*n*(n+1)/2+(b/c)*(n+1)+f(a%c,b%c,c,n);
}
ll F(ll a,ll b,ll c,ll n){
    ll x=(-b-1)/c+1;
    if(x>n) return 0;
    n-=x;
    b+=x*c;
    return f(a,b,c,n);
}
ll calc(ll a,ll b,ll c,ll n){
    ll r=0,m=(a*n+c)/b;
    if(m) r=-2*f(2*b,b-c-1,a,(m-1)/2);
    ll ans=n*(m%2)+F(b,-c-1,a,m)+r;
    return ans;
}
int main(){
    int T=read();
    while(T--){
        ll n=read(),r=read();
        ll sr=(ll)sqrt(r);
        ll ans=calc(r*sr,r,r-sr*sr,n);
        cout<<ans<<"\n";
    }
    return 0;
}