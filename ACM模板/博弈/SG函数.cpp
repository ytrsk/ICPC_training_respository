#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=107;
int vis[maxn],sg[maxn];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=i;j++) vis[sg[i-j]]=1;
		for(int j=1;j<i;j++) vis[sg[j]^sg[i-j]]=1;
		for(int j=1;;j++){
			if(!vis[j]){
				sg[i]=j;break;
			}
		}
		printf("%d %d\n",i,sg[i]);
	}
	return 0;
}