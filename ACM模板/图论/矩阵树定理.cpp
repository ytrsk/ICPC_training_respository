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
const int maxn=57;
ll a[maxn][maxn];
ll gauss_ll(){
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
		ans=(ans*a[i][i])%mod;
		if(!ans) return 0;
	}
	return (ans+mod)%mod;
}
double gauss_double(){
	double ans=1.0;
	for(int i=1;i<=n;i++){
		int t=i;
		for(int k=i+1;k<=n;k++){
			if(fabs(a[k][i])>fabs(a[t][i])) t=k;
		}
		if(t!=i) swap(a[t],a[i]),ans=-ans;
		ans*=a[i][i];
		if(fabs(ans)<eps) return 0;
		for(int k=i+1;k<=n;k++){
			double t=a[k][i]/a[i][i];
			for(int z=i;z<=n;z++){
				a[k][z]-=t*a[i][z];
			}
		}
	}
	return ans;
}
void add(int u,int v){
	if(u>v) return;
	a[u][u]++;a[v][v]++;
	a[u][v]--;a[v][u]--;
}
int main(){
	return 0;
}
