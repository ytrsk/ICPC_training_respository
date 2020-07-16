#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
const int maxn=300007;
const ll eps=1e-7;
#define ppb pair<pair<point,point>,bool>
#define pp pair<point,point>
struct point{
	ll x,y;
	point(ll x=0,ll y=0):x(x),y(y){
	}
	ll operator ^ (point a){
		return x*a.y-y*a.x;
	}
	ll operator * (point a){
		return x*a.x+y*a.y;
	}
	inline point operator - (point a){
		return point(x-a.x,y-a.y);
	}
	inline point operator + (point a){
		return point(x+a.x,y+a.y);
	}
	inline point operator * (ll a){
        return point(x*a,y*a);
	}
}p[maxn];
ll length(point x){
    return x.x*x.x+x.y*x.y;
}
typedef point vec;
inline ll dot(point a,point b,point c){
    return (a-c)*(b-c);
}
inline ll mul(point a,point b,point c){
    return (a-c)^(b-c);
}
inline int sign(ll x){
    if(x>0) return 1;
    else if(x<0) return -1;
    else return 0;
}
point q[maxn];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
point p1[maxn],p2[maxn],s,t;
int top1,top2;
struct K{
    ll a,b;
    bool operator < (K x)const{
        return (__int128)a*x.b<(__int128)b*x.a;
    }
    bool operator > (K x) const{
        return (__int128)a*x.b>(__int128)b*x.a;
    }
    bool operator <= (K x) const{
        return (__int128)a*x.b<=(__int128)b*x.a;
    }
    bool operator >= (K x) const{
        return (__int128)a*x.b>=(__int128)b*x.a;
    }
        bool operator == (K x) const{
        return (__int128)a*x.b==(__int128)b*x.a;
    }
};
K re(K a){
    return K{-a.a,a.b};
}
K solves(point x){
    return K{((t-s)*(x-s)),length(x-s)};
}
K solvet(point x){
    return K{((t-s)*(x-t)),length(x-t)};
}
bool cmp1a(point a,point b){
    return solves(a)>solves(b);
}
bool cmp1b(point a,point b){
    return solves(a)<solves(b);
}
K val[maxn];
int sz[maxn],e1,rt,fa[maxn],tr[maxn][2],a[maxn],rr[maxn];
void pushup(int x){
    if(!x) return;
    sz[x]=sz[tr[x][0]]+sz[tr[x][1]]+rr[x];
}
void rotate(int x,int &o){
    int y=fa[x],z=fa[y],l=(tr[y][1]==x),r=l^1;
    if(y==o) o=x;
    else tr[z][tr[z][1]==y]=x;
    fa[x]=z;fa[y]=x;fa[tr[x][r]]=y;
    tr[y][l]=tr[x][r];tr[x][r]=y;
    pushup(y);pushup(x);
}
void splay(int x,int &o){
    int y,z;
    while(x!=o){
        y=fa[x],z=fa[y];
        if(y!=o){
            if(tr[y][0]==x^tr[z][0]==y) rotate(x,o);
            else rotate(y,o);
        }
        rotate(x,o);
    }
}
void ins(int &o,int p,K x){
    if(!o){
        o=++e1;val[o]=x;fa[o]=p;tr[o][0]=tr[o][1]=0;sz[o]=rr[o]=1;
        splay(o,rt);return;
    }
    else if(val[o]==x){
        rr[o]++;sz[o]++;return;
    }
    ins(tr[o][x>val[o]],o,x);
    pushup(o);
}
int querysz(int o,K x){
    if(!o) return 0;
    if(val[o]<=x) return sz[tr[o][0]]+rr[o]+querysz(tr[o][1],x);
    else return querysz(tr[o][0],x); 
}
int main(){
    int n=read();
    s.x=read();s.y=read();t.x=read();t.y=read();
    for(int i=1;i<=n;i++){
        p[i].x=read();p[i].y=read();
        if(sign(mul(t,p[i],s))==1) p1[++top1]=p[i];
        else p2[++top2]=p[i]; 
    }
    ll ans=0;rt=e1=0;        
    sort(p1+1,p1+top1+1,cmp1a);
    sort(p2+1,p2+top2+1,cmp1a);
    for(int i=1;i<=top1;i++){
        ans+=querysz(rt,solvet(p1[i]));
        ins(rt,0,solvet(p1[i]));
    }
    rt=e1=0;
    for(int i=1;i<=top2;i++){
        ans+=querysz(rt,solvet(p2[i]));
        ins(rt,0,solvet(p2[i]));
    }
    rt=e1=0;
    if(top1==0||top2==0) printf("%lld",ans);
    else{
        sort(p2+1,p2+top2+1,cmp1b);
        int now=top2;
        for(int i=top1;i;i--){
            while(now>=1&&solves(p2[now])>=re(solves(p1[i]))) ins(rt,0,solvet(p2[now])),now--;
            ans+=querysz(rt,re(solvet(p1[i])));
        }
        printf("%lld",ans);
    }
    return 0;
}
