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
int del(int x,int y){
    return (x-y+mod)%mod;
}
int inv[maxn],fac[maxn];
int C(int a,int b){
    if(a<b) return 0;
    return mul(fac[a],mul(inv[b],inv[a-b]));
}
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int s[maxn];
int dp[54][54],K;
int solve(ll x){
    if(x==0) return 0;
    int N=1,ans=0;
    for(int i=0;i<=K;i++){
        if(x+1-(i+1)+1>=0) N=mul(N,(x+1-(i+1)+1)%mod);
        ans=add(ans,mul(dp[K][i],mul(N,pown(i+1,mod-2))));
    }
    return ans;
}
ll you[100];
int main(){
    fac[0]=inv[0]=1;
    for(int i=1;i<=56;i++) fac[i]=1LL*fac[i-1]*i%mod;
    inv[56]=pown(fac[56],mod-2);
    for(int i=55;i;i--) inv[i]=mul(inv[i+1],i+1);
    dp[0][0]=1;
    for(int i=1;i<=51;i++){
        for(int k=1;k<=51;k++){
            dp[i][k]=(dp[i-1][k-1]+1LL*k*dp[i-1][k])%mod;
        }
    }
    int t=read();
    while(t--){
        ll n=read();int m=read();
        int last=0,ans=0;
        for(int i=1;i<=m;i++){
            you[i]=read();
        }
        sort(you+1,you+m+1);
        for(int i=1;i<=m;i++){
            if(you[i]>n){
                m=i-1;break;
            }
        }
        you[m+1]=n+1;
        K=0;
        for(int i=m+1;i>=1;i--){
            if(you[i]-you[i-1]-1){
                K=i;break;
            }
        }
        you[m+1]=n+1;
        for(int i=0;i<=m;i++){
            for(int k=i+1;k<=m+1;k++){
                ans=add(ans,del(solve(you[k]-you[i]-1),solve(you[k-1]-you[i])));
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
