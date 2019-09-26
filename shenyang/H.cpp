#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <complex>
using namespace std;
#pragma GCC optimize(3)
typedef long long ll;
const double PI=acos(-1.0);
typedef complex<double> cd;
const int maxn=200007;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int rev[maxn<<1];
inline void fft(cd *a,int n,int dft){
	for(register int i=0;i<n;i++)
	if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(register int i=1;i<n;i<<=1){
		cd wn=exp(cd(0,dft*PI/i));
		for(register int k=0;k<n;k+=i<<1){
			cd wnk(1,0);
			for(register int j=k;j<k+i;j++){
				cd x=a[j],y=wnk*a[j+i];
				a[j]=x+y;a[j+i]=x-y;wnk*=wn;
			}
		}
	}
	if(dft==-1){
		for(int i=0;i<n;i++) a[i]/=n;
	}
}
cd A[maxn<<1],B[maxn<<1],C[maxn<<1],D[maxn<<1],E[maxn<<1],F[maxn<<1];
inline void fttmul(cd *a,cd *b,cd *c,int len){
	int bit=1;
	while((1<<bit)<=len) bit++;
	for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	for(int i=len/2+1;i<=(1<<bit);i++) a[i]=b[i]=c[i]=0;
	fft(a,1<<bit,1);fft(b,1<<bit,1);fft(c,1<<bit,1);
	for(int i=0;i<(1<<bit);i++) D[i]=(a[i]*b[i]),E[i]=(b[i]*c[i]),F[i]=a[i]*c[i];
	fft(D,1<<bit,-1);fft(E,1<<bit,-1);fft(F,1<<bit,-1);
}
int you[maxn];
ll cntA[maxn<<1],cntB[maxn<<1],cntC[maxn<<1];
ll ans=0;
int main(){
    int t=read(),cnt=0;
    while(t--){
        ++cnt;
        int n=read();
        int mx=0;
        for(int i=1;i<=n;i++){
            int x=read();cntA[x]++;
            mx=max(mx,x);
        }
        for(int i=1;i<=n;i++){
            int x=read();cntB[x]++;
            mx=max(mx,x);
        }
        for(int i=1;i<=n;i++){
            int x=read();cntC[x]++;
            mx=max(mx,x);
        }
        A[0]=B[0]=C[0]=0;
        for(int i=1;i<=mx;i++){
            A[i]=cntA[i];
            B[i]=cntB[i];
            C[i]=cntC[i];
        }
        fttmul(A,B,C,2*mx);
        for(int i=mx;i>=1;i--) cntA[i]+=cntA[i+1];
        for(int i=mx;i>=1;i--) cntB[i]+=cntB[i+1];
        for(int i=mx;i>=1;i--) cntC[i]+=cntC[i+1];
        ans=0;
        for(int i=1;i<=mx;i++){
            ans+=(ll)(D[i].real()+0.5)*cntC[i+1];
        }
        for(int i=1;i<=mx;i++){
            ans+=(ll)(E[i].real()+0.5)*cntA[i+1];
        }
        for(int i=1;i<=mx;i++){
            ans+=(ll)(F[i].real()+0.5)*cntB[i+1];
        }
        for(int i=0;i<=mx;i++) cntA[i]=0,cntB[i]=0,cntC[i]=0;
        printf("Case #%d: %lld\n",cnt,(ll)n*n*n-ans);
    }
	return 0;
}
