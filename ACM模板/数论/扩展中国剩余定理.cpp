#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=500007;
ll m[maxn],r[maxn];
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;return a;
	}
	else{ll gcd=exgcd(b,a%b,y,x);y-=x*(a/b);return gcd;}
}
ll powm(ll a,ll b,ll mod){
	ll ans=0;
	while(b){
		if(b&1) ans=(ans+a)%mod;
		a=(a<<1)%mod;
		b>>=1;
	}
	return (ans+mod)%mod;
}
ll exchina(int n){
	ll x,y;ll tot=m[1],ans=r[1];
	for(int i=2;i<=n;i++){
		ll a=tot,b=m[i],c=(r[i]-ans%m[i]+m[i])%m[i];
		ll gcd=exgcd(a,b,x,y);
		if(c%gcd!=0) return -1;
		x=powm(x,c/gcd,b/gcd);
		ans+=x*tot;
		tot*=(b/gcd);
		ans=(ans%tot+tot)%tot;
	}
	return ans;
}
int main(){
	int n;while(scanf("%d",&n)==1){
		for(int i=1;i<=n;i++) scanf("%lld%lld",&m[i],&r[i]);ll ans=exchina(n);
		printf("%lld\n",ans);
	}
	return 0;
}
