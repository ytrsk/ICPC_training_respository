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
unordered_map<int,int> ha;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int now[100007],pre[100007],a[100007];
int c(int a,int b){
    return 1LL*pre[a]*pown(pre[b],mod-2)%mod*pown(pre[a-b],mod-2)%mod;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    int n=read(),b=read();
    for(int i=1;i<=n;i++) a[i]=read(),ha[a[i]]++;
    int x=1;pre[0]=1;
    for(int i=1;i<=n;i++){
        now[i]=(now[i-1]+x)%mod;
        x=(1LL*x*b)%mod;
    }
    for(int i=1;i<=n;i++) pre[i]=(1LL*pre[i-1]*now[i])%mod;
    int last=0,ans=1;
    for(auto i:ha){
        ans=(1LL*ans*c(last+i.second,i.second))%mod;
        last+=i.second;
    }
    cout<<ans;
    return 0;
}
