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
void frac(ll a,ll b,char c){
    if(b==0) return;
    printf("%c%lld",c,a/b);
    frac(b,a%b,',');
}
int main(){
    ll x,y;
    while(scanf("%lld%lld",&x,&y)==2){
        printf("[");
        printf("%lld",x/y);
        if(x%y){
            frac(y,x%y,';');
        }
        printf("]\n");
    }
    return 0;
}