#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=998244353;
int p[maxn],a[maxn],vis[maxn];
int main(){
    int n=read(),m=read();ll sum=0;
    for(int i=1;i<=n;i++) p[i]=read(),a[i]=p[i];
    for(int i=n-m+1;i<=n;i++) sum+=i;
    int tot=1,last=-1;
    for(int i=1;i<=n;i++){
        if(p[i]>=n-m+1){
            if(~last) tot=(1LL*tot*(i-last))%mod;
            last=i;
        }
    }
    cout<<sum<<" "<<tot;
    return 0;
}