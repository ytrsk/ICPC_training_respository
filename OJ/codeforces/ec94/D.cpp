#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=3007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],pre[maxn][maxn];
int q(int l,int r,int x){
    return pre[r][x]-pre[l-1][x];
}
int main(){
    int t=read();
    while(t--){
        int n=read();    
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++)
            pre[i][k]=pre[i-1][k];
            pre[i][a[i]]++;
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll now=0;
            for(int k=i+1;k<=n;k++){
                if(k-i>=2) now+=q(k+1,n,a[k-1]),now-=q(i+1,k-2,a[k]);
                if(a[i]==a[k]){
                    ans+=now;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}