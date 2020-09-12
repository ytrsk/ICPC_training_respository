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
int a[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    long long ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=pow(1e14,1.0/n);i++){
        long long now=1,tot=0;
        for(int k=1;k<=n;k++){
            tot+=abs(a[k]-now);
            now*=i;
        }
        ans=min(ans,tot);
    }
    cout<<ans;
    return 0;
}