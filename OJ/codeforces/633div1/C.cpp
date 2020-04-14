#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    int t=read();
    while(t--){
        ll n=read();
        ll m=(n-1)/3+1;
        int pos=0;ll now=1;
        while(m>now) pos+=2,now+=1LL<<pos;
        ll x=now-(1LL<<pos);
        m=m-x;
        ll ans1=m+(1LL<<pos)-1,ans2=0;
        ans2+=(1LL<<pos)+(1LL<<pos+1);
        for(int i=pos;i;i-=2){
            if(m<=(1LL<<i-2)) continue;
            else if(m<=(1LL<<i-1)) m-=(1LL<<i-2),ans2+=(1LL<<i-1)+(1LL<<i-2);
            else if(m<=(1LL<<i-1)+(1LL<<i-2)) m-=(1LL<<i-1),ans2+=(1LL<<i-2);
            else m-=(1LL<<i-1)+(1LL<<i-2),ans2+=(1LL<<i-1);
        }
        if(n%3==1) printf("%lld\n",ans1);
        else if(n%3==0) printf("%lld\n",ans2);
        else printf("%lld\n",ans1^ans2);
    }
    return 0;
}