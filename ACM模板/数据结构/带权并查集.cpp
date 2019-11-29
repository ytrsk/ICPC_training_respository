#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=10007;
struct query{
	int l,r,id;
}p[maxn];
int len,a[maxn],fa[maxn],v[maxn];
int find(int x){
	if(x==fa[x]) return x;
	else{
		int t=fa[x];
		fa[x]=find(fa[x]);
		if(t!=fa[t]) v[x]^=v[t];
	}
	return fa[x];
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		char s[39];scanf("%d%d%s",&p[i].l,&p[i].r,s+1);
		a[++len]=p[i].l-1;a[++len]=p[i].r;
		if(s[1]=='o') p[i].id=1;
		else p[i].id=0;
	}
	sort(a+1,a+len+1);
	len=unique(a+1,a+len+1)-a-1;
	for(int i=1;i<=len;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		p[i].l=lower_bound(a+1,a+len+1,p[i].l-1)-a;
		p[i].r=lower_bound(a+1,a+len+1,p[i].r)-a;
		if(find(p[i].l)==find(p[i].r)){
			if((v[p[i].l]^v[p[i].r])!=p[i].id){
				printf("%d",i-1);return 0;
			}
		}
		else if(find(p[i].l)<find(p[i].r)){
			v[find(p[i].r)]=(v[p[i].l]^p[i].id^v[p[i].r]);
			fa[find(p[i].r)]=find(p[i].l);
		}
		else{
			v[find(p[i].l)]=(v[p[i].l]^v[p[i].r]^p[i].id);
			fa[find(p[i].l)]=find(p[i].r);
		}
	}
	printf("%d",m);
	return 0;
}
