#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const double eps=1e-6;
int len,num[107],mlen;
long long dp[107][10][2][2];
long long dfs(int pos,int pre,int you1,int you2,int limit){
	if(pos==0){
		if(you2) return 1;else return 0;
	}
	if(pos!=mlen&&!limit) if(dp[pos][pre][you1][you2]!=-1) {return dp[pos][pre][you1][you2];}
	else dp[pos][pre][you1][you2]=0;
	int start=(pos==mlen)?1:0,end=limit?num[pos]:9;
	long long ans=0;
	for(int i=start;i<=end;i++){
		ans+=dfs(pos-1,i,pos==mlen?0:(i>pre),you2|(you1&(i>pre)),limit&(i==end));
	}
	if(pos!=mlen&&!limit) dp[pos][pre][you1][you2]=ans;
	return ans;
}
long long check(long long x){
	len=0;
	while(x){
		num[++len]=x%10;
		x/=10;
	}
	long long ans=0;
	for(int i=1;i<len;i++){
		mlen=i;ans+=dfs(i,0,0,0,0);
	}
	mlen=len;ans+=dfs(mlen,0,0,0,1);
	return ans;
}
bool equal(double x,double y){
	return fabs(x-y)<eps;
}
int main(){
	memset(dp,-1,sizeof(dp));
	long long l=1,r=1;
	double u;scanf("%lf",&u);
	for(int i=0;i<=18;i++){
		long long ans=-1;
		while(l<r){
			long long mid=(l+r)>>1;
			long long x=check(mid);
			double u1=1.0*x/mid;
			if(u1>u||equal(u1,u)){
				ans=mid;r=mid-1;
			}
			else l=mid+1;
		}
		if(ans!=-1){
			printf("%lld",ans);return 0;
		}
		if(i<18) r*=10;
	}
	printf("%lf",0);
	return 0;
}