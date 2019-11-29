#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const ll mod=1e9;
const double eps=1e-7;
const int maxn=103;
double a[maxn][maxn];
/*ll gauss_ll(int n){
	ll ans=1;
	for(int i=1;i<=n;i++){
		for(int k=i+1;k<=n;k++)
		while(a[k][i]){
			ll t=a[i][i]/a[k][i];
			for(int z=i;z<=n;z++)
			a[i][z]=(a[i][z]-(a[k][z]*t)%mod+mod)%mod;
			swap(a[k],a[i]);
			ans=-ans;
		}
		if(!ans) return 0;
	}
}*/
void gauss_double(int n,double *ans){
	for(int i=1;i<=n;i++){
		int t=i;
		for(int k=i+1;k<=n;k++){
			if(fabs(a[k][i])>fabs(a[t][i])) t=k;
		}
		if(t!=i) swap(a[t],a[i]);
		if(fabs(a[i][i])<eps) continue;
		for(int k=1;k<=n;k++){
            if(k==i) continue;
			double t=a[k][i]/a[i][i];
			for(int z=i;z<=n+1;z++){
				a[k][z]-=t*a[i][z];
			}
		}
	}
	for(int i=1;i<=n;i++){
        ans[i]=a[i][n+1]/a[i][i];
	}
}
int main(){
	return 0;
}
