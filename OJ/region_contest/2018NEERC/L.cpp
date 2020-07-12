#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn],b[maxn];
int n,m;
int check(int x) {
	map <int,int> cnt[2];
	for (int i=0;i<n;i++) {
		int blk = a[i] / x;
		cnt[blk&1][a[i]%x] ++;
	}
	for (int i=0;i<m;i++) {
		int blk = b[i] / x;
		cnt[(blk&1)^1][b[i]%x] ++;
	}
	int ans = 0;
	for (int i=0;i<2;i++) {
		for (auto sel:cnt[i]) ans = max(ans,sel.second);
	}
	return ans;
}
int main() {
	int y1;
	scanf("%d%d",&n,&y1);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int y2;
	scanf("%d%d",&m,&y2);
	for (int i=0;i<m;i++) scanf("%d",&b[i]);
	int ans = 0;
	for (int i=1;i<=(1<<30);i*=2) {
		ans = max(ans,check(i));
		if (i == 1<<30) break;
	}
	printf("%d\n",ans);
	return 0;
}