#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
struct matrix{
	int n,m;ll shu[107][107];
	matrix(){
		memset(shu,0,sizeof(shu));
	}
	matrix operator * (matrix a){
		matrix new1;new1.n=n;new1.m=a.m;
		for(int i=1;i<=n;i++)
		for(int k=1;k<=a.m;k++)
		for(int z=1;z<=m;z++)
		new1.shu[i][k]+=shu[i][z]*a.shu[z][k],new1.shu[i][k]%=mod;
		return new1;
	}
	matrix operator + (matrix a){
		matrix new1;new1.n=n;new1.m=m;
		for(int i=1;i<=n;i++)
		for(int k=1;k<=m;k++){
			new1.shu[i][k]=(shu[i][k]+a.shu[i][k])%mod;
		}
		return new1;
	}
	void print(){
		for(int i=1;i<=n;i++){
			for(int k=1;k<=m;k++){
				printf("%lld ",shu[i][k]);
			}
			printf("\n");
		}
	}
	void eye(){
		for(int i=1;i<=n;i++) shu[i][i]=1;
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