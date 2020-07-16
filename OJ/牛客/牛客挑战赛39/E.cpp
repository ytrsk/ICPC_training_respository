#include <bits/stdc++.h>
#define make_pair mp
#define pii pair<int,int>
using namespace std;
typedef long long ll;
int inv2;
const int maxn=1<<17;
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
void ntt(int *a,int n,int dft){
	for(int i=0;i<n;i++)
	if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1){
		ll wn=pown(G,dft*(mod-1)/(i*2));
		for(int k=0;k<n;k+=i<<1){
			ll wnk=1;
			for(int j=k;j<k+i;j++){
				int x=a[j],y=(1LL*wnk*a[j+i])%mod;
				a[j]=(x+y)%mod;a[j+i]=(x-y+mod)%mod;
				wnk=(1LL*wnk*wn)%mod;
			}
		}
	}
	if(dft==-1){
		int inv1=pown(n,mod-2);
		for(int i=0;i<n;i++) a[i]=(1LL*a[i]*inv1)%mod;
	}
}
void nttmul(int *a,int *b,int l1,int l2){
	int bit=1;
	while((1<<bit)<=l1+l2) bit++;
	for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	for(int i=l1+1;i<(1<<bit);i++) a[i]=0;
	for(int i=l2+1;i<(1<<bit);i++) b[i]=0;
	ntt(a,1<<bit,1);ntt(b,1<<bit,1);
	for(int i=0;i<(1<<bit);i++) a[i]=(1LL*a[i]*b[i])%mod;
	ntt(a,1<<bit,-1);
}
int powm(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
void fwt_or(int *a,int n,int opt)
{
    for(int i=1;i<n;i<<=1)
    for(int k=0;k<n;k+=i<<1)
    for(int j=k;j<k+i;++j)
    if(opt==1)a[j+i]=(a[j]+a[j+i])%mod;
    else a[j+i]=(a[j+i]-a[j]+mod)%mod;
}
void fwt_and(int *a,int n,int opt)
{
    for(int i=1;i<n;i<<=1)
    for(int k=0;k<n;k+=i<<1)
    for(int j=k;j<i+k;++j)
    if(opt==1)a[j]=(a[j]+a[j+i])%mod;
    else a[j]=(a[j]-a[j+i]+mod)%mod;
}
void fwt_xor(int *a,int n,int opt)
{
    for(int i=1;i<n;i<<=1)
    for(int k=0;k<n;k+=i<<1)
    for(int j=k;j<i+k;++j)
    {
        int x=a[j],y=a[j+i];
        a[j]=(x+y)%mod;a[j+i]=(x-y+mod)%mod;
        if(opt==-1) a[j]=1LL*a[j]*inv2%mod,a[j+i]=1LL*a[j+i]*inv2%mod;
    }
}
int A[18][maxn],B[18][maxn],AA[18][maxn],ans[1<<20];
int aa[maxn],bb[maxn],cc[maxn<<2],dd[maxn<<1];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    inv2=powm(2,mod-2); 
    int n=read();
    for(int i=0;i<=n;i++) aa[i]=read();
    for(int k=0;k<=n;k++) bb[k]=read();
    for(int i=0;i<=n;i++) cc[i]=read();
    for(int i=0;i<=n;i++) dd[i]=read();
    for(int i=0;i<=n;i++){
        A[__builtin_popcount(i)][i]=aa[i];
        B[__builtin_popcount(i)][i]=bb[i];
    }
    for(int i=0;i<=17;i++) fwt_or(A[i],1<<17,1),fwt_or(B[i],1<<17,1);
    for(int i=0;i<=17;i++){
        for(int k=0;k<=i;k++) for(int z=0;z<(1<<17);z++) AA[i][z]=(AA[i][z]+1LL*A[k][z]*B[i-k][z])%mod;
        fwt_or(AA[i],1<<17,-1);
        for(int k=0;k<(1<<17);k++) if(__builtin_popcount(k)==i)(ans[k]+=AA[i][k])%=mod;
    }
    nttmul(ans,cc,(1<<17)-1,(1<<17)-1);
    fwt_xor(ans,1<<18,1);
    fwt_xor(dd,1<<18,1);
    for(int i=0;i<(1<<18);i++) ans[i]=(1LL*ans[i]*dd[i])%mod;
    fwt_xor(ans,1<<18,-1);
    int t=read();
    while(t--){
        int x=read();
        printf("%d\n",ans[x]);
    }
    return 0;
}
