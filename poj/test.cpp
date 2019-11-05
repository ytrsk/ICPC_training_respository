#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const int maxn = 105;

int dq[maxn], top, bot, pn, order[maxn], ln;
struct Point {
    double x, y;
    void print(){
        cout<<x<<" "<<y<<" ";
    }
} p[maxn];

struct Line {
    Point a, b;
    void print(){
        a.print();b.print();cout<<endl;
    }
    double angle;
} l[maxn];

int dblcmp(double k) {
    if (fabs(k) < eps) return 0;
    return k > 0 ? 1 : -1;
}

double multi(Point p0, Point p1, Point p2) {
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

bool cmp(int u, int v) {
    int d = dblcmp(l[u].angle-l[v].angle);
    if (!d) return dblcmp(multi(l[u].a, l[v].a, l[v].b)) < 0;
    return d < 0;
}

void getIntersect(Line l1, Line l2, Point& p) {
    double dot1,dot2;
    dot1 = multi(l2.a, l1.b, l1.a);
    dot2 = multi(l1.b, l2.b, l1.a);
    p.x = (l2.a.x * dot2 + l2.b.x * dot1) / (dot2 + dot1);
    p.y = (l2.a.y * dot2 + l2.b.y * dot1) / (dot2 + dot1);
}

bool judge(Line l0, Line l1, Line l2) {
    Point p;
    getIntersect(l1, l2, p);
    return dblcmp(multi(p, l0.a, l0.b)) > 0;
}

void addLine(double x1, double y1, double x2, double y2) {
    l[ln].a.x = x1; l[ln].a.y = y1;
    l[ln].b.x = x2; l[ln].b.y = y2;
    l[ln].angle = atan2(y2-y1, x2-x1);
    order[ln] = ln;
    ln++;
}

void halfPlaneIntersection() {
    int i, j;
    sort(order, order+ln, cmp);
    for (i = 1, j = 0; i < ln; i++)
        if (dblcmp(l[order[i]].angle-l[order[j]].angle) > 0)
            order[++j] = order[i];
    ln = j + 1;
    dq[0] = order[0];
    dq[1] = order[1];
    bot = 0;
    top = 1;
    for (i = 2; i < ln; i++) {
        while (bot < top && judge(l[order[i]], l[dq[top-1]], l[dq[top]])) top--;
        while (bot < top && judge(l[order[i]], l[dq[bot+1]], l[dq[bot]])) bot++;
        dq[++top] = order[i];
    }
    while (bot < top && judge(l[dq[bot]], l[dq[top-1]], l[dq[top]])) top--;
    while (bot < top && judge(l[dq[top]], l[dq[bot+1]], l[dq[bot]])) bot++;
}

bool isThereACore() {
    if (top-bot > 1) return true;
    return false;
}
int main()
{
    int t, i;

    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &pn);
        for (i = 0; i < pn; i++)
            scanf ("%lf%lf", &p[i].x, &p[i].y);
        for (ln = i = 0; i < pn-1; i++)
            addLine(p[i].x, p[i].y, p[i+1].x, p[i+1].y);
        addLine(p[i].x, p[i].y, p[0].x, p[0].y);
        halfPlaneIntersection();
        if (isThereACore()) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}
