#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=300007;
const ll inf=1<<29;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll a[maxn],b[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        ll sum=0;
        for(int i=1;i<=n;i++){
            a[i]=read();b[i]=read();
            if(i-1) sum+=max(0LL,a[i]-b[i-1]);
        }
        sum+=max(0LL,a[1]-b[n]);
        ll mn=0x7f7f7f7f7f7f7f7f;
        for(int i=1;i<=n;i++){
            ll x=(i==1)?max(0LL,a[1]-b[n]):max(0LL,a[i]-b[i-1]);
            mn=min(mn,sum-x+a[i]);
        }
        cout<<mn<<"\n";
    }
    return 0;
}