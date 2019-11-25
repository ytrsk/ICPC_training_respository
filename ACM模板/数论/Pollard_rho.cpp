#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
vector<ll> fac;
ll gcd(ll a,ll b){
	if(a<0) return gcd(-a,b);
	return b==0?a:gcd(b,a%b);
}
ll powm(ll a,ll b,ll mod){
	ll ans=0;
	while(b){
		if(b&1) ans=(ans+a)%mod;
		a=(a<<1)%mod;
		b>>=1;
	}
	return ans;
}
ll pown(ll a,ll b,ll mod){
	ll ans=1;
	while(b){
		if(b&1) ans=powm(ans,a,mod);
		a=powm(a,a,mod);
		b>>=1;
	}
	return ans;
}
bool miller_rabin(ll n){
	if(n==2) return true;
	if(n<2||!(n%2)) return false;
	long long ind=n-1,last,x;
	int cnt=0;
	while(ind%2==0){
		++cnt;
		ind>>=1;
	}
	for(int i=1;i<=20;i++){
		x=pown(rand()%(n-2)+2,ind,n);last=x;
		for(int k=1;k<=cnt;k++){
			x=powm(x,x,n);
			if(x==1&&last!=1&&last!=n-1) return false;
			last=x;
		}
		if(x!=1) return false;
	}
	return true;
}
ll pollard_rho(ll n,ll c){
	ll l=1,r=2;
	ll x=rand()%n,last=x;
	while(1){
		l++;x=(powm(x,x,n)+c)%n;
		ll d=gcd(last-x,n);
		if(1<d&&d<n) return d;
		if(last==x) return n;
		if(l==r){
			last=x;
			r<<=1;
		}
	}
}
void find(ll n){
	if(miller_rabin(n)){
		fac.push_back(n);return;
	}
	ll p=n;
	while(p==n) p=pollard_rho(p,rand()%(n-1)+1);;
	find(p);
	find(n/p);
}
int main(){
	ll n;
	while(scanf("%lld",&n)==1){
		fac.clear();if(n>1) find(n);
		cout<<fac.size()<<"\n";
	}
	return 0;
}
