#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
const int maxn=307;
const double eps=1e-7;
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
	point operator - (point a){
		return point(x-a.x,y-a.y);
	}
	point operator + (point a){
		return point(x+a.x,y+a.y);
	}
}p[maxn],s;
bool euqal0(double x){
    return fabs(x)<1e-7;
}
struct segment{

};
typedef point vec;
double length(point a){
    return sqrt(sqr(a.x)+sqr(a.y));
}
double dis(point a,point b){
    return length(a-b);
}
double dot(point a,point b,point c){
    return (a-c)*(b-c);
}
double mul(point a,point b,point c){
    return (a-c)^(b-c);
}
bool cmp(point a,point b){
    if(fabs(mul(a,b,s))<eps) return dis(a,s)<dis(b,s);
    else return mul(a,b,s)>0;
}
int sign(double x){
    if(fabs(x)<eps) return 0;
    else if(x>0) return 1;
    else return -1;
}
int top;point q[maxn];
void sort_by_angle1(point *p,int n){
    int pos=1;
    for(int i=2;i<=n;i++){
        if(p[i].y<p[pos].y||p[i].y==p[pos].y&&p[i].x<p[pos].x) pos=i;
    }
    swap(p[1],p[pos]);s=p[1];
    sort(p+2,p+n+1,cmp);
}
void graham(point *p,int n){
    sort_by_angle1(p,n);
    top=0;
    if(n==1){
        q[++top]=p[1];return;
    }
    else if(n==2){
        q[++top]=p[1];q[++top]=p[2];return;
    }
    q[++top]=p[1];q[++top]=p[2];q[++top]=p[3];
    for(int i=4;i<=n;i++){
        while(top>=2&&mul(p[i],q[top],q[top-1])>=0) top--;
        q[++top]=p[i];
    }
}
double tri_s(point a,point b,point c){
	return fabs((a-b)^(c-b))/2;
}
void sort_by_angle2(point *p,point a,int n){
    s=a;
    sort(p+1,p+n+1,cmp);
}
//intersection of segment and line
bool isColide_ls(point a,point b,point c,point d){
    double x=mul(c,b,a)*mul(d,b,a);
    return !equal0(x)||x<0;
}
double point_line_len(point a,point b,point c){
    double x=mul(c,b,a);
    return x/length(b-c);
}
bool online(point a,point b,point c){
    return equal0(point_line_len(a,b,c));
}
bool onsegment(point a,point b,point c){
    return online(a,b,c)&&sign(dot(b,c,a))>=0;
}
bool isColide_ss(point a,point b,point c,point d){
    double x1=mul(b,c,a),x2=mul(b,d,a);
    double x3=mul(d,a,c),x4=mul(d,b,c);
    if(equal0(x1)&&equal0(x2)) return onsegment(a,c,d)||onsegment(b,c,d);
    else if(sign(x1*x2)>0||sign(x3*x4)>0) return false;
    else return true;
}
point getpoint(point p1, point p2, point p3, point p4){
    double x1 = p1.x, y1 = p1.y;
    double x2 = p2.x, y2 = p2.y;
    double x3 = p3.x, y3 = p3.y;
    double x4 = p4.x, y4 = p4.y;
    double t = ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) / ((x2 - x1)*(y3 - y4) - (x3 - x4)*(y2 - y1));
    return point(x3 + t*(x4 - x3), y3 + t*(y4 - y3));
}
int main(){

    return 0;
}
