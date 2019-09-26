#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=5000007;
const int N=5000000;
int e1,mu[maxn],p[maxn],sum1[maxn],phi[maxn];
ll sum2[maxn];
void pre(){
    phi[1]=mu[1]=1;
    for(int i=2;i<=N;i++){
        if(!phi[i]){
            p[++e1]=i;mu[i]=-1;phi[i]=i-1;
        }
        for(int k=1;k<=e1&&p[k]*i<=N;k++){
            if(i%p[k]==0){
                phi[i*p[k]]=phi[i]*p[k];break;
            }
            else mu[i*p[k]]=-mu[i],phi[i*p[k]]=phi[i]*phi[p[k]];
        }
    }
    for(int i=1;i<=N;i++) sum1[i]=sum1[i-1]+mu[i],sum2[i]=sum2[i-1]+phi[i];
}
int djs1(int x){
    if(x<=N) return sum1[x];
    if(a1.count(x)) return a1[x];
    int ans=1;
    for(int l=2,r;l<=x;l=r+1){
        r=x/(x/l);
        ans-=(r-l+1)*djs1(x/l);
    }
    return a1[x]=ans;
}
ll djs2(ll x){
    if(x<=N) return sum2[x];
    if(a2.count(x)) return a2[x];
    ll ans=x*(x+1)/2;
    for(ll l=2,r;l<=x;l=r+1){
        r=x/(x/l);
        ans-=(r-l+1)*djs2(x/l);
    }
    return a2[x]=ans;
}
int main(){
    int t;cin>>t;pre();
    while(t--){
        int n;scanf("%d",&n);
        printf("%lld %d\n",djs2(n),djs1(n));
    }
    return 0;
}
