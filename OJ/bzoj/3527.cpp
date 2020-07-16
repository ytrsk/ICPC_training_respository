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
    cd operator = (double a){
        return *this=cd(a,0);
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
const int maxn=400007;
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
double q[maxn];
cd A[maxn<<1],B[maxn<<1],C[maxn<<1];
cd Ans1[maxn<<1],Ans2[maxn<<1];
void fttmul(cd *a,cd *b,cd *c,int len){
	int bit=1;
	while((1<<bit)<=len) bit++;
	for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	fft(a,1<<bit,1);fft(b,1<<bit,1);
    for(int i=0;i<(1<<bit);i++) c[i]=a[i]*b[i];
    fft(c,1<<bit,-1);
}
int main(){
    int n=read();
    for(int i=1;i<=n;i++){
        scanf("%lf",&q[i]);
    }
    for(int i=1;i<=n;i++) A[i]=q[i];
    for(int i=1;i<=n;i++){
        B[i]=1/(1.0*i*i);
    }
    fttmul(A,B,Ans1,2*n);
    memset(A,0,sizeof(A));memset(B,0,sizeof(B));
    for(int i=1;i<=n;i++) A[n+1-i]=q[i],B[i]=1/(1.0*i*i);
    fttmul(A,B,Ans2,2*n);
    for(int i=1;i<=n;i++) printf("%.3f\n",(Ans1[i]-Ans2[n+1-i]).real);
    return 0;
}
