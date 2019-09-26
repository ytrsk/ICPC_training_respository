#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
const double eps=1e-15;
const int maxn=10007;
double ansx,ansy;
int n;
double xx[maxn],yy[maxn],w[maxn];
double calc(double x,double y){
	double tot=0;
	for(int i=1;i<=n;i++){
		tot+=sqrt(sqr(xx[i]-x)+sqr(yy[i]-y))*w[i];
	}
	return tot;
}
void mnth(){
	double T=200;
	while(T>eps){
		double nowx=(ansx+(rand()*2-RAND_MAX)*T);
		double nowy=(ansy+(rand()*2-RAND_MAX)*T);
		double delta=calc(nowx,nowy)-calc(ansx,ansy);
		if(delta<0) ansx=nowx,ansy=nowy;
		else if(exp(-delta/T)*RAND_MAX>rand()) ansx=nowx,ansy=nowy;
		T*=0.999;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&xx[i],&yy[i],&w[i]);
		ansx+=xx[i];ansy+=yy[i];
	}
	ansx/=n;ansy/=n;
	mnth();
	printf("%.3lf %.3lf",ansx,ansy);
	return 0;
}
