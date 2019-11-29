#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=1000007;
int ql=1,qr=0,q[maxn];
ll sum[maxn],dp[maxn];
ll gety(int x){
	return -dp[x]-sum[x]*sum[x];
}
ll getx(int x){
	return sum[x];
}
bool check_k(int a,int b,int x){
	if(gety(b)-gety(a)>=x*(getx(b)-getx(a))) return true;
	else return false;
}
bool check_poly(int a,int b,int c){
	if((gety(c)-gety(b))*(getx(b)-getx(a))>=(gety(b)-gety(a))*(getx(c)-getx(b))) return true;
	else return false;
}
//dp[i]=dp[k]+(sum[i]-sum[k])^2+m
//y=kx+b --> b=sum[i]^2+m-dp[i] k=-2*sum[i] x=sum[k] y=-dp[k]-sum[k]^2 b --> max 
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		ql=1,qr=0;
		q[++qr]=0;
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);sum[i]=sum[i-1]+x;
			while(ql<qr&&check_k(q[ql],q[ql+1],-2*sum[i])) ql++;
			dp[i]=dp[q[ql]]+(sum[i]-sum[q[ql]])*(sum[i]-sum[q[ql]])+m;
			while(ql<qr&&check_poly(q[qr-1],q[qr],i)) qr--;
			q[++qr]=i;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
