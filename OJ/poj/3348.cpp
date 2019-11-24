#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
const int maxn=100007;
const double eps=1e-7;
#define ppb pair<pair<point,point>,bool>
#define pp pair<point,point>
struct point{
	double x,y;
	point(double x=0.0,double y=0.0):x(x),y(y){
	}
	double operator ^ (point a){
		return x*a.y-y*a.x;
	}
	double operator * (point a){
		return x*a.x+y*a.y;
	}
	inline point operator - (point a){
		return point(x-a.x,y-a.y);
	}
	inline point operator + (point a){
		return point(x+a.x,y+a.y);
	}
    inline bool operator == (point a){
        return fabs(x-a.x)<eps&&fabs(y-a.y)<eps;
	}
	inline bool operator < (point a){
        if(fabs(y-a.y)<eps) return x<a.x;
        return y<a.y;
	}
	void print(){
        cout<<x<<" "<<y<<" ";
	}
}p[maxn],s;
bool equal0(double x){
    return fabs(x)<eps;
}
bool equal_num(double x,double y){
    return fabs(x-y)<eps;
}
typedef point vec;
inline double length(point a){
    return sqrt(sqr(a.x)+sqr(a.y));
}
inline double dis(point a,point b){
    return length(a-b);
}
inline double dot(point a,point b,point c){
    return (a-c)*(b-c);
}
inline double mul(point a,point b,point c){
    return (a-c)^(b-c);
}
inline bool cmp(point a,point b){
    if(fabs(mul(a,b,s))<eps) return dis(a,s)<dis(b,s);
    else return mul(a,b,s)>0;
}
inline int sign(double x){
    if(fabs(x)<eps) return 0;
    else if(x>0) return 1;
    else return -1;
}
int top;point q[maxn];
inline void sort_by_angle1(point *p,int n){
    int pos=1;
    for(int i=2;i<=n;i++){
        if(p[i].y+eps<p[pos].y||fabs(p[i].y-p[pos].y)<eps&&p[i].x<p[pos].x) pos=i;
    }
    swap(p[1],p[pos]);s=p[1];
    sort(p+2,p+n+1,cmp);
}
inline void graham(point *p,int n){
    sort_by_angle1(p,n);
    top=0;
    if(n==1){
        q[++top]=p[1];return;
    }
    else if(n==2){
        q[++top]=p[1];q[++top]=p[2];return;
    }
    q[++top]=p[1];q[++top]=p[2];
    for(int i=3;i<=n;i++){
        while(top>=2&&mul(p[i],q[top],q[top-1])>-eps) top--;
        q[++top]=p[i];
    }
}
inline double tri_s(point a,point b,point c){
	return fabs((a-b)^(c-b))/2;
}
void sort_by_angle2(point *p,int n,point a){
    s=a;
    sort(p+1,p+n+1,cmp);
}
//intersection of segment and line
bool parallel(point a,point b,point c,point d){
    return equal0((b-a)^(d-c));
}
bool intersect_line_segment(point a,point b,point c,point d){
    double x=mul(b,c,a)*mul(b,d,a);
    return x<eps;
}
double dis_point_to_line(point a,point b,point c){
    double x=mul(b,a,c);
    return fabs(x)/length(b-c);
}
bool online(point a,point b,point c){
    return equal0(mul(c,b,a));
}
bool onsegment(point a,point b,point c){
    return online(a,b,c)&&dot(b,c,a)<eps;
}
bool onsegment_spec(point a,point b,point c){
    return online(a,b,c)&&dot(b,c,a)<-eps;
}
bool intersect_segment_spec(point a,point b,point c,point d){
    double x1=mul(b,c,a),x2=mul(b,d,a);
    double x3=mul(d,a,c),x4=mul(d,b,c);
    if(equal0(x1)&&equal0(x2)) return onsegment_spec(a,c,d)||onsegment_spec(b,c,d);
    else if(sign(x1*x2)<0&&sign(x3*x4)<0) return true;
    else return false;
}
bool intersect_segment(point a,point b,point c,point d){
    double x1=mul(b,c,a),x2=mul(b,d,a);
    double x3=mul(d,a,c),x4=mul(d,b,c);
    if(equal0(x1)&&equal0(x2)) return onsegment(a,c,d)||onsegment(b,c,d);
    else if(sign(x1*x2)>0||sign(x3*x4)>0) return false;
    else return true;
}
point get_intersect_point(point p1,point p2,point p3,point p4){
    double x1=p1.x,y1=p1.y;
    double x2=p2.x,y2=p2.y;
    double x3=p3.x,y3=p3.y;
    double x4=p4.x,y4=p4.y;
    double t=((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/((x2-x1)*(y3-y4)-(x3-x4)*(y2-y1));
    return point(x3+t*(x4-x3),y3+t*(y4-y3));
}
//probably some eps problem===================================
inline ppb get_intersect_segment(point a,point b,point c,point d){
    if(onsegment(a,c,d)||onsegment(b,c,d)){
        if(b<a) swap(a,b);
        if(d<c) swap(c,d);
        point x,y;
        if(onsegment(c,a,b)) x=c;else x=a;
        if(onsegment(d,a,b)) y=d;else y=b;
        return make_pair(make_pair(x,y),true);
    }
    else return make_pair(make_pair(0,0),false);
}
inline point project_point(point p,point a,point b){
    point ans;
    double u=((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
    u = ((b.x-a.x)*(b.x-p.x)+(b.y-a.y)*(b.y-p.y))/u;
    ans.x=u*a.x+(1-u)*b.x;
    ans.y=u*a.y+(1-u)*b.y;
    return ans;
}
inline ppb project_segment(point a,point b,point c,point d){
    point x=project_point(c,a,b),y=project_point(d,a,b);
    return get_intersect_segment(a,b,x,y);
}
inline pp project_line(point a,point b,point c,point d){
    point x=project_point(c,a,b),y=project_point(d,a,b);
    return make_pair(x,y);
}
//==========================================================
struct segment{
    point a,b;
    segment(point a=point(),point b=point()):a(a),b(b){}
};
struct polygon{
    segment s[21];
    int num;
};
struct circle{
    point o;
    double r;
};
int circle_to_line(circle a,point b,point c){
    double x=dis_point_to_line(a.o,b,c);
    if(fabs(x-a.r)<eps) return 0;
    else if(x<a.r) return 1;
    else return -1;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
bool point_in_poly(point a,point *p,int n){
    for(int i=1;i<n;i++){
        if(mul(p[i],p[i+1],a)<-eps) return false;
    }
    return mul(p[n],p[1],a)>-eps;
}
double poly_area(point *p,int n){
    double ans=0;
    for(int i=1;i<=n;i++) ans+=p[i]^p[i%n+1];
    return fabs(0.5*ans);
}
int main(){
    int n=read();
    for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    graham(p,n);
    double s=poly_area(q,top);
    int x=s/50.0+eps;
    printf("%d",x);
    return 0;
}
