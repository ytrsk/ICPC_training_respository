#include <bits/stdc++.h>
using namespace std;
long long f(long long x) {
	long long res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long b,x;
		scanf("%lld%lld",&b,&x);
		long long bb = b;
		while (f(bb) != bb) bb = f(bb);
		if ((bb % x == 0) == (b % x == 0)) printf("T\n");
		else printf("F\n");
	}
	return 0;
}
