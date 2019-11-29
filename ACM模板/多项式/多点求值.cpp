#include <cstdio>
#include <algorithm>
#include <vector>
const int mod = 998244353, G = 3;

namespace Math {
    inline int pw(int base, int p) {
        static int res;
        for (res = 1; p; p >>= 1, base = static_cast<long long> (base) * base % mod) if (p & 1) res = static_cast<long long> (res) * base % mod;
        return res;
    }
    inline int inv(int x) { return pw(x, mod - 2); }
}
inline void reduce(int &x) { x += x >> 31 & mod; }

#define maxn 65536
int a[maxn], ans[maxn];
namespace Poly {
#define N maxn
    int rev[N], lim, s, ilim;
    int Wn[N + 1];
    inline void clear(register int *l, const int *r) {
        if (l >= r) return ;
        while (l != r) *l++ = 0;
    }

    inline void init(const int n) {
        s = -1, lim = 1; while (lim < n) lim <<= 1, ++s; ilim = Math::inv(lim);
        for (register int i = 0; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << s;
        const int t = Math::pw(G, (mod - 1) / lim);
        *Wn = 1; for (register int *i = Wn; i != Wn + lim; ++i) *(i + 1) = static_cast<long long> (*i) * t % mod;
    }
    inline void NTT(int *A, const int op = 1) {
        static int Wt[N];
        for (register int i = 1; i < lim; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
        for (register int mid = 1; mid < lim; mid <<= 1) {
            const int t = lim / mid >> 1;
            *Wt = Wn[op ? 0 : lim];
            for (register int *i = Wt, W = 0; i != Wt + mid; ++i, W += t) *i = Wn[op ? W : lim - W];
            for (register int i = 0; i < lim; i += mid << 1) {
                for (register int j = 0; j < mid; ++j) {
                    const int X = A[i + j], Y = static_cast<long long> (Wt[j]) * A[i + j + mid] % mod;
                    reduce(A[i + j] += Y - mod), reduce(A[i + j + mid] = X - Y);
                }
            }
        }
        if (!op) for (register int *i = A; i != A + lim; ++i) *i = static_cast<long long> (*i) * ilim % mod;
    }

    std::vector<int> P[N << 1], S[N << 1];
    int C[N], D[N];
    void DC_NTT(int rt, int l, int r) {
        if (l == r) { P[rt] = {a[l], 1}; return ; }
        int mid = l + r >> 1;
        DC_NTT(rt << 1, l, mid), DC_NTT(rt << 1 | 1, mid + 1, r);
        int L = rt << 1, R = rt << 1 | 1;
        int n = P[L].size(), m = P[R].size();
        init(n + m - 1);
        std::copy(P[L].begin(), P[L].end(), C); clear(C + n, C + lim);
        std::copy(P[R].begin(), P[R].end(), D); clear(D + m, D + lim);
        NTT(C), NTT(D);
        for (int i = 0; i < lim; ++i) C[i] = static_cast<long long> (C[i]) * D[i] % mod;
        NTT(C, 0);
        P[rt].assign(C, C + n + m - 1);
    }

    int E[N];
    void INV(int *A, int *B, int n) {
        if (n == 1) {
            *B = Math::inv(*A);
            return ;
        }
        INV(A, B, n + 1 >> 1);
        init(n + n - 1);
        std::copy(A, A + n, E); clear(E + n, E + lim);
        clear(B + (n + 1 >> 1), B + lim);
        NTT(B), NTT(E);
        for (int i = 0; i < lim; ++i) B[i] = (2 + mod - static_cast<long long> (B[i]) * E[i] % mod) * B[i] % mod;
        NTT(B, 0); clear(B + n, B + lim);
    }
    int F[N];
    void DIV(int A, int n, int B, int m) {
        const int len = n - m + 1;
        init(len << 1);
        std::reverse_copy(S[A].begin(), S[A].end(), C); clear(C + len, C + lim);
        std::reverse_copy(P[B].begin(), P[B].end(), D); clear(D + len, D + lim);
        clear(F, F + lim);
        INV(D, F, len);
        NTT(C), NTT(F);
        for (int i = 0; i < lim; ++i) F[i] = static_cast<long long> (F[i]) * C[i] % mod;
        NTT(F, 0);
        clear(F + len, F + lim);
    }
    void __DIVMOD(int res, int A, int n, int B, int m) {
        if (n < m) {
            S[res].assign(S[A].begin(), S[A].end());
            return ;
        }
        DIV(A, n, B, m);
        init(n);
        std::reverse_copy(F, F + n - m + 1, C); clear(C + n - m + 1, C + lim);
        std::copy(P[B].begin(), P[B].end(), D); clear(D + m, D + lim);
        NTT(C), NTT(D);
        for (int i = 0; i < lim; ++i) C[i] = static_cast<long long> (C[i]) * D[i] % mod;
        NTT(C, 0);
        for (int i = 0; i < m - 1; ++i) reduce(C[i] = S[A][i] - C[i]);
        S[res].assign(C, C + m - 1);
    }
    void DIVMOD(int res, int A) {
        int n = S[A].size(), m = P[res].size();
        __DIVMOD(res, A, n, res, m);
    }

    void solve(int rt, int l, int r) {
        if (l == r) {
            ans[l] = S[rt][0];
            return ;
        }
        int mid = l + r >> 1;
        DIVMOD(rt << 1, rt), DIVMOD(rt << 1 | 1, rt);
        solve(rt << 1, l, mid), solve(rt << 1 | 1, mid + 1, r);
    }

    void work(int *f, int n, int m) {
        DC_NTT(1, 1, m);
        S[0].assign(f, f + n);
        DIVMOD(1, 0);
        solve(1, 1, m);
    }
#undef N
}

int n, m;
int f[maxn];
int main() {
    scanf("%d%d", &n, &m); if (!m) return 0; ++n;
    for (int i = 0; i < n; ++i) scanf("%d", f + i);
    for (int i = 1; i <= m; ++i) scanf("%d", a + i), reduce(a[i] = -a[i]);
    Poly::work(f, n, m);
    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
    return 0;
}
