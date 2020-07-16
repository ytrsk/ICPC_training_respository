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
int main(){
    int t=read();
    while(t--){
        ll n=read();
        ll L=read(),R=read();
        ll now=2*(n-1),pos=1;
        for(ll i=L;i<=R;i++){
            if(i==n*(n-1)+1) printf("1 ");
            else{
                while(now<i){
                    pos++;now+=2*(n-pos);
                }
                ll x=now-2*(n-pos);
                if((i-x)%2) printf("%lld ",pos);
                else printf("%lld ",pos+(i-x)/2);
            }
        }
        printf("\n");
    }
    return 0;
}