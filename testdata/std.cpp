#include<bits/stdc++.h>
using namespace std;
#define MAXN	1000005
#define INF	1e9
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct point {int x[2]; } p[MAXN], q[MAXN];
bool querytype[MAXN];
int cmptype;
bool operator == (point a, point b) {
	return a.x[0] == b.x[0] && a.x[1] == b.x[1];
}
bool cmp(point a, point b) {
	return a.x[cmptype] < b.x[cmptype] || a.x[cmptype] == b.x[cmptype] && a.x[cmptype ^ 1] < b.x[cmptype ^ 1];
}
void chkmax(int &x, int y) {
	x = max(x, y);
}
void chkmin(int &x, int y) {
	x = min(x, y);
}
struct KD_Tree {
	struct Node {
		bool active;
		int lc, rc, type;
		point pos, L, R;
	} a[MAXN];
	int n, root, size, nowans;
	point now;
	void update(int root) {
		if (a[root].active) {
			a[root].L = a[root].pos;
			a[root].R = a[root].pos;
		} else {
			a[root].L.x[0] = INF;
			a[root].L.x[1] = INF;
			a[root].R.x[0] = -INF;
			a[root].R.x[1] = -INF;
		}
		if (a[root].lc) {
			int tmp = a[root].lc;
			chkmin(a[root].L.x[0], a[tmp].L.x[0]);
			chkmin(a[root].L.x[1], a[tmp].L.x[1]);
			chkmax(a[root].R.x[0], a[tmp].R.x[0]);
			chkmax(a[root].R.x[1], a[tmp].R.x[1]);
		}
		if (a[root].rc) {
			int tmp = a[root].rc;
			chkmin(a[root].L.x[0], a[tmp].L.x[0]);
			chkmin(a[root].L.x[1], a[tmp].L.x[1]);
			chkmax(a[root].R.x[0], a[tmp].R.x[0]);
			chkmax(a[root].R.x[1], a[tmp].R.x[1]);
		}
	}
	void build(int root, int l, int r, int t) {
		a[root].active = false;
		if (l == r) {
			a[root].pos = p[l];
			a[root].L.x[0] = INF;
			a[root].L.x[1] = INF;
			a[root].R.x[0] = -INF;
			a[root].R.x[1] = -INF;
			a[root].type = t;
			return;
		}
		int mid = (l + r) / 2;
		cmptype = t;
		nth_element(p + l, p + mid, p + r + 1, cmp);
		a[root].pos = p[mid];
		a[root].type = t;
		if (mid > l) {
			a[root].lc = ++size;
			build(size, l, mid - 1, t ^ 1);
		}
		if (mid < r) {
			a[root].rc = ++size;
			build(size, mid + 1, r, t ^ 1);
		}
		update(root);
	}
	void init(int x) {
		n = x; root = size = 1;
		build(size, 1, n, 0);
	}
	int dist(int root, point now) {
		return abs(a[root].pos.x[0] - now.x[0]) + abs(a[root].pos.x[1] - now.x[1]);
	}
	int distmin(int root, point now) {
		if (root == 0 || a[root].L.x[0] == INF) return INF;
		int ans = 0;
		if (now.x[0] <= a[root].L.x[0]) ans += a[root].L.x[0] - now.x[0];
		if (now.x[0] >= a[root].R.x[0]) ans += now.x[0] - a[root].R.x[0];
		if (now.x[1] <= a[root].L.x[1]) ans += a[root].L.x[1] - now.x[1];
		if (now.x[1] >= a[root].R.x[1]) ans += now.x[1] - a[root].R.x[1];
		return ans;
	}
	void querymin(int root) {
		if (a[root].active) {
			int d = dist(root, now);
			chkmin(nowans, d);
		}
		int ld = distmin(a[root].lc, now);
		int rd = distmin(a[root].rc, now);
		if (ld <= rd) {
			if (a[root].lc && ld < nowans) querymin(a[root].lc);
			if (a[root].rc && rd < nowans) querymin(a[root].rc);
		} else {
			if (a[root].rc && rd < nowans) querymin(a[root].rc);
			if (a[root].lc && ld < nowans) querymin(a[root].lc);
		}
	}
	int Querymin(point x) {
		now = x; nowans = INF;
		querymin(root);
		return nowans;
	}
	void insert(int root, int t) {
		if (a[root].pos == now) {
			a[root].active = true;
			update(root);
			return;
		}
		cmptype = t;
		if (cmp(now, a[root].pos)) insert(a[root].lc, t ^ 1);
		else insert(a[root].rc, t ^ 1);
		update(root);
	}
	void Insert(point x) {
		now = x;
		insert(root, 0);
	}
} KDT;
int main() {
    freopen("test.in","r",stdin);
    freopen("std.out","w",stdout);
	int n, m;
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(p[i].x[0]), read(p[i].x[1]);
		q[i] = p[i];
	}
	int tn = n;
	for (int i = 1; i <= m; i++) {
		int opt; read(opt);
		read(q[n + i].x[0]), read(q[n + i].x[1]);
		if (opt == 1) {
			querytype[i] = true;
			p[++tn] = q[n + i];
		} else querytype[i] = false;
	}
	KDT.init(tn);
	for (int i = 1; i <= n; i++)
		KDT.Insert(q[i]);
	for (int i = 1; i <= m; i++)
		if (querytype[i]) KDT.Insert(q[n + i]);
		else printf("%d\n", KDT.Querymin(q[n + i]));
	return 0;
}
