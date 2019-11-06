#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int main(){
 //   cin.tie(0);ios_base::sync_with_stdio(false);
    int t=read();
    while(t--){
        int a=read(),b=read(),c=read(),d=read();
        if(a+d==b+c) printf("%d %d %d %d %d\n",a,b,c,d,d+b-a);
        else printf("%d %d %d %d %lld\n",a,b,c,d,1LL*d*d/c);
    }
    return 0;
}
