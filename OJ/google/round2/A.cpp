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
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll L,R;
int main(){
    int T=read();ll e=0;
    while(T--){
        L=read(),R=read();
        ll now=1,cnt=0;
        while(max(L,R)>=now){
            ++cnt;
            if(L>=R) L-=now;
            else R-=now;
            now++;
        }
        printf("Case #%lld: %lld %lld %lld\n",++e,cnt,L,R);
    }
    return 0;
}