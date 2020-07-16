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
ll x[maxn],y[maxn];
ll w[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
    for(int i=1;i<=n;i++){
        w[i]=x[i]*x[i]*y[i]+y[i]*y[i]*(y[i]-2*x[i]);
    }
    sort(w+1,w+n+1);
    ll ans=0;
    for(int i=2;i<=n;i++){
        ans+=w[i]-w[i-1];
    }
    cout<<ans;
    return 0;
}