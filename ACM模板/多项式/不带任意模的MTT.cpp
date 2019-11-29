#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
const int mod1=479*(1<<21)+1,G=3,mod2=998244353;
int rev[maxn<<2];
ll pown(ll a,ll b,int mod){
	if(b<0){
		b=-b;a=pown(a,mod-2,mod);
	}
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
void ntt(ll *a,int n,int dft,int mod){
	for(int i=0;i<n;i++)
	if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1){
		ll wn=pown(G,dft*(mod-1)/(i*2),mod);
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
		int inv1=pown(n,mod-2,mod);
		for(int i=0;i<n;i++) a[i]=(a[i]*inv1)%mod;
	}
}
void nttmul(ll *a,ll *b,int l1,int l2,int mod){
	int bit=1;
	while((1<<bit)<=l1+l2) bit++;
	for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	ntt(a,1<<bit,1,mod);ntt(b,1<<bit,1,mod);
	for(int i=0;i<(1<<bit);i++) a[i]=(a[i]*b[i])%mod;
	ntt(a,1<<bit,-1,mod);
}
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
ll a1[200007<<2],b1[200007<<2],a2[200007<<2],b2[200007<<2];
int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    int n;ll x;cin>>n>>x;
    nttmul(a1,b1,n,n,mod1);nttmul(a2,b2,n,n,mod2);
    for(int i=n+1;i<=2*n;i++){
        m[1]=mod1;r[1]=a1[i];
        m[2]=mod2;r[2]=a2[i];
        printf("%lld ",exchina(2));
    }
    return 0;
}
