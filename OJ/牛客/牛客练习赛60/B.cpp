#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll a[maxn],b[maxn];
int main(){
    int n=read();ll ans=0;
    for(int i=1;i<=n;i++){
        a[i]=read();b[i]=read();
    }
    for(int i=1;i<=n;i++){
        for(int k=i+1;k<=n;k++){
            ans+=1LL*(n-2)*(abs(0LL+a[i]-a[k])+abs(0LL+b[i]-b[k]))%998244353;
            ans%=998244353;
        }
    }
    cout<<ans;
    return 0;
}