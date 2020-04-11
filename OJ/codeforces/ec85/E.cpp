#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac;
inline ll gcd(ll a,ll b){
	if(a<0) return gcd(-a,b);
	return b==0?a:gcd(b,a%b);
}
inline ll powm(ll a,ll b,ll mod){
	ll ans=0;
	while(b){
		if(b&1) ans=(ans+a)%mod;
		a=(a<<1)%mod;
		b>>=1;
	}
	return ans;
}
inline ll pown(ll a,ll b,ll mod){
	ll ans=1;
	while(b){
		if(b&1) ans=powm(ans,a,mod);
		a=powm(a,a,mod);
		b>>=1;
	}
	return ans;
}
inline bool miller_rabin(ll n){
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
inline ll pollard_rho(ll n,ll c){
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
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=998244353;
ll pown(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll pre[10000007];
unordered_map<ll,int> aa;
int main(){
    pre[0]=1;
    for(int i=1;i<=500000;i++){
        pre[i]=(pre[i-1]*i)%mod;
    }
	ll D=read();
    int q=read();
    while(q--){
        ll U=read(),V=read();
        ll g=gcd(U,V);
		aa.clear();fac.clear();if(U/g>1) find(U/g);
        int sum=fac.size();
        for(int k=0;k<fac.size();k++) aa[fac[k]]++;
        ll ans=1;
        for(auto i:aa){
            ans=(1LL*ans*pown(pre[i.second],mod-2))%mod;    
        }
        ans=(1LL*ans*pre[sum])%mod;
        aa.clear();fac.clear();if(V/g>1) find(V/g);
        sum=fac.size();
        for(int k=0;k<fac.size();k++) aa[fac[k]]++;
        for(auto i:aa){
            ans=(1LL*ans*pown(pre[i.second],mod-2))%mod;    
        }
        ans=(1LL*ans*pre[sum])%mod;
        printf("%lld\n",ans);
	}
	return 0;
}