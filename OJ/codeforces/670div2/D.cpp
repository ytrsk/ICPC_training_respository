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
ll a[maxn],d[maxn];
int main(){
    int n=read();
    rep(i,1,n) a[i]=read(),d[i]=a[i]-a[i-1];
    int q=read();
    ll up=0,fi=a[1];
    rep(i,2,n) up+=max(0LL,d[i]);
    printf("%lld\n",fi+up>0?(fi+up-1)/2+1:(fi+up)/2);
    for(int i=1;i<=q;i++){
        ll l=read(),r=read(),x=read();
        if(l==1) up+=x;
        if(r+1<=n){
            up-=max(0LL,d[r+1]);
            d[r+1]-=x;
            up+=max(0LL,d[r+1]);
        }
        if(l>=2){
            up-=max(0LL,d[l]);
            d[l]+=x;
            up+=max(0LL,d[l]);
        }
        x=fi+up;
        printf("%lld\n",x>0?(x-1)/2+1:x/2);
    }
    return 0;
}