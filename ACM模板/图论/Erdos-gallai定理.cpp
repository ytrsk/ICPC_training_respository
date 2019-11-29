#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=500007;
int a[maxn],n;
bool cmp(int a,int b){
	return a>b;
}
int eg(int x){
	int z[maxn];for(int i=0;i<=n;i++) z[i]=0;
	z[x]++;for(int i=1;i<=n;i++) z[a[i]]++;
	long long sum1=0,sum2=0,sum3=0;
	int ok=0;
	for(int i=1;i<=n;i++){
		int val=0,pos;
		if(ok){
			val=a[i-1];
		}
		else{
			if(x>a[i]) val=x,ok=1;
			else val=a[i];
		}
		sum1+=val;sum3+=z[i-1];
		sum2-=min(i-1,val);
		sum2+=max(0LL,n+1-i-sum3);
		if(sum1>sum2+1LL*i*(i-1)){
			if(ok) return 1;
			else return -1;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);sum+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	int p=sum%2;
	int l=0,r=(n-p)/2,ans1=-1;
	while(l<=r){
		int m=(l+r)>>1;
		int x=eg(m*2+p);
		if(x==-1) l=m+1;
		else{
			r=m-1;
			if(x==0) ans1=m;
		}
	}
	l=0,r=(n-p)/2;int ans2=-1;
	while(l<=r){
		int m=(l+r)>>1;
		int x=eg(m*2+p);
		if(x==1) r=m-1;
		else{
			l=m+1;
			if(x==0) ans2=m;
		}
	}
	if(ans1==-1||ans2==-1) printf("-1");
	else{
		for(int i=ans1;i<=ans2;i++) printf("%d ",i*2+p);
	}
	return 0;
}
