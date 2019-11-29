#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;return;
	}
	exgcd(b,a%b,y,x);y-=x*(a/b);
}
ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}
ll calc(ll a,ll b,ll c){
	if(a==0){
		return b==0?-2:-1;
	}
	ll x,y;
	if(b%gcd(a,c)!=0) return -1;
	exgcd(a,c,x,y);x*=b/gcd(a,c);
	ll s=c/gcd(a,c);
	return (x%s+s)%s;
}
