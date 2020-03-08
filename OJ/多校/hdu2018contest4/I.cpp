#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef long long LL;
typedef long double db;
const int mod=1000000007,N=131080,M=32767;
const db pi=acos(-1);
int K,T;LL n;
int fac[N],inv[N],ifac[N],rev[N],len[N];
int aa[N],bb[N],k1[N],k2[N];
struct com{db r,i;}a[N],b[N],Aa[N],Ab[N],Ba[N],Bb[N];
com operator + (com A,com B) {return (com){A.r+B.r,A.i+B.i};}
com operator - (com A,com B) {return (com){A.r-B.r,A.i-B.i};}
com operator * (com A,com B) {return (com){A.r*B.r-A.i*B.i,A.r*B.i+A.i*B.r};}
com conj(com A) {return (com){A.r,-A.i};}

int qm(int x) {return x>=mod?x-mod:x;}
int ksm(int x,int y) {
	int re=1;
	for(;y;y>>=1,x=1LL*x*x%mod) if(y&1) re=1LL*re*x%mod;
	return re;
}
void FFT(com *a,int n) {
	for(RI i=0;i<n;++i) if(rev[i]>i) swap(a[i],a[rev[i]]);
	for(RI i=1;i<n;i<<=1) {
		com wn=(com){cos(pi/i),sin(pi/i)};
		for(RI j=0;j<n;j+=(i<<1)) {
			com t1,t2,w=(com){1,0};
			for(RI k=0;k<i;++k,w=w*wn)
				t1=a[j+k],t2=a[j+i+k]*w,a[j+k]=t1+t2,a[j+i+k]=t1-t2;
		}
	}
}
void mul(int *ka,int *kb,int *kc,int n) {
	for(RI i=0;i<n;++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(len[n]-1));
	for(RI i=0;i<(n>>1);++i) {
		a[i]=(com){(db)(ka[i]&M),(db)(ka[i]>>15)};
		b[i]=(com){(db)(kb[i]&M),(db)(kb[i]>>15)};
		a[i+(n>>1)]=b[i+(n>>1)]=(com){0,0};
	}
	FFT(a,n),FFT(b,n);
	for(RI i=0;i<n;++i) {
		int j=(n-i)&(n-1);
		com kAa=(a[i]+conj(a[j]))*(com){0.5,0};
		com kAb=(a[i]-conj(a[j]))*(com){0,-0.5};
		com kBa=(b[i]+conj(b[j]))*(com){0.5,0};
		com kBb=(b[i]-conj(b[j]))*(com){0,-0.5};
		Aa[j]=kAa*kBa,Ab[j]=kAa*kBb,Ba[j]=kAb*kBa,Bb[j]=kAb*kBb;
	}
	for(RI i=0;i<n;++i)
		a[i]=Aa[i]+Ab[i]*(com){0,1},b[i]=Ba[i]+Bb[i]*(com){0,1};
	FFT(a,n),FFT(b,n);
	for(RI i=0;i<n;++i) {
		int kAa=(LL)(a[i].r/n+0.5)%mod;
		int kAb=(LL)(a[i].i/n+0.5)%mod;
		int kBa=(LL)(b[i].r/n+0.5)%mod;
		int kBb=(LL)(b[i].i/n+0.5)%mod;
		kc[i]=qm(((LL)kAa+((LL)(kAb+kBa)<<15)+((LL)kBb<<30))%mod+mod);
	}
}
void getinv(int *a,int *b,int n) {
	if(n==1) {b[0]=ksm(a[0],mod-2),b[1]=0;return;}
	getinv(a,b,n>>1),mul(a,b,k1,n<<1),mul(k1,b,k2,n<<1);
	for(RI i=0;i<n;++i) b[i]=qm(qm(b[i]+b[i])-k2[i]+mod),b[i+n]=0;
}
const int maxn=100007;
int C(int d,int u) {return 1LL*fac[d]*ifac[u]%mod*ifac[d-u]%mod;}
void prework() {
	inv[0]=inv[1]=1,ifac[0]=1,fac[0]=1;
	for(RI i=1;i<N;++i) fac[i]=1LL*fac[i-1]*i%mod;
	for(RI i=2;i<N;++i) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(RI i=1;i<N;++i) ifac[i]=1LL*ifac[i-1]*inv[i]%mod;
	int kn=1;while(kn<=50000) kn<<=1,len[kn]=len[kn>>1]+1;
	len[kn<<1]=len[kn]+1;
	for(RI i=0;i<kn;++i) aa[i]=ifac[i+1];
	getinv(aa,bb,kn);
	for(RI i=0;i<=50000;++i) bb[i]=1LL*bb[i]*fac[i]%mod;
}
int coe[maxn];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int pown(int a,int b){
    if(b<0) return pown(pown(a,-b),mod-2);
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int A[maxn],B[maxn];
int mul(int a,int b){
    return 1LL*a*b%mod;
}
void add(int &a,int b){
    a+=b;if(a>=mod) a-=mod;
}
typedef long long ll;
struct FfT{
    const int mod=479*(1<<21)+1,G=3;
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
        for(int i=l1+1;i<(1<<bit);i++) a[i]=0;
        for(int i=l2+1;i<(1<<bit);i++) b[i]=0;
        for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
        ntt(a,1<<bit,1);ntt(b,1<<bit,1);
        for(int i=0;i<(1<<bit);i++) a[i]=(a[i]*b[i])%mod;
        ntt(a,1<<bit,-1);
    }
    ll a[maxn<<2],b[maxn<<2];
}FFt;
int Pre[maxn];
int main(){
	prework();Pre[0]=1;
    for(int i=1;i<=100000;i++) Pre[i]=1LL*Pre[i-1]*i%mod;
    int T=read();
    while(T--){
        int nn,N=1;
        scanf("%lld%d",&K,&nn);
        for(int i=1;i<=nn;i++) A[i]=read(),B[i]=read(),N=1LL*N*ksm(A[i],B[i])%mod;
        int ans=0;
        FFt.a[0]=0;
        for(RI i=1;i<=K+1;++i)
            coe[i]=1LL*qm(1LL*C(K+1,K+1-i)*bb[K+1-i]%mod)*inv[K+1]%mod,FFt.a[K+1-i]=mul(Pre[i],coe[i]);
        for(int i=1;i<=K+1;i++) FFt.b[i]=Pre[i];
        FFt.b[0]=1;
        int l1=K+1,l2=K+1;
        FFt.nttmul(FFt.a,FFt.b,l1,l2);
        FFt.a[K+1]=0;
        for(int i=0;i<=K+1;i++){
            int tmp=mul(ksm(N,i),mul(FFt.a[K+1-i],pown(Pre[i],mod-2)));
            for(int k=1;k<=nn;k++){
                tmp=mul(tmp,1+mod-pown(A[k],K-i));
            }
            add(ans,tmp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}