#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
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
        ll a=read(),b=read(),x=read(),y=read(),n=read();
        ll ans1=n<=a-x?(a-n)*b:x*max(y,b-(n-(a-x)));
        swap(a,b);swap(x,y);
        ll ans2=n<=a-x?(a-n)*b:x*max(y,b-(n-(a-x)));
        printf("%lld\n",min(ans1,ans2));
    }
    return 0;
}