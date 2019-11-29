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
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int id[maxn];
int n;double ans[maxn];
int main(){
    int t=read();int cnt=0;
    while(t--){
        int n=read();
        memset(a,0,sizeof(a));
        for(int i=1;i<=99;i++){
            id[i]=0;
            a[i][i]=-1;
            a[i][101]=-1;
        }
        a[100][100]=1;
        for(int i=1;i<=99;i++){
            if(i+6<=100){
                for(int k=1;k<=6;k++) a[i][i+k]=1.0/6;
            }
            else{
                int x=100-i;
                for(int k=1;k<=x;k++) a[i][i+k]=1.0/6;
                a[i][i]+=1.0*(6-x)/6;
            }
        }
        for(int i=1;i<=n;i++){
            int u=read(),v=read();
            id[u]=v;
        }
        for(int i=1;i<=100;i++){
            if(id[i]){
                for(int k=1;k<=101;k++) a[i][k]=0;
                a[i][i]=1;a[i][id[i]]=-1;
            }
        }
        gauss_double(100,ans);
        printf("Case %d: %.8f\n",++cnt,ans[1]);
    }
	return 0;
}
