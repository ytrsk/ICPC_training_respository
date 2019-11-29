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
const double eps=1e-13;
const int maxn=56;
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
	for(int i=0;i<=n;i++){
		int t=i;
		for(int k=i+1;k<=n;k++){
			if(fabs(a[k][i])>fabs(a[t][i])) t=k;
		}
		if(t!=i) swap(a[t],a[i]);
		//if(fabs(a[i][i])<1e) continue;
		for(int k=0;k<=n;k++){
            if(k==i) continue;
			double t=a[k][i]/a[i][i];
			for(int z=i;z<=n+1;z++){
				a[k][z]-=t*a[i][z];
			}
		}
	}
	for(int i=0;i<=n;i++){
        ans[i]=a[i][n+1]/a[i][i];
	}
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
double ans[57];
int main(){
    int t=read(),cnt=0;
    while(t--){
        double p;scanf("%lf",&p);p=1-p;
        int n=read(),m=read();
        memset(a,0,sizeof(a));
        if(n==0||m==0){
            printf("Case %d: 0.0000000\n",++cnt);continue;
        }
        for(int i=0;i<=n+m;i++) a[i][i]=1;
        for(int i=0;i<=n-1;i++){
            a[i][i+1]=-p;
            a[i][n+1]=p-1;
            a[i][n+m+1]=1;
        }
        for(int i=n+1;i<n+m;i++){
            a[i][i+1]=p-1;
            a[i][1]=-p;
            a[i][n+m+1]=1;
        }
        gauss_double(n+m,ans);
        printf("Case %d: %.8f\n",++cnt,ans[0]);
    }
	return 0;
}
