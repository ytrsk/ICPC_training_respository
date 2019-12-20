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
ll calc(ll a,ll b,ll c,ll n){
    if(a==0){
        return ((c/b)&1)?-n:n;
    }
    if(c>b){
        ll ans=calc(a,b,c%b,n);
        return ((c/b)&1)?-ans:ans;
    }
    cout<<a<<" "<<b<<" "<<c<<" "<<n<<endl;
    ll r=0,m=(a*n+c)/b;
    if(m>1) r=2*f(2*b,2*b-c-1,a,m/2-1);
    ll ans=n*(m%2)-f(b,b-c-1,a,m-1)+r;
    ans=n-2*ans;
    return ans;
}
int main(){
    int T=read();
    while(T--){
        ll n=read(),r=read();
        ll sr=(ll)sqrt(r);
        ll ans=calc(r*sr+r-sr*sr,r,0,n);
        cout<<ans<<"\n";
    }
    return 0;
}