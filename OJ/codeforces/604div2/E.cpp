#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
const int inf=(1LL<<29);
const int mod=998244353;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int p[maxn],now[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) p[i]=read(),p[i]=1LL*p[i]*pown(100,mod-2)%mod;
    now[n]=(mod+1-p[n])%mod;
    ll tot=now[n],ans=1;
    for(int i=n-1;i>=1;i--){
        tot=(1LL*p[i]*tot+mod+1-p[i])%mod;
        ans=(1LL*p[i]*ans+1)%mod;
    }
    cout<<(1LL*ans*pown((mod+1-tot)%mod,mod-2))%mod;
    return 0;
}