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
int main(){
    int t=read();
    while(t--){
        int a=read(),b=read(),d=read(),t=read();
        long double now=-3*t*t*(a+b)*(long double)6.67430*(1e-11)+2*d*d*d;
        printf("%.12f\n",(double)pow(now/2,(long double)1/3.0));
    }
    return 0;
}