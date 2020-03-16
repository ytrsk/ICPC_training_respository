#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <complex>
using namespace std;
typedef long long ll;
const int maxn=200007;
const int mod=1e9+7;
ll pown(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int add(int x,int y){
    return (x+y)%mod;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
int inv[maxn],fac[maxn];
int C(int a,int b){
    if(a<b) return 0;
    return mul(fac[a],mul(inv[b],inv[a-b]));
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn];
int main(){
    fac[0]=inv[0]=1;
    int n=read(),K=read();
    int tota=0;
    for(int i=1;i<=n;i++){
        a[i]=read();tota=add(tota,a[i]);
    }
    for(int i=1;i<=K;i++) fac[i]=1LL*fac[i-1]*i%mod;
    inv[K]=pown(fac[K],mod-2);
    for(int i=K-1;i;i--) inv[i]=mul(inv[i+1],i+1);
    int ans=0;
    if(n==1){
        if(K==1) printf("%d",tota);
        else printf("0");
        return 0;
    }
    for(int i=0;i<=K-1;i++){
        int x=pown(mod-1,i);
        x=mul(x,mul(inv[i],inv[K-1-i]));
        int y=K-1-i;
        int r=(mul(n,pown(y+1,n-1))-mul(mul(n-1,y),pown(y+1,n-2))+mod)%mod;
        r=mul(r,x);
        ans=add(r,ans);
    }
    ans=mul(ans,tota);
    cout<<ans;
	return 0;
}
