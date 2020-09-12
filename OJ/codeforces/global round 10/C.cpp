#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn<<1];
int main(){
    int t=read();
    while(t--){
        int n=read();
        ll ans=0;
        for(int i=1;i<=n;i++){
            a[i]=read();if(i-1) ans+=max(0,a[i-1]-a[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}