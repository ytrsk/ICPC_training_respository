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
int a[maxn];
int you[32];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        for(int k=30;~k;--k){
            if(a[i]>>k&1) you[k]++;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int k=30;~k;--k){
            if(a[i]>>k&1) ans+=1LL*you[k]*(1LL<<k);
        }
    }
    cout<<ans;
    return 0;
}