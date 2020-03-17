#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define cs const
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const ll mod=31525197391593473,inv2=mod+1>>1;
const ll maxn=1000007;
inline ll add(ll a,ll b){return a+b>=mod?a+b-mod:a+b;}
inline ll dec(ll a,ll b){return a<b?a-b+mod:a-b;}
inline ll mul(ll a,ll b){return (__int128)a*b%mod;}
inline ll pown(ll a,ll b){
    ll res=1;
	while(b){
		if(b&1)res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
struct cn{
    ll x,y,w;
    cn operator * (cn a){
        cn ans;
        ans.x=(1LL*x*a.x%mod+1LL*y*a.y%mod*w%mod)%mod;
        ans.y=(1LL*x*a.y%mod+1LL*y*a.x%mod)%mod;
        ans.w=w;
        return ans;
    }
    ll operator ^ (ll b){
        cn ans,x=*this;ans.x=1;ans.y=0;ans.w=w;
        while(b){
            if(b&1) ans=ans*x;
            x=x*x;
            b>>=1;
        }
        return ans.x;
    }
};
ll sqrt_mod(ll n){
    if(n==0) return 0;
    if(pown(n,(mod-1)/2)==mod-1) return -1;
    ll a,w;
    while(1){
        a=rand()%mod;
        w=(1LL*a*a-n+mod)%mod;
        if(pown(w,(mod-1)/2)==mod-1) break;
    }
    cn x;x.x=a;x.y=1;x.w=w;
    return x^((mod+1)/2);
}
typedef vector<ll> Poly;
inline void prll(cs Poly &a,char c=' '){
	for(re ll i=0;i<a.size();++i) cout<<a[i]<<c;
}
ll rev[maxn],inv[maxn];
inline void ntt(Poly &a,ll n,ll dft){
	for(re ll i=0;i<n;++i)
    if(i<rev[i])swap(a[i],a[rev[i]]);
	for(re ll i=1;i<n;i<<=1){
		ll wn=pown(dft==-1?(mod+1)/3:3,(mod-1)/i/2);
		for(re ll j=0;j<n;j+=i<<1)
		for(re ll k=0,x,y,w=1;k<i;++k,w=mul(w,wn)){
			x=a[j+k],y=mul(w,a[j+k+i]);
			a[j+k]=add(x,y);
			a[j+k+i]=dec(x,y);
		}
	}
	if(dft==-1)for(re ll i=0;i<n;++i) a[i]=mul(a[i],inv[n]);
}
inline void init_rev(ll len){
	for(re ll i=0;i<len;++i) rev[i]=rev[i>>1]>>1|((i&1)*(len>>1));
}
inline Poly operator + (cs Poly &a,cs Poly &b){
	Poly c=a;c.resize(max(a.size(),b.size()));
	for(ll re i=0;i<b.size();++i)c[i]=(c[i]+b[i])%313;
	return c;
}
inline Poly operator - (cs Poly &a,cs Poly &b){
	Poly c=a;c.resize(max(a.size(),b.size()));
	for(ll re i=0;i<b.size();++i)c[i]=(c[i]-b[i]+313)%313;
	return c;
}
void Re(Poly &A){
    for(ll i=0;i<A.size();i++) A[i]%=313;
}
inline Poly operator * (Poly a,Poly b){
	ll n=a.size(),m=b.size(),l=1;
	while(l<n+m-1) l<<=1;
	init_rev(l);
	a.resize(l),ntt(a,l,1);
	b.resize(l),ntt(b,l,1);
	for(ll re i=0;i<l;++i)a[i]=mul(a[i],b[i]);
	ntt(a,l,-1);
    Re(a);
	a.resize(n+m-1);
	return a;
}

inline Poly operator * (Poly a,ll b){
	for(re ll i=0;i<a.size();++i) a[i]=(1LL*a[i]*b)%313;
	return a;
}
inline Poly Deriv(Poly a){
	for(re ll i=0;i+1<a.size();++i) a[i]=mul(a[i+1],i+1);
	a.pop_back();
	return a;
}
inline Poly lleg(Poly a){
	a.push_back(0);
	for(re ll i=a.size()-1;i;--i) a[i]=mul(a[i-1],inv[i]);
	a[0]=0;
	return a;
}
inline Poly Inv(cs Poly &a,ll lim){
	Poly c,b(1,pown(a[0],313-2));Re(b);
	for(ll re l=4;(l>>2)<lim;l<<=1){
		init_rev(l);
		c=a,c.resize(l>>1);
        Poly now=c*b;
        for(re ll i=0;i<now.size();i++) now[i]=(now[i]*(313-1))%313;
        now[0]=(now[0]+2)%313;
        now.resize(l>>1);
        b=b*now;
		b.resize(l>>1);
	}
	b.resize(lim);
	return b;
}
inline Poly Inv(cs Poly &a){return Inv(a,a.size());}
inline Poly Ln(Poly a,ll lim){
	a=lleg(Deriv(a)*Inv(a,lim));
	a.resize(lim);
	return a;
}
inline Poly Ln(cs Poly &a){return Ln(a,a.size());}
inline Poly Exp(cs Poly &a,ll lim){
	Poly c,b(1,1);ll n=a.size();
	for(ll re i=2;(i>>1)<lim;i<<=1){
		c=Ln(b,i);
		for(ll re j=0;j<i;++j)c[j]=dec(j<n?a[j]:0,c[j]);
		c[0]=add(c[0],1);
		b=b*c;
		b.resize(i);
	}
	b.resize(lim);
	return b;
}
inline Poly Exp(cs Poly &a){return Exp(a,a.size());}
cs ll w4=pown(3,(mod-1)/4);
inline Poly Cos(cs Poly &a,ll lim){
	Poly c=a;c.resize(lim);
	c=(Exp(c*w4)+Exp(c*(mod-w4)))*inv2;
	return c;
}
inline Poly Cos(cs Poly &a){return Cos(a,a.size());}

inline Poly Sin(cs Poly &a,ll lim){
	Poly c=a;c.resize(lim);
	c=(Exp(c*w4)-Exp(c*(mod-w4)))*mul(inv2,pown(w4,mod-2));
	return c;
}
inline Poly Sin(cs Poly &a){return Sin(a,a.size());}

inline Poly Sqrt(cs Poly &a,ll lim){
	Poly c,d,b(1,sqrt_mod(a[0]));
	for(ll re l=4;(l>>2)<lim;l<<=1){
		init_rev(l);
		c=a,c.resize(l>>1);
		d=Inv(b,l>>1);
		c.resize(l),ntt(c,l,1);
		d.resize(l),ntt(d,l,1);
		for(ll re j=0;j<l;++j)c[j]=mul(c[j],d[j]);
		ntt(c,l,-1);
		b.resize(l>>1);
		for(ll re j=0;j<(l>>1);++j)b[j]=mul(add(c[j],b[j]),inv2);
	}
	b.resize(lim);
	return b;
}
inline Poly Sqrt(cs Poly &a){return Sqrt(a,a.size());}

inline Poly Ksm(Poly a,ll k,ll lim){
	a=Exp(Ln(a)*k);
	a.resize(lim);
	return a;
}
inline Poly Ksm(cs Poly &a,ll k){return Ksm(a,k,a.size());}
inline Poly operator / (Poly a,Poly b){
	re ll len=1,deg=a.size()-b.size()+1;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	while(len<=deg) len<<=1;
	b=Inv(b,len);b.resize(deg);
	a=a*b;a.resize(deg);
	reverse(a.begin(),a.end());
	return a;
}
inline Poly operator % (const Poly &a,const Poly &b){
	Poly c=a-(a/b)*b;
	c.resize(b.size()-1);
	return c;
}
inline void init_inv(){
	inv[0]=inv[1]=1;
	for(re ll i=2;i<maxn;++i)inv[i]=mul(inv[mod%i],mod-mod/i);
}
int main(){
	init_inv();
    int n;
    while(scanf("%d",&n)==1&&n){
        Poly A(n+1,0);
        for(ll i=1;i<=n;i++){
            ll x=read();A[i]=x%313;
        }
        Poly B(n+1,0);B[0]=1;
        Poly E=Inv(B-A,n+1);
        printf("%d\n",E[n]);
    }
	return 0;
}