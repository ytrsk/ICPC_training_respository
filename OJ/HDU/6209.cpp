#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
typedef long double ld;
ld g(ld a,ld b){
    return a*a*a/(b*b*b);
}
long double f(ld a,ld b,ld c){
    return fabs(g(a,b)-c);
}
int main(){
    int T=read();
    while(T--){
        int x=read();
        ll y=1LL*x*x;
        ll z=(ll)pow(y+0.5,1.0/3);
        if(z*z*z==y){
            printf("%lld/%d\n",z,1);continue;
        }
        long long ansa=0,ansb=1;
        long long la=z,lb=1,ra=z+1,rb=1;
        if(f(la,lb,y)<f(ra,rb,y)) ansa=la,ansb=lb;
        else ansa=ra,ansb=rb;
        ansa=ra,ansb=rb;
        while(1){
            ll mida=la+ra,midb=lb+rb;
            if(midb>100000) break;
            if(f(mida,midb,(ld)y)<f(ansa,ansb,(ld)y)) ansa=mida,ansb=midb;
            if(g(mida,midb)<y) la=mida,lb=midb;
            else ra=mida,rb=midb;
        }
        printf("%lld/%lld\n",ansa,ansb);
    }
    return 0;
}