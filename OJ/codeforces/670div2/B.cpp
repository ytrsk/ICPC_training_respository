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
ll a[maxn];
ll top,Top,q[maxn],Q[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        top=Top=0;
        if(n==5) printf("%lld\n",a[1]*a[2]*a[3]*a[4]*a[5]);
        else{
            for(int i=1;i<=n;i++){
                if(a[i]<0) q[++top]=-a[i];
                else Q[++Top]=a[i];
            }
            ll mx=0;
            sort(q+1,q+top+1);
            reverse(q+1,q+top+1);
            sort(Q+1,Q+Top+1);
            reverse(Q+1,Q+Top+1);
            if(top>=0&&Top>=5) mx=max(mx,Q[1]*Q[2]*Q[3]*Q[4]*Q[5]);
            if(top>=2&&Top>=3) mx=max(mx,q[1]*q[2]*Q[1]*Q[2]*Q[3]);
            if(top>=4&&Top>=1) mx=max(mx,q[1]*q[2]*q[3]*q[4]*Q[1]);
            reverse(q+1,q+top+1);
            if(Top) printf("%lld\n",mx);
            else printf("%lld\n",-q[1]*q[2]*q[3]*q[4]*q[5]); 
        }
    }
    return 0;
}