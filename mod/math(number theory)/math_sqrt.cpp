#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
int main(){
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		ans+=(r-l+1)*(n/l);
	}
	return 0;
}

