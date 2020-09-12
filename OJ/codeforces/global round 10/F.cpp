#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll h[maxn],a[maxn];
vector<pii> g;
int main(){
    int n=read();
    for(int i=1;i<=n;i++) h[i]=read();
    for(int i=1;i<n;i++) a[i]=h[i+1]-h[i];
    for(int i=1;i<n;i++){
        if(a[i]>=2){
            int now=i;
            while(i+1<n&&a[i+1]>=2) ++i;
            g.push_back(mp(now,i));
        }
    }
    printf("%lld ",);
    for(int i=1;i<n;i++){
        pre+=a[i];
        printf("%lld ",pre);
    }
    return 0;
}