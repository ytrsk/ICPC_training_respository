#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

inline LL Get_Int() {
	LL num=0,bj=1;
	char x=getchar();
	while(!isdigit(x)) {if(x=='-')bj=-1;x=getchar();}
	while(isdigit(x)) {num=num*10+x-'0';x=getchar();}
	return num*bj;
}

const LL mod=1e9+7;

LL n,k;

int main() {
	n=Get_Int();
	k=Get_Int();
	LL next=0,sum=(k+n-1)%mod;
    if(n>=2)
	for(LL i=2;i<=min(n,k); i=next+1) {
	//	if(n/i==0)break;
		next=min(k,n/(n/i));
		sum=(sum+1ll*(n/i)*(next-i+1)%mod)%mod;
	}
    if(n-1>=2)
	for(LL i=2; i<=min(n-1,k); i=next+1) {
        //if((n-1)%i==0) break;
		next=min(k,(n-1)/((n-1)/i));
		sum=(sum+1ll*((n-1)/i)*(next-i+1)%mod)%mod;
	}
    for(LL)
	printf("%lld\n",sum);
	return 0;
}
