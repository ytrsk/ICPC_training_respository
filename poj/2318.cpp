#include <stdio.h>
#include <algorithm>
#include <math.h>
#define sqr(x) (x)*(x)
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const double eps=1e-7;
struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){
	}
	int operator ^ (point a){
		return x*a.y-y*a.x;
	}
	int operator * (point a){
		return x*a.x+y*a.y;
	}
	point operator - (point a){
		return point(x-a.x,y-a.y);
	}
	point operator + (point a){
		return point(x+a.x,y+a.y);
	}
}p[maxn],s;
double length(point a){
    return sqrt(sqr(a.x)+sqr(a.y));
}
int dis(point a,point b){
    return length(a-b);
}
int dot(point a,point b,point c){
    return (a-c)*(b-c);
}
int mul(point a,point b,point c){
    return (a-c)^(b-c);
}
bool equal0(int x){
    return x;
}
int online(point a,point b,point c){
    return equal0(mul(b,c,a));
}
int tot[maxn];
int main(){
    int n,m;
    while(scanf("%d",&n)==1&&n){
        m=read();
        int x1=read(),y1=read(),x2=read(),y2=read();
        for(int i=1;i<=n;i++){
            p[i].x=read();p[i].y=read();
        }
        for(int i=0;i<=n;i++) tot[i]=0;
        for(int i=1;i<=m;i++){
            int x=read(),y=read();
            int l=1,r=n,ans=n;
            while(l<=r){
                int mid=(l+r)>>1;
                if(mul(point(p[mid].y,y2),point(x,y),point(p[mid].x,y1))<0){
                   r=mid-1;ans=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            tot[ans]++;
        }
        for(int i=0;i<=n;i++){
            printf("%d: %d\n",i,tot[i]);
        }
        printf("\n");
    }
    return 0;
}
