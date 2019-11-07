#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#define ms(i, j) memset(i, j, sizeof i)
#define LL long long
#define db double
#define fir first
#define sec second
#define mp make_pair
using namespace std;

int kase = 0;

namespace flyinthesky {

    const int MAXN = 100000 + 5, LOGS = 20;

    struct edge {
        int v, nxt;
    } ed_o[200000 * 2 + 5], ed_ecc[200000 * 2 + 5];

    int n_o, m_o, en_o, hd_o[MAXN], q;
    int low_o[MAXN], dfn_o[MAXN], sz_o, bri_o[200000 * 2 + 5];
    int siz_ecc, bl_ecc[MAXN];
    int en_ecc, hd_ecc[MAXN];
    int f_ecc[MAXN], dis_ecc[MAXN], pre_ecc[MAXN][LOGS + 5], ans; // 加后缀不会写错

    void ins_o(int u, int v) {ed_o[++en_o] = (edge){v, hd_o[u]}, hd_o[u] = en_o;}
    void ins_ecc(int u, int v) {ed_ecc[++en_ecc] = (edge){v, hd_ecc[u]}, hd_ecc[u] = en_ecc;}
    int find_ecc(int x) {return f_ecc[x] == x ? x : f_ecc[x] = find_ecc(f_ecc[x]);}

    void tarjan_o(int u, int pre) {
        low_o[u] = dfn_o[u] = ++sz_o;
        for (int i = hd_o[u]; i >= 0; i = ed_o[i].nxt) {
            edge &e = ed_o[i];
            if (i != (pre ^ 1)) {
                if (!dfn_o[e.v]) {
                    tarjan_o(e.v, i); // 注意不要写错成 u
                    low_o[u] = min(low_o[u], low_o[e.v]);
                    if (low_o[e.v] > dfn_o[u])
                        bri_o[i] = bri_o[i ^ 1] = 1, ++ans;
                } else low_o[u] = min(low_o[u], dfn_o[e.v]);
            }
        }
    }
    void dfs1_o(int u, int gg) {
        bl_ecc[u] = gg;
        for (int i = hd_o[u]; i >= 0; i = ed_o[i].nxt) {
            edge &e = ed_o[i];
            if (!bl_ecc[e.v] && !bri_o[i]) dfs1_o(e.v, gg);
        }
    }
    void dfs_ecc(int u, int fa) {
        dis_ecc[u] = dis_ecc[fa] + 1, pre_ecc[u][0] = fa; // dis_ecc[1] 要为 1
        for (int i = 1; i <= LOGS; ++i) pre_ecc[u][i] = pre_ecc[pre_ecc[u][i - 1]][i - 1];
        for (int i = hd_ecc[u]; i >= 0; i = ed_ecc[i].nxt) {
            edge &e = ed_ecc[i];
            if (e.v != fa) {
                dfs_ecc(e.v, u);
            }
        }
    }
    int LCA_ecc(int a, int b) {
        if (dis_ecc[a] < dis_ecc[b]) swap(a, b);
        for (int i = LOGS; i >= 0; --i) if (dis_ecc[pre_ecc[a][i]] >= dis_ecc[b]) a = pre_ecc[a][i];
        if (a == b) return a;
        for (int i = LOGS; i >= 0; --i) if (pre_ecc[a][i] != pre_ecc[b][i]) a = pre_ecc[a][i], b = pre_ecc[b][i];
        return pre_ecc[a][0];
    }

    void clean() {
        en_o = -1, ms(hd_o, -1);
        ms(low_o, 0), ms(dfn_o, 0), sz_o = 0, ms(bri_o, 0);
        siz_ecc = 0, ms(bl_ecc, 0);
        en_ecc = -1, ms(hd_ecc, -1);
        ms(dis_ecc, 0), ms(pre_ecc, 0), ans = 0;
    }
    int solve() {

        printf("Case %d:\n", ++kase);

        clean();

        for (int x, y, i = 1; i <= m_o; ++i) scanf("%d%d", &x, &y), ins_o(x, y), ins_o(y, x);

        tarjan_o(1, -1); // tarjan 找桥
        for (int i = 1; i <= n_o; ++i)  // ecc 给点编号
            if (!bl_ecc[i]) dfs1_o(i, ++siz_ecc);

        for (int u = 1; u <= n_o; ++u) { // ecc 加边
            for (int i = hd_o[u]; i >= 0; i = ed_o[i].nxt) {
                edge &e = ed_o[i];
                if (bl_ecc[u] != bl_ecc[e.v]) ins_ecc(bl_ecc[u], bl_ecc[e.v]); // 注意不要写成原来的点
            }
        }

        dfs_ecc(1, 0); // ecc 上预处理

        for (int i = 1; i <= siz_ecc; ++i) f_ecc[i] = i;

        scanf("%d", &q);
        while (q--) {
            int x, y; scanf("%d%d", &x, &y);
            int lca = find_ecc(LCA_ecc(find_ecc(bl_ecc[x]), find_ecc(bl_ecc[y])));
            int cnt = 0;
            int now = find_ecc(bl_ecc[x]);
            while (now != lca) f_ecc[now] = lca, now = find_ecc(pre_ecc[now][0]), ++cnt;
            now = find_ecc(bl_ecc[y]);
            while (now != lca) f_ecc[now] = lca, now = find_ecc(pre_ecc[now][0]), ++cnt;
            ans -= cnt;
            printf("%d\n", ans);
        }

        printf("\n");

        return 0;
    }
}
int main() {
    while (scanf("%d%d", &flyinthesky::n_o, &flyinthesky::m_o) && flyinthesky::n_o && flyinthesky::m_o) flyinthesky::solve();
    return 0;
}
