#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    int t= read();
    while(t--){
        ll x=read(),y=read(),a=read(),b=read();
        if(x*y<0) printf("%lld\n",a*(abs(x)+abs(y)));
        else printf("%lld\n",min(2*a,b)*min(abs(x),abs(y))+a*(max(abs(x),abs(y))-min(abs(x),abs(y))));
    }
    return 0;
}