#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("F.in","w",stdout);
	int T = 1;
	printf("%d\n",T);
	while (T --) {
		int n = 100000;
		set <pair<int,int> > s;
		for (int i=0;i<n;i++) {
			int u = 1 + (rand() % n);
			int v = 1 + (rand() % n);
			if (u == v) continue;
			if (u > v) swap(u,v);
			s.insert({u,v});
		}
		int m = s.size();
		printf("%d %d\n",n,m);
		for (int i=1;i<=n;i++) printf("%d ",(rand()&1)?2:3);
		printf("\n");
		for (auto x:s) printf("%d %d\n",x.first,x.second);
		int q = 100000;
		printf("%d\n",q);
		while (q --) {
			int op = 1+(rand()&1);
			if (op == 1) {
				printf("%d %d %d\n",1,1+(rand()%n),1);
			}
			else {
				printf("%d %d\n",2,1+(rand()%n));
			}
		}
	}
	return 0;
}
