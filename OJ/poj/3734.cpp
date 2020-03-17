#include <stdio.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
const int mod=10007;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int main(){
    int t=read();
    while(t--){
        int n=read();
        printf("%d\n",1LL*(pown(4,n)+pown(2,n+1))*pown(4,mod-2)%mod);
    }
    return 0;
}