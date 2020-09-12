#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int mu[maxn],phi[maxn],sum[maxn];
int len,p[maxn];
const int mod=1e9+7;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int add(int a,int b){
    return a+b>=mod?a+b-mod:a+b;
}
int dec(int a,int b){
    return a-b<mod?a-b+mod:a-b;
}
int mul(int a,int b){
    return 1LL*a*b%mod;
}
int pre[maxn],f[maxn];
int main(){
    int t=read(),K=read(),X=read();
    mu[1]=1;phi[1]=1;
    for(int i=2;i<=200000;i++){
        if(!phi[i]) p[++len]=i,mu[i]=-1,phi[i]=i-1;
        for(int k=1;k<=len&&i*p[k]<=200000;k++){
            if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=mu[i]*mu[p[k]];
            else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=0;break;}
        }
    }
    for(int i=1;i<=200000;i++) mu[i]=(mu[i]+mod)%mod;
    for(int i=1;i<=200000;i++){
        for(int k=i;k<=200000;k+=i){
            int x=k/i;
            f[k]=add(f[k],mul(mul(mu[i],pown(i,1LL*K*X%(mod-1))),mul(pown(x,(1LL*K*X+1)%(mod-1)),mul(mu[x],mu[x]))));
        }
    }
    for(int i=1;i<=200000;i++) sum[i]=add(sum[i-1],f[i]);
    for(int i=1;i<=200000;i++) pre[i]=add(pre[i-1],pown(i,K));
    while(t--){
        int n=read(),ans=0;
        for(int l=1,r;l<=n;l=r+1){
            r=n/(n/l);
            ans=add(ans,mul(pown(pre[n/l],X),dec(sum[r],sum[l-1])));
        }
        printf("%d\n",ans);
    }
    return 0;
}