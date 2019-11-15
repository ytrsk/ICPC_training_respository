#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

typedef long long int64;
typedef pair<int64, int> HeapNode;
typedef __gnu_pbds::priority_queue<HeapNode, greater<HeapNode>, __gnu_pbds::pairing_heap_tag>
        pairing_heap;

struct Edge {
    int u, v;
    int64 flow, cap, cost;
    int next;
};

const int MAXN = 5000, MAXM = 50000;
const int64 LLINF = 0x3f3f3f3f3f3f3f3fLL;

int e_ptr = 1, s, t, head[MAXN+10]; Edge E[(MAXM+10)<<1];
int64 dist[MAXN+10], MaxFlow, MinCost, delta;
int inq[MAXN+10], done[MAXN+10], vis[MAXN+10];
pairing_heap pq; pairing_heap :: point_iterator it[MAXN+10];

void AddEdge(int u, int v, int64 cap, int64 cost) {
    E[++e_ptr] = (Edge) { u, v, 0, cap, cost, head[u] }; head[u] = e_ptr;
    E[++e_ptr] = (Edge) { v, u, 0,  0, -cost, head[v] }; head[v] = e_ptr;
}

void Reduce() {
    for(int i = 2; i <= e_ptr; i++)
        E[i].cost += dist[E[i].v] - dist[E[i].u];
    delta += dist[s];
}

