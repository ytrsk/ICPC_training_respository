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
typedef long long ll;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;return;
	}
	exgcd(b,a%b,y,x);y-=x*(a/b);
}
ll a[maxn];
ll A[maxn],B[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    if(n==1){
        printf("1 1\n");
        printf("%lld\n",-a[1]);
        printf("1 1\n0\n1 1\n0");
        return 0;
    }
    ll x,y;
    exgcd(n,n-1,x,y);
    printf("%d %d\n",1,n-1);
    for(int i=1;i<=n-1;i++) printf("%lld ",-a[i]*y*(n-1));
    printf("\n%d %d\n",1,n);
    for(int i=1;i<=n-1;i++) printf("%lld ",-a[i]*x*n);
    printf("0");
    printf("\n%d %d\n",n,n);
    printf("%lld\n",-a[n]);
    return 0;
}