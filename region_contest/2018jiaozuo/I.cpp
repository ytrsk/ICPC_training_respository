#include <bits/stdc++.h>
#define mp make_pair
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
long long sum[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        a[1]=0;
        for(int i=2;i<=n;i++) a[i]=a[i-1]+read();
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        if(n==1){
            printf("0\n");continue;
        }
        printf("%d %d%c",0,a[n]-a[1],n==2?'\n':' ');ll lastl=-a[1],lastr=a[n],last=a[n]-a[1];
        for(int i=3;i<=n;i++){
            if(i%2){
                printf("%lld%c",last+sum[n]-sum[n-i/2]-sum[i/2],i==n?'\n':' ');
            }
            else{
                lastl=lastl-2*sum[i/2-1]+1LL*(2*i/2-1-i)*a[i/2];
                lastr=lastr+2*(sum[n]-sum[n-(i/2-1)])+a[n-(i/2)+1];
                last=lastl+lastr;
                printf("%lld%c",last,i==n?'\n':' ');
            }
        }
    }
    return 0;
}
