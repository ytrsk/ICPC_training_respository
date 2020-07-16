#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
#define lowbit(x) (x)&(-(x))
typedef pair<long long,long long> pii;
typedef long long ll;
const ll maxn=100007;
const ll inf=1<<29;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct nd{
    ll x,y,z,v;
    nd(ll x=0,ll y=0,ll z=0,ll v=0):x(x),y(y),z(z),v(v){}
    bool operator < (nd a) const{
        if(x!=a.x) return x<a.x;
        else if(y!=a.y) return y<a.y;
        else return z<a.z;
    }
}p[maxn],pr[maxn];
ll v[maxn],dp[maxn];
void add(ll o,ll x){
    for(ll i=o;i<=100000;i+=lowbit(i)) v[i]=max(v[i],x);
}
void del(ll o){
    for(ll i=o;i<=100000;i+=lowbit(i)) v[i]=0;
}
ll query(ll o){
    ll x=0;
    for(ll i=o;i;i-=lowbit(i)) x=max(x,v[i]);
    return x;
}
ll A[maxn],B[maxn];
ll T[maxn],P[maxn],C[maxn];
map<ll,ll> ha,Ha;
ll AA[maxn],BB[maxn],CC[maxn];
//外部排序时如表达式(第一位第二位第三位)出现相等的情况，需要调整cmp，如果全部相等，则需缩点
//内部排序时第二维第三维可随意处理，第一维如出现不等号（但是数据中有第一维相等的情况），则无法正确处理
//注意内存
bool cmp(nd x,nd y){
    return x.z<y.z;
}
void cdq(ll l,ll r){
    if(l==r) return;
    ll m=(l+r)>>1;
    sort(p+l,p+r+1);
    cdq(l,m);
    ll top=l;
    sort(p+l,p+m+1,cmp);
    sort(p+m+1,p+r+1,cmp);
    for(ll i=m+1;i<=r;i++){
        while(top<=m&&p[top].z<=p[i].z) add(p[top].y,dp[p[top].v]),top++;
        dp[p[i].v]=max(dp[p[i].v],C[p[i].v]+query(p[i].y));
    }
    for(ll i=l;i<top;i++) del(p[i].y);
    cdq(m+1,r);
}
int main(){
    ll n=read(),m=read();
    for(ll i=1;i<=m;i++) A[i]=read();
    for(ll i=1;i<=m;i++) B[i]=read();
    ll top=0,id=0;
    for(ll i=1;i<=n;i++){
        T[i]=read();P[i]=read();C[i]=read();T[i]=T[i]+B[P[i]];P[i]=A[P[i]];
        ha[T[i]+P[i]]=1;
    }
    ll Now=0;
    for(auto i:ha) Ha[i.first]=++Now;
    for(ll i=1;i<=n;i++){
        AA[i]=T[i];BB[i]=Ha[T[i]+P[i]];CC[i]=T[i]-P[i];
        p[++top]=nd(AA[i],BB[i],CC[i],i);
        dp[i]=C[i];
    }
    sort(p+1,p+top+1);
    cdq(1,top);
    ll mx=0;
    for(ll i=1;i<=n;i++) mx=max(mx,dp[i]);
    cout<<mx;
    return 0;
}
