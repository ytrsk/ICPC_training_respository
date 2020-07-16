#include <bits/stdc++.h>
#define make_pair mp
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1<<18;
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
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int ans[200007];
int a[21][maxn];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x=read();a[1][x]++;
    }
    inv2=powm(2,mod-2);
    fwt_xor(a[1],1<<18,1);
    for(int k=2;k<20;k++)
    for(int i=0;i<(1<<18);i++){
        a[k][i]=(1LL*a[k-1][i]*a[1][i])%mod;
    }
    for(int i=1;i<20;i++) fwt_xor(a[i],1<<18,-1);
    for(int i=1;i<=n;i++){
        if(i<20){
            int x=0;
            for(int k=0;k<(1<<18);k++){
                if(a[i][k]) x=max(x,k);
            }
            ans[i]=x;
        }
        else ans[i]=ans[i-2];
        printf("%d ",ans[i]);
    }
    return 0;
}