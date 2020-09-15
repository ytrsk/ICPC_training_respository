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
int a[maxn];
int top,q[maxn],Top,Q[maxn];
ll sum[maxn];
int main(){
    int n=read(),d=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        if(a[i]<=m) q[++top]=a[i];
        else Q[++Top]=a[i];
    }
    sort(q+1,q+top+1);
    reverse(q+1,q+top+1);
    sort(Q+1,Q+Top+1);
    reverse(Q+1,Q+Top+1);
    for(int i=1;i<=top;i++) sum[i]=sum[i-1]+q[i];
    ll Sum=0,ans=0;
    for(int i=0;i<=Top;i++){
        Sum+=Q[i];
        if(i&&1LL*(i-1)*d-(Top-i)>top) continue;
        ans=max(ans,Sum+sum[top-max(1LL*(i-1)*d-Top+i,0LL)]);
    }
    printf("%lld",ans);
    return 0;
}