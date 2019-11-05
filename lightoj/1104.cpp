#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    int n=read(),cnt=0;
    while(n--){
        int x=read();
        double ans=1;
        int now=1;
        while(ans>0.5){
            ans*=(x-now);
            ans/=x;now++;
        }
        printf("Case %d: %d\n",++cnt,now-1);
    }
    return 0;
}
