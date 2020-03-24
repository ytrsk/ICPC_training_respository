#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=10000007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=998244353;
int a[maxn],top,fac[maxn];
int mul(int x,int y){
    return 1LL*x*y%mod;
}
int main(){
    int n=read();fac[0]=1;for(int i=1;i<=n;i++) fac[i]=(10LL*fac[i-1])%mod;
    for(int i=1;i<=n;i++){
        if(i==n) printf("10 ");
        else{
            int x=mul(2,mul(9,fac[n-i-1]));
            int now=x;
            if(i<n-1) now=(now+mul(mul(9*9,n-i-1),fac[n-i-2]))%mod;
            now=mul(now,10);
            printf("%d\n",now);
        }
    }    
    return 0;
}