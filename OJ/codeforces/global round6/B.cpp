#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
ll read(){
    ll x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int main(){
    int T=read();
    while(T--){
        ll n=read();
        if(n<15) cout<<"NO\n";
        else if(n>=15&&n<=20) cout<<"YES\n";
        else{
            n%=14;
            if(n+14>=15&&n+14<=20) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}