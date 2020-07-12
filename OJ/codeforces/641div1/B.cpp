#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
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
int a[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read(),K=read();
        rep(i,1,n) a[i]=read();
        int ok=0;
        int sum1=0;
        map<int,int> aa0,aa1;
        int OK=1;
        rep(i,1,n) if(a[i]^K) OK=0;
 
        rep(i,1,n){
            int now=0;
            if(a[i]<=K) now=1;
            sum1+=now;
            if(a[i]==K){
                if(i%2==1){
                    if(aa0[1-(-i/2+sum1)]||aa1[-(-i/2+sum1)]) ok=1;
                }
                else{
                    if(aa0[-(-i/2+sum1)]||aa1[1-1-(-i/2+sum1)]) ok=1;
                }
            }
            if((i-1)%2==0) aa0[-(sum1-now)+(i-1)/2]=1;
            else aa1[-(sum1-now)+(i-1)/2]=1;
        }
        reverse(a+1,a+n+1);
        sum1=0;
        aa0.clear();aa1.clear();
        rep(i,1,n){
            int now=0;
            if(a[i]<=K) now=1;
            sum1+=now;
            if(a[i]==K){
                if(i%2==1){
                    if(aa0[1-(-i/2+sum1)]||aa1[-(-i/2+sum1)]) ok=1;
                }
                else{
                    if(aa0[-(-i/2+sum1)]||aa1[1-1-(-i/2+sum1)]) ok=1;
                }
            }
            if((i-1)%2==0) aa0[-(sum1-now)+(i-1)/2]=1;
            else aa1[-(sum1-now)+(i-1)/2]=1;
        } 
        if(ok||OK) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}