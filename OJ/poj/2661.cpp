#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=1e9+7;
const double pi=acos(-1.0);
const double e=exp(1);
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
void del(int x,int y){
    x-=y;
    if(x<0) x+=mod;
}
int fac[maxn],inv[maxn];
int C(int a,int b){
    if(a<b) return 0;
    return 1LL*fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    int N;
    while(scanf("%d",&N)==1&&N){
        ll ed=1969,now=4;
        while(N>ed){
            ed+=10;now*=2;
        }
        int l=1,r=now,ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(log2(sqrt(2*pi*mid))+mid*log2(mid/e)<=now){
                ans=mid;l=mid+1;
            }
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}