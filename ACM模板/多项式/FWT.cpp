#include <bits/stdc++.h>
#define make_pair mp
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=100007;
int inv2;
int powm(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
void fwt_or(int *a,int n,int opt)
{
    for(int i=1;i<n;i<<=1)
    for(int k=0;k<n;k+=i<<1)
    for(int j=k;j<k+i;++j)
    if(opt==1)a[j+i]=(a[j]+a[j+i])%mod;
    else a[j+i]=(a[j+i]-a[j]+mod)%mod;
}
void fwt_and(int *a,int n,int opt)
{
    for(int i=1;i<n;i<<=1)
    for(int k=0;k<n;k+=i<<1)
    for(int j=k;j<i+k;++j)
    if(opt==1)a[j]=(a[j]+a[j+i])%mod;
    else a[j]=(a[j]-a[j+i]+mod)%mod;
}
void fwt_xor(int *a,int n,int opt)
{
    for(int i=1;i<n;i<<=1)
    for(int k=0;k<n;k+=i<<1)
    for(int j=k;j<i+k;++j)
    {
        int x=a[j],y=a[j+i];
        a[j]=(x+y)%mod;a[j+i]=(x-y+mod)%mod;
        if(opt==-1) a[j]=1LL*a[j]*inv2%mod,a[j+i]=1LL*a[j+i]*inv2%mod;
    }
}
int main(){
    int n;cin>>n;
    inv2=powm(2,mod-2);
    return 0;
}
