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
int a[100007];
int main(){
    int t=read();
    while(t--){
        int n=read(),L=read(),K=read();
        for(int i=1;i<=n;i++) a[i]=read();
        sort(a+1,a+n+1);
        int cnt=n-L+1;
        ll ans=0;
        int fi=1,Now=0;
        dep(i,n-K+1,1){
            ++Now;
            int now=min(max(1,Now%K==1?L-K+1:1),cnt); 
            cnt-=now;
            ans+=1LL*now*a[i];
        }
        cnt=n-L+1;
        ll Ans=0;
        Now=0;
        rep(i,L-K+1,n){
            ++Now;
            int now=min(max(1,Now%(L-K+1)==1?K:1),cnt);
            cnt-=now;
            Ans+=1LL*now*a[i];
        }
        printf("%lld %lld\n",ans,Ans);
    }
    return 0;
}