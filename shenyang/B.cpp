#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int mod=1e9+7;
const int inf=(1LL<<29);
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
int a[100007];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n,t=read();ll m;
    while(t--){
        n=read();scanf("%lld",&m);
        int tot=0,sum=0;
        for(int i=1;i<=2*n;i++){
            a[i]=read();
            (sum+=a[i])%=mod;
            if(i>n){
                (tot+=a[i])%=mod;
            }
        }
      //  cout<<tot<<endl;
        tot=1LL*tot*pown(n,mod-2)%mod;
        if(m<=2*n){
            int tot=0;
            for(int i=1;i<=m;i++){
                (tot+=a[i])%mod;
            }
            printf("%d\n",tot);
        }
        else{
            int now=1LL*(m-2*n)%mod*tot%mod;
            (now+=sum)%=mod;
            printf("%d\n",now);
        }
    }
    return 0;
}
