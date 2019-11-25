#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
const long double eps=1e-7;
priority_queue<pair<long double,long double>> q;
long double a,ans;
void add(long double x,long double v){
    long double st=fabs(v)<eps?0.0:x/v,ed=x/(v+2);
    long double t=0;
    while(!q.empty()&&q.top().first>v+eps&&t+eps<ed){
        pair<long double,long double> u=q.top();q.pop();
        long double now=min(u.second,ed-t);
        ans+=now/(u.first+1);
        u.second-=now;
        t+=now;
        if(u.second>eps) q.push(u);
    }
    //cout<<x<<" "<<(x-t)/(v+1)<<" "<<v+1<<" "<<(x-t)<<endl;
    ans+=(x-t)/(v+1);q.push(mp(v,st+t));
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    int n,l;cin>>n>>l;
    long double last=0;
    for(int i=1;i<=n;i++){
        long double x,y,s;cin>>x>>y>>s;
        add(x-last,0);add(y-x,s);last=y;
    }
    add(l-last,0);
    cout<<setprecision(10)<<ans;
    //printf("%.10Lf",ans);
    return 0;
}
