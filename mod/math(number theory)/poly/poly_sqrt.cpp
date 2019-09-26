#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=300007;
const int mod=998244353,G=3;
int rev[maxn<<2];ll tmp[maxn<<2],invb[maxn<<2];
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
struct cn{
    int x,y,w;
    cn operator * (cn a){
        cn ans;
        ans.x=(1LL*x*a.x%mod+1LL*y*a.y%mod*w%mod)%mod;
        ans.y=(1LL*x*a.y%mod+1LL*y*a.x%mod)%mod;
        ans.w=w;
        return ans;
    }
    int operator ^ (int b){
        cn ans,x=*this;ans.x=1;ans.y=0;ans.w=w;
        while(b){
            if(b&1) ans=ans*x;
            x=x*x;
            b>>=1;
        }
        return ans.x;
    }
};
int sqrt_mod(int n){
    if(n==0) return 0;
    if(pown(n,(mod-1)/2)==mod-1) return -1;
    int a,w;
    while(1){
        a=rand()%mod;
        w=(1LL*a*a-n+mod)%mod;
        if(pown(w,(mod-1)/2)==mod-1) break;
    }
    cn x;x.x=a;x.y=1;x.w=w;
    return x^((mod+1)/2);
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
void poly_inv(ll *a,ll *b,int len){
    if(!len){
        b[0]=pown(a[0],mod-2);
        return;
    }
    poly_inv(a,b,len/2);
    int bit=1;
    while((1<<bit)<=(len<<1)) bit++;
    for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
    for(int i=len/2+1;i<(1<<bit);i++) b[i]=0;
    for(int i=0;i<=len;i++) tmp[i]=a[i];
    for(int i=len+1;i<(1<<bit);i++) tmp[i]=0;
    ntt(tmp,(1<<bit),1),ntt(b,(1<<bit),1);
    for(int i=0;i<(1<<bit);i++) (b[i]*=(2-tmp[i]*b[i]%mod+mod)%mod)%=mod;
    ntt(b,(1<<bit),-1);for(int i=len+1;i<(1<<bit);i++) b[i]=0;
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
int inv2=pown(2,mod-2);
void poly_sqrt(ll *a,ll *b,int len){
    if(!len){
        b[0]=sqrt_mod(a[0]);
        b[0]=min(b[0],mod-b[0]);
        return;
    }
    poly_sqrt(a,b,len/2);poly_inv(b,invb,len);
    int bit=1;
	while((1<<bit)<=(len<<1)) bit++;
	for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	for(int i=len/2+1;i<(1<<bit);i++) b[i]=0;
	for(int i=0;i<=len;i++) tmp[i]=a[i];
	for(int i=len+1;i<(1<<bit);i++) tmp[i]=0;
    ntt(b,(1<<bit),1);ntt(invb,(1<<bit),1);ntt(tmp,(1<<bit),1);
    for(int i=0;i<(1<<bit);i++){
        b[i]=(b[i]+tmp[i]*invb[i])%mod*inv2%mod;
    }
    ntt(b,(1<<bit),-1);for(int i=len+1;i<(1<<bit);i++) b[i]=0;
}
ll a[maxn],b[maxn],c[maxn],z[maxn];
int main(){
    int n;cin>>n;n--;
    for(int i=0;i<=n;i++) cin>>a[i];
    poly_sqrt(a,b,n);
    for(int i=0;i<=n;i++) cout<<b[i]<<' ';
    return 0;
}
