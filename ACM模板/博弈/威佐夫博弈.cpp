//有两堆石子,一次能取一堆中的任意多个,或是两堆同时取相同个数,先取完者胜
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
const double eps=1e-5;
double equal(double x,double y){
	return fabs(x-y)<eps;
}
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)==2){
		if((int)(abs(a-b)*(sqrt(5.0)+1)/2.0)==min(a,b)){
			printf("0\n");
            //先手必输
		}
		else printf("1\n");
            //先手必胜
	}
	return 0;
}