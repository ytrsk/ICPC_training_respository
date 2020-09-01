#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=998244353;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
const int len=600;
int pre[6000007];
int inv[6000007];
int main(){
    int t=read();
    pre[0]=0;pre[1]=1;
    inv[1]=1;
    //for(int i=2;i<=6000000;i++) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=6000000;i++){
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
        pre[i]=(pre[i-1]+1LL*inv[i]*inv[i]%mod)%mod;
    }
    while(t--){
        int n=read();
        printf("%lld\n",pre[n]*3LL%mod*pown(n,mod-2)%mod);
    }
    return 0;
}