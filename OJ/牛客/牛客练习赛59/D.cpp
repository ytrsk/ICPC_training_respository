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
        ll n=read();
        int ok=0;
        if(n>=2){
            ll now=2,sum=3;ok=1;
            while(n>sum){
                if(ok) now=now*2-1; 
                else now=now*2+1;
                sum+=now;
                ok^=1;
            }
        }
        if(ok) printf("XiaoHuiHui\n");
        else printf("XiaoQiao\n");
    }
    return 0;
}