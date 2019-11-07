#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi = acos(-1);
const int maxn=100007;
const int inf = 1e9 + 7;
typedef struct {
	double x, y, z, r;
}point;
int n;
point a[maxn],s;
double dis(point p,point q) {
	double ans = sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y)+(p.z-q.z)*(p.z-q.z));
	return ans;
}
int main()
{
	int T;scanf("%d", &T);
	int Case = 1;
	while (T--)
	{
	    scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
		}
		scanf("%lf%lf%lf%lf",&s.x,&s.y,&s.z,&s.r);
		double ans=0;
		for (int i=0;i<n;i++) {
			double d = dis(s,a[i]);
			if(d>=s.r+a[i].r) continue;
			else if(d+a[i].r<=s.r) ans+=(4.0/3)*pi*a[i].r*a[i].r*a[i].r;
			else if(d+s.r<=a[i].r) ans+=(4.0/3)*pi*s.r*s.r*s.r;
			else{
				double co=(s.r*s.r+d*d-a[i].r*a[i].r)/(2.0*d*s.r);
				double h=s.r*(1-co);
				ans+=(1.0/3)*pi*(3.0*s.r-h)*h*h;
				co=(a[i].r*a[i].r+d*d-s.r*s.r)/(2.0*d*a[i].r);
				h=a[i].r*(1-co);
				ans+=(1.0/3)*pi*(3.0*a[i].r-h)*h*h;
			}
		}
		ans=-ans;
		ans+=pi*(4.0/3)*(a[0].r*a[0].r*a[0].r+s.r*s.r*s.r);
		printf("%.10lf\n",ans);
	}
	return 0;
}
