#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=200007;
int a[maxn];
int main(){
	int n;
	while(cin>>n){
		if(!n) return 0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int sum=0;
		for(int i=1;i<=n;i++) sum^=a[i];
		if(sum==0){
			printf("No\n");
		}
		else{
			printf("Yes\n");
			int cnt=0;
			for(int i=1;i<=n;i++) if((a[i]^sum)<a[i]){
				printf("%d %d\n",a[i],a[i]^sum);
			}
		}
	}
	return 0;
}

