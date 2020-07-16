#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <complex>
using namespace std;
typedef long long ll;
const int maxn=200007;
const int mod=998244353,G=3;
int rev[maxn<<2];
ll pown(ll a,ll b){
	if(b<0){
		b=-b;a=pown(a,mod-2);
	}
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
void ntt(ll *a,int n,int dft){
	for(int i=0;i<n;i++)
	if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1){
		ll wn=pown(G,dft*(mod-1)/(i*2));
		for(int k=0;k<n;k+=i<<1){
			ll wnk=1;
			for(int j=k;j<k+i;j++){
				int x=a[j],y=(wnk*a[j+i])%mod;
				a[j]=(x+y)%mod;a[j+i]=(x-y+mod)%mod;
				wnk=(wnk*wn)%mod;
			}
		}
	}
	if(dft==-1){
		int inv1=pown(n,mod-2);
		for(int i=0;i<n;i++) a[i]=(a[i]*inv1)%mod;
	}
}
void nttmul(ll *a,ll *b,int l1,int l2){
	int bit=1;
	while((1<<bit)<=l1+l2) bit++;
	for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	for(int i=l1+1;i<(1<<bit);i++) a[i]=0;
	for(int i=l2+1;i<(1<<bit);i++) b[i]=0;
	ntt(a,1<<bit,1);ntt(b,1<<bit,1);
	for(int i=0;i<(1<<bit);i++) a[i]=(a[i]*b[i])%mod;
	ntt(a,1<<bit,-1);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
    }
	return 0;
}
