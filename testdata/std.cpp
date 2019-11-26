#include <cstdio>
#include <cstring>

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline char fgc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int readint() {
    register int res = 0, neg = 1;
    register char c = fgc();
    while(c < '0' || c > '9') {
        if(c == '-') neg = -1;
        c = fgc();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = fgc();
    }
    return res * neg;
}

inline bool isop(char c) {
    return c == 'Q' || c == 'C' || c == 'D';
}

inline char readop() {
    register char c;
    while(!isop(c = fgc()));
    return c;
}

const int MAXN = 10005;

struct Edge {
    int to, w, nxt;
} gra[MAXN << 1];
int head[MAXN], tot;

int T, n, m, ut, vt, wt;
char op;
int w[MAXN], fa[MAXN], siz[MAXN], son[MAXN], dfn[MAXN], ptn[MAXN], top[MAXN], dep[MAXN], cnt;

inline void dfs1(int u) {
    siz[u] = 1;
    son[u] = 0;
    for(register int i = head[u]; i; i = gra[i].nxt) {
        register int v = gra[i].to;
        if(v == fa[u]) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        w[v] = gra[i].w;
        dfs1(v);
        siz[u] += siz[v];
        if(siz[v] > siz[son[u]]) son[u] = v;
    }
}

inline void dfs2(int u, int tp) {
    top[u] = tp;
    dfn[u] = ++cnt;
    ptn[dfn[u]] = u;
    if(son[u]) dfs2(son[u], tp);
    for(register int i = head[u]; i; i = gra[i].nxt) {
        register int v = gra[i].to;
        if(v == son[u] || v == fa[u]) continue;
        dfs2(v, v);
    }
}

int sgt[MAXN << 2];

inline void build(int o, int l, int r) {
    if(l == r) {
        sgt[o] = w[ptn[l]];
        return;
    }
    register int mid = (l + r) >> 1, lch = o << 1, rch = (o << 1) | 1;
    build(lch, l, mid);
    build(rch, mid + 1, r);
    sgt[o] = max(sgt[lch], sgt[rch]);
}

inline void modify(int o, int l, int r, int x, int v) {
    if(l == r) {
        sgt[o] = v;
        return;
    }
    register int mid = (l + r) >> 1, lch = o << 1, rch = (o << 1) | 1;
    if(x <= mid) modify(lch, l, mid, x, v);
    else modify(rch, mid + 1, r, x, v);
    sgt[o] = max(sgt[lch], sgt[rch]);
}

inline int query(int o, int l, int r, int ll, int rr) {
    if(l >= ll && r <= rr) {
        return sgt[o];
    }
    register int mid = (l + r) >> 1, lch = o << 1, rch = (o << 1) | 1, res = 0;
    if(ll <= mid) res = max(res, query(lch, l, mid, ll, rr));
    if(rr > mid) res = max(res, query(rch, mid + 1, r, ll, rr));
    return res;
}

inline int query(int u, int v) {
    register int res = 0, tu = top[u], tv = top[v], t;
    while(tu != tv) {
        if(dep[tu] > dep[tv]) {
            t = tu; tu = tv; tv = t;
            t = u; u = v; v = t;
        }
        res = max(res, query(1, 1, n, dfn[tv], dfn[v]));
        v = fa[tv];
        tv = top[v];
    }
    if(dep[u] > dep[v]) { t = u; u = v; v = t; }
    if(u != v) res = max(res, query(1, 1, n, dfn[u] + 1, dfn[v]));
    return res;
}

struct Edge1 {
    int u, v, w;
} edge[MAXN];

int main() {
    T = readint();
    while(T--) {
        tot = cnt = 0;
        memset(head, 0, sizeof(head));
        n = readint();
        for(int i = 1; i < n; i++) {
            ut = readint(); vt = readint(); wt = readint();
            edge[i] = Edge1 {ut, vt, wt};
            gra[++tot] = Edge {vt, wt, head[ut]};
            head[ut] = tot;
            gra[++tot] = Edge {ut, wt, head[vt]};
            head[vt] = tot;
        }
        dfs1(1);
        dfs2(1, 1);
        build(1, 1, n);
        for(;;) {
            op = readop();
            if(op == 'D') break;
            ut = readint();
            vt = readint();
            if(op == 'Q') {
                printf("%d\n", query(ut, vt));
            } else {
                register int u = dep[edge[ut].u] > dep[edge[ut].v] ? edge[ut].u : edge[ut].v;
                modify(1, 1, n, dfn[u], vt);
            }
        }
    }
    return 0;
}