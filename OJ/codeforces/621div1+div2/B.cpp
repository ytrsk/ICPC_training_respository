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
int a[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read(),x=read();
        for(int i=1;i<=n;i++) a[i]=read();sort(a+1,a+n+1);
        int ans=inf;
        for(int i=1;i<=n;i++) if(a[i]<=x) ans=min(ans,(x-1)/a[i]+1);else ans=min(ans,2);
        printf("%d\n",ans);
    }
    return 0;
}