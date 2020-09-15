#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
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
        int r=read(),g=read(),b=read(),w=read();
        if(r%2+g%2+b%2+w%2<=1||r&&b&&g&&(r-1)%2+(g-1)%2+(b-1)%2+(w+1)%2<=1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}