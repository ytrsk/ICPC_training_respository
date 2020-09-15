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
int mod=1e9+7;
int main(){
    int n=read(),ans=1,now=1;
    for(int i=1;i<=n;i++) ans=(1LL*ans*i)%mod;
    for(int i=1;i<n;i++) now=(now<<1)%mod;
    printf("%d\n",(ans-now+mod)%mod);
    return 0;
}