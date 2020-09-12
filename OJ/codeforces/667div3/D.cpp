#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[23],b[23];
int main(){
    int t=read();
    while(t--){
        int len=0;
        ll n=read();int s=read();ll x=n;
        int sum=0;
        while(x){
            a[++len]=x%10;sum+=a[len];
            x/=10;
        }
        a[len+1]=0;
        int now=0;
        if(sum<=s){printf("0\n");continue;}
        for(int i=1;i<=len;i++){
            now+=a[i];
            if(sum-now+1<=s){
                ll S=0;
                for(int k=1;k<=i;k++) b[k]=0;
                b[i+1]=a[i+1]+1;
                for(int k=i+2;k<=len+1;k++) b[k]=a[k];
                for(ll k=1,z=1;k<=len+1;k++,z*=10)  S+=b[k]*z;
                printf("%lld\n",S-n);
                break;
            }
        }
    }
    return 0;
}