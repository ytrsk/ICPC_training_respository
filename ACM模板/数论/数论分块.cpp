#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,ans;
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		ans+=(r-l+1)*(n/l);
	}
	return 0;
}

