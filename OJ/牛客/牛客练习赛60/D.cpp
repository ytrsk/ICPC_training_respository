#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef __int128 ll;
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;return;
    }
    exgcd(b,a%b,y,x);y-=x*(a/b);
}
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll X;
bool solve(ll x,ll y,ll z,ll opt){
    if(z%gcd(x,y)!=0) return false;
    ll a,b,g=gcd(x,y);
    exgcd(x,y,a,b);a*=z/g;
    ll s=y/g;
    ll now=(a%s+s)%s;
    if(z-now*x>=0){
        if(opt==1)  printf("%lld %lld %lld",(long long)now,(long long)((z-now*x)/y),0LL);
        else printf("%lld %lld %lld",(long long)X,(long long)now,(long long)((z-now*x)/y));
        return true;
    }
    return false;
}
int main(){
    ll a=read(),b=read(),c=read(),K=read();
        for(int i=0;i<=b;i++){
            X=i;
            if(solve(b,c,K-a*i,2)) return 0;
        }
    return 0;
}