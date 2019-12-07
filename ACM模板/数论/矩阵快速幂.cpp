#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
struct matrix{
	int n,m;ll a[107][107];
	matrix(){
		memset(a,0,sizeof(a));
	}
	matrix operator * (matrix x){
		matrix New;New.n=n;New.m=x.m;
		for(int i=1;i<=n;i++)
		for(int k=1;k<=x.m;k++)
		for(int z=1;z<=m;z++)
		New.a[i][k]+=a[i][z]*x.a[z][k],New.a[i][k]%=mod;
		return New;
	}
	matrix operator + (matrix x){
		matrix New;New.n=n;New.m=m;
		for(int i=1;i<=n;i++)
		for(int k=1;k<=m;k++){
			New.a[i][k]=(a[i][k]+x.a[i][k])%mod;
		}
		return New;
	}
	void print(){
		for(int i=1;i<=n;i++){
			for(int k=1;k<=m;k++){
				printf("%lld ",a[i][k]);
			}
			printf("\n");
		}
	}
	void eye(){
		for(int i=1;i<=n;i++) a[i][i]=1;
	}
};
matrix powmat(matrix a,int b){
	matrix ans;ans.n=ans.m=a.n;ans.eye();
	while(b){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}