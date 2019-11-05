#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
typedef double db;
const db eps=1e-6;
const db pi=acos(-1);
int sign(db k){
    if (k>eps) return 1; else if (k<-eps) return -1; return 0;
}
int cmp(db k1,db k2){return sign(k1-k2);}
struct point{
    db x,y;
    point operator + (const point &k1) const{return (point){k1.x+x,k1.y+y};}
    point operator - (const point &k1) const{return (point){x-k1.x,y-k1.y};}
    point operator * (db k1) const{return (point){x*k1,y*k1};}
    point operator / (db k1) const{return (point){x/k1,y/k1};}
    db abs(){ return sqrt(x*x+y*y);}
};
db cross(point k1,point k2){return k1.x*k2.y-k1.y*k2.x;}
db dot(point k1,point k2){return k1.x*k2.x+k1.y*k2.y;}
point getLL(point k1,point k2,point k3,point k4){
    db w1=cross(k1-k3,k4-k3),w2=cross(k4-k3,k2-k3); return (k1*w2+k2*w1)/(w1+w2);
}
int intersect(db l1,db r1,db l2,db r2){
    if (l1>r1) swap(l1,r1); if (l2>r2) swap(l2,r2); return cmp(r1,l2)!=-1&&cmp(r2,l1)!=-1;
}
int checkSS(point k1,point k2,point k3,point k4){
    return intersect(k1.x,k2.x,k3.x,k4.x)&&intersect(k1.y,k2.y,k3.y,k4.y)&&
           sign(cross(k3-k1,k4-k1))*sign(cross(k3-k2,k4-k2))<=0&&
           sign(cross(k1-k3,k2-k3))*sign(cross(k1-k4,k2-k4))<=0;
}
struct line{
    point p[2];
    line(point k1,point k2){p[0]=k1; p[1]=k2;}
};
double l,r,y;
point p[10005];
int n;
point s1,t1,s2,t2;
//离散化+前缀和。
vector<db> v,a,b;
int pre[100005];
int main(){
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(2);
    while (cin>>l>>r>>y&&(l||r||y)){
        s1={l,y};t1={r,y};
        cin>>l>>r>>y;
        s2={l,y};t2={r,y};
        v.push_back(l);
        v.push_back(r);
        cin>>n;
        for(int i=1;i<=2*n;i+=2){
            cin>>l>>r>>y;
            p[i]={l,y};
            p[i+1]={r,y};
        }
        for(int i=1;i<=2*n;i+=2){
            if(cmp(s1.y,p[i].y)==1&&cmp(p[i].y,s2.y)==1){//在中间
                point tmp = getLL(t1,p[i],s2,t2);
                v.push_back(tmp.x);//-1
                a.push_back(tmp.x);
                tmp = getLL(s1,p[i+1],s2,t2);
                v.push_back(tmp.x);//+1
                b.push_back(tmp.x);
            }
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=0;i<a.size();i++){
            int id = lower_bound(v.begin(),v.end(),a[i])-v.begin();
            pre[id]--;
        }
        for(int i=0;i<b.size();i++){
            int id = lower_bound(v.begin(),v.end(),b[i])-v.begin();
            pre[id]++;
        }
        int id1 = lower_bound(v.begin(),v.end(),s2.x)-v.begin();
        int id2 = lower_bound(v.begin(),v.end(),t2.x)-v.begin();
        for(int i=1;i<v.size();i++){
            pre[i]+=pre[i-1];
        }
        db ans = 0;
        for(int l=id1,r;l<=id2;l=r+1){
            r=l;
            while (r<id2&&pre[r]>=0)
                r++;
            ans=max(ans,v[r]-v[l]);
        }
        if(cmp(ans,0.00)==0){
            cout<<"No View"<<endl;
        } else {
            cout << ans << endl;
        }
        v.clear();
        a.clear();
        b.clear();
        memset(pre,0, sizeof(pre));
    }
}
/**
 2 6 6
 0 15 0
 1
 2 6 7

 2 6 6
 0 15 0
 1
 2 6 7
 2 6 6
 0 15 0
 1
 4 4.5 5.5
 2 6 6
 0 15 0
 16
 0 1 3
 1.5 2 3
 2.5 3 3
 3.5 4 3
 4.5 5 3
 5.5 6 3
 6.5 7 3
 7.5 8 3
 8.5 9 3
 9.5 10 3
 10.5 11 3
 11.5 12 3
 12.5 13 3
 13.5 14 3
 14.5 15 3
 15.5 16 3
 2 6 6
 0 15 0
 16
 0 1 .1
 1.5 2 .1
 2.5 3 .1
 3.5 4 .1
 4.5 5 .1
 5.5 6 .1
 6.5 7 .1
 7.5 8 .1
 8.5 9 .1
 9.5 10 .1
 10.5 11 .1
 11.5 12 .1
 12.5 13 .1
 13.5 14 .1
 14.5 15 .1
 15.5 16 .1
 2 6 6
 0 15 0
 14
 0 1 3
 1.5 2 3
 2.5 3 3
 3.5 4 3
 4.5 5 3
 5.5 6 3
 8.5 9 3
 9.5 10 3
 10.5 11 3
 11.5 12 3
 12.5 13 3
 13.5 14 3
 14.5 15 3
 15.5 16 3


 2 6 6
 0 15 1
 5
 1 1.5 6
 17 18 1
 3 5 3
 0 20 10
 0 20 0.5
 */
