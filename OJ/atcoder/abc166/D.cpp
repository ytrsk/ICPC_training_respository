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
ll s(ll x){return x*x*x*x*x;}
map<ll,int> aa;
int main(){
    ll n;cin>>n;
    for(ll i=0;s(i)<=1e18;i++) aa[s(i)]=i;
    for(ll i=0;-s(i)<=1e18;i--) aa[s(i)]=i;
    for(ll i=0;s(i)<=1e18;i++){
        if(aa[n+s(i)]){
            cout<<aa[n+s(i)]<<" "<<i;return 0;
        }
    }
    for(ll i=0;-s(i)<=1e18;i--){
        if(aa[n+s(i)]){
            cout<<aa[n+s(i)]<<" "<<i;return 0;
        }
    }
    return 0;
}