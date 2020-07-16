#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1LL<<61;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll x[5],y[5],v[5];
int main(){
    int t=read();
    while(t--){
        ll K=read(),n=read(),m=read();
        v[1]=v[2]=v[3]=v[4]=inf;
        x[1]=x[2]=0;
        x[3]=x[4]=n;
        y[1]=y[3]=0;
        y[2]=y[4]=m;
        for(int i=1;i<=K;i++){
            ll a=read(),b=read();
            for(int k=1;k<=4;k++) v[k]=min(v[k],abs(a-x[k])+abs(b-y[k]));
        }
        ll ans=-inf;
        for(int i=1;i<=4;i++) ans=max(ans,v[i]);
        printf("%lld\n",ans);
    }
    return 0;
}