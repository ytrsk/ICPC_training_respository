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
int a[maxn];
long long gcd(long long x,long long y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        int m=n;long long sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]<0) m--;
            sum+=abs(a[i]);
        }
        printf("Case %d: ",++cnt);
        if(m==0) printf("inf");
        else{
            ll g=gcd(sum,m);
            sum/=g;m/=g;
            printf("%lld/%d",sum,m);
        }
        printf("\n");
    }
    return 0;
}
