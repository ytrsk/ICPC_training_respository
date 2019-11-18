#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
int getmin(char *s){
	int ql=0,qr=1,pos=0,len=strlen(s),x;
	while(ql<len&&qr<len&&pos<len){
		x=s[(ql+pos)%len]-s[(qr+pos)%len];
		if(!x) pos++;
		else{
			if(x>0) ql+=pos+1;
			else qr+=pos+1;
			if(ql==qr) qr++;
			pos=0;
		}
	}
	return min(ql,qr);
}
int getmax(char *s){
	int ql=0,qr=1,pos=0,len=strlen(s),x;
	while(ql<len&&qr<len&&pos<len){
		x=s[(ql+pos)%len]-s[(qr+pos)%len];
		if(!x) pos++;
		else{
			if(x<0) ql+=pos+1;
			else qr+=pos+1;
			if(ql==qr) qr++;
			pos=0;
		}
	}
	return min(ql,qr);
}
int main(){
	return 0;
}

