#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=110007;
int fail[maxn<<1];
char s[maxn<<1],sf[maxn<<1];
int main(){
	while(scanf("%s",s+1)==1){
		int len=strlen(s+1);
		for(int i=1;i<=len;i++){
			sf[i*2-1]='#';
			sf[i*2]=s[i];
		}
		sf[0]='@';sf[len*2+1]='#';sf[len*2+2]='$';
		int mx=0,ans=0,id=0;
		for(int i=1;i<=2*len+1;i++){
			fail[i]=mx>i?min(mx-i,fail[2*id-i]):1;
			while(sf[i-fail[i]]==sf[i+fail[i]]) fail[i]++;
			if(fail[i]+i>mx) mx=fail[i]+i,id=i;
			ans=max(ans,fail[i]-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
