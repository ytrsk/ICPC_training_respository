#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;return;
	}
	exgcd(b,a%b,y,x);y-=(a/b)*x;
}
int main(){
	int x,y;scanf("%d%d",&x,&y);
	int a,b;exgcd(x,y,a,b);
	cout<<a<<" "<<b<<endl;
	return 0;
}
