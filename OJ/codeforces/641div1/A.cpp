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
}int a[200007],suf[maxn],pre[maxn];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int n=read();
    ll ans=0;
    rep(i,1,n){
        a[i]=read();
        pre[i]=gcd(pre[i-1],a[i]);
    }
    dep(i,n,1){
        suf[i]=gcd(suf[i+1],a[i]);
    }
    rep(i,1,n){
        int x=gcd(pre[i-1],suf[i+1]);
        ll now=1LL*x*a[i]/gcd(x,a[i]);
        ans=gcd(ans,now);
    }
    cout<<ans;
    return 0;
}