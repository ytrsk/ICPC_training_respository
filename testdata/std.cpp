#include<cstdio>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
const int MAXN = 400001, INF = 1e9 + 10;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9'){if(c == '-')f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
struct Query {
    int t, x, val, type, id;
    bool operator < (const Query &rhs) const {
        return x == rhs.x ? val < rhs.val : x < rhs.x;
    }
}Q[MAXN], Tp[MAXN];
int N, M, a[MAXN], pos[MAXN], tim;
LL ans[MAXN];

#define lb(x) (x & -x)
int T[MAXN];
void Add(int pos, int val) {for(int i = pos; i <= N; i += lb(i)) T[i] += val;}
int Sum(int pos) {int ans = 0; for(int i = pos; i >= 1; i -= lb(i)) ans += T[i]; return ans;}

void CDQ(int l, int r) {
    if(l == r) return;
    int mid = l + r >> 1;
    for(int i = l; i <= r; i++)
        if(Q[i].t <= mid) Add(Q[i].val, Q[i].type);
        else ans[Q[i].id] += Q[i].type * (Sum(N) - Sum(Q[i].val));
    for(int i = l; i <= r; i++) if(Q[i].t <= mid) Add(Q[i].val, -Q[i].type);

    for(int i = r; i >= l; i--)
        if(Q[i].t <= mid) Add(Q[i].val, Q[i].type);
        else ans[Q[i].id] += Q[i].type * (Sum(Q[i].val - 1));
    for(int i = l; i <= r; i++)if(Q[i].t <= mid) Add(Q[i].val, -Q[i].type);

    int p1 = l, p2 = mid + 1;
    for(int i = l; i <= r; i++)
        if(Q[i].t <= mid) Tp[p1++] = Q[i];
        else Tp[p2++] = Q[i];
    for(int i = l; i <= r; i++) Q[i] = Tp[i];
    CDQ(l, mid); CDQ(mid + 1, r);
}
int main() {
#ifdef WIN32
    //freopen("a.in", "r", stdin);
#endif
    N = read(); M = read();
    for(int i = 1; i <= N; i++) {
        a[i] = read(); pos[a[i]] = i ;
        Q[++tim] = (Query) {tim, i, a[i], 1, 0};
    }
    for(int i = 1; i <= M; i++) {
        int x = read();
        Q[++tim] = (Query) {tim, pos[x], x, -1, i};
    }
    sort(Q + 1, Q + tim + 1);
    CDQ(1, tim);
    for(int i = 1; i <= M; i++) {
        ans[i] += ans[i - 1];
        printf("%lld\n", ans[i - 1]);
    }
    return 0;
}
