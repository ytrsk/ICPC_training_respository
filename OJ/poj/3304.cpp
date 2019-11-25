#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
const int maxn=100007;
const double eps=1e-8;
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
	point operator - (point a){
		return point(x-a.x,y-a.y);
	}
	point operator + (point a){
		return point(x+a.x,y+a.y);
	}
	bool operator == (point a){
        return fabs(x-a.x)<eps&&fabs(y-a.y)<eps;
	}
	bool operator < (point a){
        if(fabs(x-a.x)<eps) return y<a.y;
        return x<a.x;
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
        if(p[i].y<p[pos].y||equal_num(p[i].y,p[pos].y)&&p[i].x<p[pos].x) pos=i;
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
bool parallel(point a,point b,point c,point d){
    return equal0((b-a)^(d-c));
}
bool intersect_line_segment(point a,point b,point c,point d){
    double x=mul(b,c,a)*mul(b,d,a);
    return equal0(x)||x<0;
}
double dis_point_to_line(point a,point b,point c){
    double x=mul(c,b,a);
    return fabs(x)/length(b-c);
}
bool online(point a,point b,point c){
    return equal0(mul(c,b,a));
}
bool onsegment(point a,point b,point c){
    return online(a,b,c)&&sign(dot(b,c,a))<=0;
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
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++){
            scanf("%lf%lf%lf%lf",&p[i*2-1].x,&p[i*2-1].y,&p[i<<1].x,&p[i<<1].y);
        }
        int OK=0;
        for(int i=1;i<=(n<<1);i++){
            for(int z=1;z<=(n<<1);z++){
                point a=p[i],b=p[z];
                if(a==b) continue;
                point ansx=point(),ansy=point()+point((b-a).y,-(b-a).x),nowx=a,nowy=b;int ok=1;
                for(int k=1;k<=n;k++){
                    pp now=project_line(ansx,ansy,p[k*2-1],p[k<<1]);
                    if(k==1){
                        nowx=now.first,nowy=now.second;continue;
                    }
                    ppb x=get_intersect_segment(nowx,nowy,now.first,now.second);
                    if(x.second==false){
                        ok=0;break;
                    }
                    else{
                        now=x.first;nowx=now.first;nowy=now.second;
                    }
                }
                OK|=ok;
            }
        }
        if(OK) printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}