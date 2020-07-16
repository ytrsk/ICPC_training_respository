#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
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
        ll x=read();ll y=read();
        if(x/2<=y/3) printf("%lld\n",x/2);
        else if(x/4<=y){
            ll z=(3*x-2*y)/10;
            ll j=min((y-z)/3,(x-4*z)/2);
            ll z1=(3*x-2*y)/10+1;
            ll j1=min((y-z1)/3,(x-4*z1)/2);
            printf("%lld\n",max(z+j,z1+j1));
        }
        else printf("%lld\n",y);
    }
    return 0;
}