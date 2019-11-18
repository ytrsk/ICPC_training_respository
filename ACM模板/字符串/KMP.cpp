#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=100007;
int fail[maxn];
char s1[maxn],s2[maxn];
int main(){
	scanf("%s%s",s1+1,s2+1);
	int last=0,l1=strlen(s1+1),l2=strlen(s2+1);
	for(int i=2;i<=l1;i++){
		while(last&&s1[last+1]!=s1[i]) last=fail[last];
		if(s1[last+1]==s1[i]) last++;
		fail[i]=last;
	}
	last=0;int ans=0;
	for(int i=1;i<=l2;i++){
		while(last&&s1[last+1]!=s2[i]) last=fail[last];
		if(s1[last+1]==s2[i]) last++;
		if(last==l1){
			last=fail[last];ans++;
		}
	}
	printf("%d",ans?ans:-1);
	return 0;
}