bool BellmanFord() {
    queue<int> Q;
    memset(dist, 0x3f, sizeof(dist));
    dist[t] = 0; Q.push(t); inq[t] = true;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop(); inq[u] = false;
        for(int j=head[u]; j; j=E[j].next) {
            int v = E[j].v; int64 f = E[j^1].flow, c = E[j^1].cap, len = E[j^1].cost;
            if(f < c && dist[v] > dist[u] + len) {
                dist[v] = dist[u] + len;
                if(!inq[v]) {
                    inq[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    return dist[s] != LLINF;
}

bool Dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(it, 0, sizeof(it));
    dist[t] = 0; it[t] = pq.push(make_pair(dist[t], t));
    while(!pq.empty()) {
        HeapNode p = pq.top(); pq.pop();
        int u = p.second;
        for(int j=head[u]; j; j=E[j].next) {
            int v = E[j].v; int64 f = E[j^1].flow, c = E[j^1].cap, len = E[j^1].cost;
            if(f < c && dist[v] > dist[u] + len) {
                dist[v] = dist[u] + len;
                if(it[v] == NULL)
                    it[v] = pq.push(make_pair(dist[v], v));
                else
                    pq.modify(it[v], make_pair(dist[v], v));
            }
        }
    }
    return dist[s] != LLINF;
}

int64 DFS(int u, int64 flow) {
    if(u == t || flow == 0) return flow;
    vis[u] = true; // differ from dinic
    int64 res = flow;
    for(int j=head[u]; j; j=E[j].next) {
        int v = E[j].v; int64 f = E[j].flow, c = E[j].cap, len = E[j].cost;
        if(!vis[v] && f < c && len == 0) { // not `dist[v] == dist[u]` ! they do not equal !
            int64 tmp = DFS(v, min(res, c-f)); // len = 0 <=> on the shortest path
            E[j].flow += tmp;
            E[j^1].flow -= tmp;
            res -= tmp;
        }
    }
    return flow - res;
}

void Augment() {
    int64 CurFlow = 0;
    while(memset(vis, 0, sizeof(vis)),
        (CurFlow = DFS(s, LLINF))) {
        MaxFlow += CurFlow;
        MinCost += CurFlow * delta;
    }
}

void PrimalDual() {
    if(!BellmanFord()) return;
    Reduce(); Augment();
    while(Dijkstra()) {
        Reduce(); Augment();
    }
}

int main() {
    int n, m, u, v, cap, cost;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i=1; i<=m; i++) {
        scanf("%d%d%d%d", &u, &v, &cap, &cost);
        AddEdge(u, v, cap, cost);
    }
    PrimalDual();
    printf("%lld %lld", MaxFlow, MinCost);
    return 0;
}#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

typedef long long int64;
typedef pair<int64, int> HeapNode;
typedef __gnu_pbds::priority_queue<HeapNode, greater<HeapNode>, __gnu_pbds::pairing_heap_tag>
        pairing_heap;

struct Edge {
    int u, v;
    int64 flow, cap, cost;
    int next;
};

const int MAXN = 5000, MAXM = 50000;
const int64 LLINF = 0x3f3f3f3f3f3f3f3fLL;

int e_ptr = 1, s, t, head[MAXN+10]; Edge E[(MAXM+10)<<1];
int64 dist[MAXN+10], MaxFlow, MinCost, delta;
int inq[MAXN+10], done[MAXN+10], vis[MAXN+10];
pairing_heap pq; pairing_heap :: point_iterator it[MAXN+10];

void AddEdge(int u, int v, int64 cap, int64 cost) {
    E[++e_ptr] = (Edge) { u, v, 0, cap, cost, head[u] }; head[u] = e_ptr;
    E[++e_ptr] = (Edge) { v, u, 0,  0, -cost, head[v] }; head[v] = e_ptr;
}

void Reduce() {
    for(int i = 2; i <= e_ptr; i++)
        E[i].cost += dist[E[i].v] - dist[E[i].u];
    delta += dist[s];
}

bool BellmanFord() {
    queue<int> Q;
    memset(dist, 0x3f, sizeof(dist));
    dist[t] = 0; Q.push(t); inq[t] = true;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop(); inq[u] = false;
        for(int j=head[u]; j; j=E[j].next) {
            int v = E[j].v; int64 f = E[j^1].flow, c = E[j^1].cap, len = E[j^1].cost;
            if(f < c && dist[v] > dist[u] + len) {
                dist[v] = dist[u] + len;
                if(!inq[v]) {
                    inq[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    return dist[s] != LLINF;
}

bool Dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(it, 0, sizeof(it));
    dist[t] = 0; it[t] = pq.push(make_pair(dist[t], t));
    while(!pq.empty()) {
        HeapNode p = pq.top(); pq.pop();
        int u = p.second;
        for(int j=head[u]; j; j=E[j].next) {
            int v = E[j].v; int64 f = E[j^1].flow, c = E[j^1].cap, len = E[j^1].cost;
            if(f < c && dist[v] > dist[u] + len) {
                dist[v] = dist[u] + len;
                if(it[v] == NULL)
                    it[v] = pq.push(make_pair(dist[v], v));
                else
                    pq.modify(it[v], make_pair(dist[v], v));
            }
        }
    }
    return dist[s] != LLINF;
}

int64 DFS(int u, int64 flow) {
    if(u == t || flow == 0) return flow;
    vis[u] = true; // differ from dinic
    int64 res = flow;
    for(int j=head[u]; j; j=E[j].next) {
        int v = E[j].v; int64 f = E[j].flow, c = E[j].cap, len = E[j].cost;
        if(!vis[v] && f < c && len == 0) { // not `dist[v] == dist[u]` ! they do not equal !
            int64 tmp = DFS(v, min(res, c-f)); // len = 0 <=> on the shortest path
            E[j].flow += tmp;
            E[j^1].flow -= tmp;
            res -= tmp;
        }
    }
    return flow - res;
}

void Augment() {
    int64 CurFlow = 0;
    while(memset(vis, 0, sizeof(vis)),
        (CurFlow = DFS(s, LLINF))) {
        MaxFlow += CurFlow;
        MinCost += CurFlow * delta;
    }
}

void PrimalDual() {
    if(!BellmanFord()) return;
    Reduce(); Augment();
    while(Dijkstra()) {
        Reduce(); Augment();
    }
}

int main() {
    int n, m, u, v, cap, cost;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i=1; i<=m; i++) {
        scanf("%d%d%d%d", &u, &v, &cap, &cost);
        AddEdge(u, v, cap, cost);
    }
    PrimalDual();
    printf("%lld %lld", MaxFlow, MinCost);
    return 0;
}
