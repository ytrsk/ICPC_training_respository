#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int a[maxn],you[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    a[0]=a[n];a[n+1]=a[1];
    ll val=0,sum=0,rsum=0;
    for(int i=1;i<=n;i++){
        val+=a[i-1]*a[i];sum+=a[i];
    }
    for(int i=1;i<=n;i++){
        int x=read();
        if(x){
            ll y=sum-a[i-1]-a[i]-a[i+1]-rsum;
            if(i==n&&you[1])y+=a[1];
            if(you[i-1]) y+=a[i-1];
            val+=y*a[i];
            you[i]=1;
            rsum+=a[i];
        }
    }
    cout<<val;
    return 0;
}