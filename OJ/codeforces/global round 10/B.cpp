#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll a[maxn];
int main(){
    int t=read();
    while(t--){
        ll n=read(),K=read();
        for(int i=1;i<=n;i++) a[i]=read();
        ll mx=*max_element(a+1,a+n+1);
        for(int i=1;i<=n;i++) a[i]=mx-a[i];
        mx=*max_element(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            printf("%d ",K%2?a[i]:mx-a[i]);
        }
        printf("\n");
    }
    return 0;
}