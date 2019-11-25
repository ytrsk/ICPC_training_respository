#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn];
double to(double a,double b,double c){
    return sqr(a-c)-sqr(b-c);
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        ++cnt;
        int n=read(),m=read();
        priority_queue<pair<double,pair<int,int> > > q;
        double mid=0,sum=0;
        for(int i=1;i<=n;i++) a[i]=read(),mid+=a[i],sum+=a[i];
        mid/=m;
        double ans=mid*mid*m;
        for(int i=1;i<=n;i++){
            ans-=2*a[i]*mid;
            q.push(mp(a[i]*a[i]/1.0-sqr(a[i])/2.0,mp(1,a[i])));
            ans+=1.0*a[i]*a[i];
        }
     //   cout<<ans<<endl;
        int last=m-n;
        while(last--){
            pair<double,pair<int,int> > u=q.top();q.pop();
            ans-=u.first;
            u.second.first++;
            u.first=1.0*sqr(u.second.second)/u.second.first-1.0*sqr(u.second.second)/(u.second.first+1);
            q.push(u);
        }
        printf("Case #%d: %.9f\n",cnt,ans/m);
    }
    return 0;
}
