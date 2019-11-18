#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=200007;
int n,st[maxn][32],val[maxn],lg[maxn];
inline void init(){
	for(int i=1;i<=n;i++) st[i][0]=val[i];
	for(int i=1;(1<<i)<=n;i++){
		for(int k=1;k+(1<<i)-1<=n;k++){
			st[k][i]=max(st[k][i-1],st[k+(1<<i-1)][i-1]);
		}
	}
	for(int i=1;i<=n;i++) lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
}
inline int query(int l,int r){
    int x=lg[r-l+1];
    return max(st[l][x],st[r-(1<<x)+1][x]);
}
int main(){
	return 0;
}
