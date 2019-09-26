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
struct cd{
    double real,unreal;
    cd(double real=0.0,double unreal=0.0):real(real),unreal(unreal){
    }
    cd operator + (cd a){
        return cd(real+a.real,unreal+a.unreal);
    }
    cd operator - (cd a){
        return cd(real-a.real,unreal-a.unreal);
    }
    cd operator * (cd a){
        return cd(real*a.real-unreal*a.unreal,real*a.unreal+unreal*a.real);
    }
    cd operator = (ll a){
        return *this=cd(a,0);
    }
    cd operator = (complex<double> a){
        return *this=cd(a.real(),a.imag());
    }
    cd operator / (ll a){
        return cd(real/a,unreal/a);
    }
};
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
void fft(cd *a,int n,int dft){
	for(int i=0;i<n;i++)
	if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(register int i=1;i<n;i<<=1){
		cd wn;wn=exp(complex<double>(0,dft*PI/i));
		for(register int k=0;k<n;k+=i<<1){
			cd wnk(1,0);
			for(register int j=k;j<k+i;++j){
				cd x=a[j],y=wnk*a[j+i];
				a[j]=x+y;a[j+i]=x-y;wnk=wnk*wn;
			}
		}
	}
	if(dft==-1){
		for(int i=0;i<n;i++) a[i]=a[i]/n;
	}
}
cd A[maxn<<1],B[maxn<<1],C[maxn<<1],D[maxn<<1],E[maxn<<1],F[maxn<<1];
void fttmul(cd *a,cd *b,cd *c,int len){
	int bit=1;
	while((1<<bit)<=len) bit++;
	for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	for(int i=len/2+1;i<=(1<<bit);i++) a[i]=b[i]=c[i]=0;
	fft(a,1<<bit,1);fft(b,1<<bit,1);fft(c,1<<bit,1);
	for(int i=0;i<(1<<bit);i++) D[i]=a[i]*b[i],E[i]=b[i]*c[i],F[i]=a[i]*c[i];
	fft(D,1<<bit,-1);fft(E,1<<bit,-1);fft(F,1<<bit,-1);
}
int you[maxn];
ll cntA[maxn<<1],cntB[maxn<<1],cntC[maxn<<1];
ll ans=0;
int aa[maxn],bb[maxn],cc[maxn];
ll solve(int *aa,int *bb,int *cc,int n){
    ll ans=0;
    for(int i=1;i<=n;i++){
        int now=0;
        for(int k=1;k<=n;k++){
            while(now<n&&aa[i]+bb[k]>=cc[now+1]) ++now;
            ans+=n-now;
            //cout<<i<<" "<<k<<" "<<now<<endl;
        }
    }
    return ans;
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        ++cnt;
        int n=read();
        if(1){
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
                ans+=(ll)(D[i].real+0.5)*cntC[i+1];
            }
            for(int i=1;i<=mx;i++){
                ans+=(ll)(E[i].real+0.5)*cntA[i+1];
            }
            for(int i=1;i<=mx;i++){
                ans+=(ll)(F[i].real+0.5)*cntB[i+1];
            }
            for(int i=0;i<=mx;i++) cntA[i]=0,cntB[i]=0,cntC[i]=0;
            printf("Case #%d: %lld\n",cnt,(ll)n*n*n-ans);
        }
        else{
            for(int i=1;i<=n;i++) aa[i]=read();
            for(int i=1;i<=n;i++) bb[i]=read();
            for(int i=1;i<=n;i++) cc[i]=read();
            sort(aa+1,aa+n+1);sort(bb+1,bb+n+1);sort(cc+1,cc+n+1);
            ans=1LL*n*n*n;;
            ans-=solve(aa,bb,cc,n);ans-=solve(aa,cc,bb,n);
            ans-=solve(bb,cc,aa,n);
            printf("Case #%d: %lld\n",cnt,ans);
        }
    }
	return 0;
}
