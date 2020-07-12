#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],b[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        rep(i,0,n-1) b[i]=0,a[i]=read();
        int ok=1;
        rep(i,0,n-1){
            b[(i+a[i]%n+n)%n]=1;
        }
        rep(i,0,n-1){
            if(!b[i]) ok=0;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}