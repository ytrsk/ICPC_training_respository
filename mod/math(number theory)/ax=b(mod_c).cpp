#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
void exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;y=0;return;
	}
	exgcd(b,a%b,y,x);y-=x*(a/b);
}
long long gcd(long long x,long long y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	long long a,b,c,x,y,z;
	while(scanf("%lld%lld%lld%lld",&a,&b,&c,&z)==4){
		if(b%gcd(a,c)!=0){
			printf("-1\n");continue;
		}
		exgcd(a,c,x,y);x*=b/gcd(a,c);
		long long s=c/gcd(a,c);
		printf("%lld\n",(x%s+s)%s);
	}
	return 0;
}
