#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=300007;
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
void ntt(vector<ll> &a,int n,int dft){
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
struct poly{
    int len;vector<ll> a;
    poly(vector<ll> a):a(a){
        len=a.size()-1;
    }
    poly(){
        len=0;
    }
    void change(){
        while(len&&a[len]==0) len--,a.pop_back();
    }
    poly operator * (poly x){
        poly nex;nex.len=len+x.len;
        int bit=1;
        while((1<<bit)<=nex.len) bit++;
        for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
        vector<ll> A,B;
        for(int i=0;i<=len;i++) A.push_back(a[i]);
        for(int i=0;i<=x.len;i++) B.push_back(x.a[i]);
        for(int i=len+1;i<(1<<bit);i++) A.push_back(0);
        for(int i=x.len+1;i<(1<<bit);i++) B.push_back(0);
        ntt(A,1<<bit,1);ntt(B,1<<bit,1);
        for(int i=0;i<(1<<bit);i++) A[i]=(A[i]*B[i])%mod;
        ntt(A,1<<bit,-1);
        for(int i=0;i<=nex.len;i++) nex.a.push_back(A[i]);
        return nex;
    }
    poly operator + (poly x){
        poly nex;nex.len=max(len,x.len);
        for(int i=0;i<=nex.len;i++){
            nex.a.push_back(i<=len&&i<=x.len?(a[i]+x.a[i])%mod:i<=len?a[i]:x.a[i]);
        }
        return nex;
    }
    poly operator - (poly x){
        poly nex;nex.len=len;
        for(int i=0;i<=x.len;i++){
            nex.a.push_back((a[i]-x.a[i]+mod)%mod);
        }
        for(int i=x.len+1;i<=len;i++) nex.a.push_back(a[i]);
        nex.change();
        return nex;
    }
    void print(){
        for(int i=0;i<=len;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
};
int main(){
    vector<ll> a{1,2,3};
    vector<ll> b{1,2,3};
    poly A(a),B(b);
    A.print();
    B.print();
    (A*B).print();
    return 0;
}
