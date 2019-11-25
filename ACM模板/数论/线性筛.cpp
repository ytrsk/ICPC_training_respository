#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=10000007;
const int mod=998244353;
int mu[maxn],phi[maxn],sum[maxn];
int len,p[2000007];
int main(){
	int n;cin>>n;mu[1]=1;phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!phi[i]) p[++len]=i,mu[i]=-1,phi[i]=i-1;
		for(int k=1;k<=len&&i*p[k]<=n;k++){
			if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=mu[i]*mu[p[k]];
			else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=0;break;}
		}
	}
	for(int i=1;i<=n;i++){
		if(mu[i]) for(int k=2*i;k<=n;k+=i) sum[k]=(sum[k]+1LL*phi[k/i]*mu[i])%mod; 
	}
	int ans=0;
	for(int i=2;i<=n;i++) sum[i]=(sum[i]+sum[i-1])%mod;
	for(int i=1;i<=n;i++) ans=(ans+mod+mu[i])%mod;
	printf("%d",((sum[n]<<1)%mod+ans)%mod);
	return 0;
}
