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
int p[maxn],a[maxn],dp[1007][1007];
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
//下标从1开始
int pown(int a,int b){
    if(b<0) return pown(pown(a,-b),mod-2);
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int mul(int a,int b){
    return 1LL*a*b%mod;
}
int Y[maxn],coe[maxn],n,X[maxn];
void init(){
    for(int i=1;i<=n;i++){
        for(int k=0;k<=i;k++) dp[i][k]=((k?dp[i-1][k-1]:0)+mul(dp[i-1][k],mod-X[i]))%mod;
    }
    for(int i=1;i<=n;i++){
        int inv=1;
        for(int k=1;k<=n;k++){
            if(k!=i) inv=mul(inv,mod+X[i]-X[k]);
        }
        inv=pown(inv,mod-2);
        int last=0,tmp=pown(mod-X[i],mod-2);
        for(int k=0;k<n;k++){
            last=mul((dp[n][k]-last+mod)%mod,tmp);
            add(coe[k],mul(last,mul(Y[i],inv)));
        }
    }
}
int main(){
    int d=read(),nn=read(),N=1;
    for(int i=1;i<=nn;i++){
        p[i]=read(),a[i]=read();N=mul(N,pown(p[i],a[i]));
    }
    dp[0][0]=1;int now=0;n=d+2;
    for(int i=1;i<=n;i++){
        X[i]=i;add(now,pown(i,d));Y[i]=now;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int tmp=mul(pown(N,i),coe[i]);
        for(int k=1;k<=nn;k++){
            tmp=mul(tmp,1+mod-pown(p[k],d-i));
        }
        add(ans,tmp);
    }
    cout<<ans;
    return 0;
}
