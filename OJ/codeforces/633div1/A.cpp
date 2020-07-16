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
ll a[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        ll now=0,mx=a[1];
        for(int i=2;i<=n;i++){
            now=max(now,max(0LL,mx-a[i]));
            mx=max(mx,a[i]);
        }
        int m=0;
        for(int i=0;i<=60;i++){
            if(now>>i&1) m=max(m,i+1);
        }
        printf("%d\n",m);
    }
    return 0;
}