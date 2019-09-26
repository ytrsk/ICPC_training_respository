#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
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
int a[1007];
int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;a[1]=1;
    for(int i=2;i<=n;i++) a[i]=(a[i-1]+a[i-2])%mod;
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int k=0;k<=i;k++) (ans+=1LL*a[k]*a[i-k]%mod)%=mod;
        cout<<i<<" "<<ans<<"\n";
        //if(ans==1) cout<<i<<endl;
    }
    return 0;
}
