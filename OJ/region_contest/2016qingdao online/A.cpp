#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0) {x=1,y=0;}
    else
    {
        exgcd(b,a%b,y,x);
        y-=x*(a/b);
    }
}

ll mod_inverse(ll a){
	ll x,y;
	exgcd(a,mod,x,y);
	return (mod+x%mod)%mod;
}

ll qpow(ll a,ll b){
    ll ans=1;
    ll k=a;
    while(b){
        if(b&1)ans=ans*k%mod;
        k=k*k%mod;
        b>>=1;
    }
    return ans;
}

ll n,m;

int main()
{
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%lld%lld",&n,&m);
		ll ans=qpow(2,n)-1;
		ll t=n,tt=1;
		for(int i=1;i<m;i++)
		{
			ans=(ans-t*mod_inverse(tt)%mod+mod)%mod;
			t=(t*(n-i))%mod;
			tt=(tt*(i+1))%mod;
		}
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}
