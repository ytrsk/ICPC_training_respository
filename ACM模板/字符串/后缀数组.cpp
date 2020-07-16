#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=200007;
char s[maxn];
int sa[2][maxn],rk[2][maxn],now,bit,n,a[maxn],h[maxn],v[maxn],l1;
void solve(int sa[],int rk[],int SA[],int RK[]){
	for(int i=1;i<=n;i++) v[rk[sa[i]]]=i;
	for(int i=n;i;i--) if(sa[i]>l1) SA[v[rk[sa[i]-l1]]--]=sa[i]-l1;
	for(int i=n-l1+1;i<=n;i++) SA[v[rk[i]]--]=i;
	for(int i=1;i<=n;i++) RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+l1]!=rk[SA[i-1]+l1]);
}
void getsa(){
	now=0;
	for(int i=1;i<=n;i++) v[a[i]]++;
	for(int i=1;i<=30;i++) v[i]+=v[i-1];
	for(int i=1;i<=n;i++) sa[now][v[a[i]]--]=i;
	for(int i=1;i<=n;i++) rk[now][sa[now][i]]=rk[now][sa[now][i-1]]+(a[sa[now][i]]!=a[sa[now][i-1]]);
    for(l1=1;l1<n;l1<<=1){
		solve(sa[now],rk[now],sa[now^1],rk[now^1]);now^=1;
	}
}
void geth(){
	l1=0;
	for(int i=1;i<=n;i++)
    if(rk[now][i]==1) h[rk[now][i]]=0;
    else{
        int last=sa[now][rk[now][i]-1];
        while(l1<=min(n-i,n-last)&&a[i+l1]==a[last+l1]) l1++;
        h[rk[now][i]]=l1;if(l1>0) l1--;
    }
}
void init(){
    for(int i=1;i<=30;i++) v[i]=0;
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'a'+1;
	getsa();geth();
	for(int i=1;i<=n;i++)printf("%d ",sa[now][i]);
	printf("\n");
	for(int i=1;i<=n;i++)printf("%d ",h[i]);
	return 0;
}
