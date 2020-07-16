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
    int x=read(),y=read(),z=read();
    int a=x+z-y;int b=x-z-y;
    if(a==0&&b==0||a&&b&&a/abs(a)==b/abs(b)){
        if(a==0) printf("0");
        else if(a>0) printf("+");
        else printf("-");
    }
    else printf("?");
    return 0;
}