#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=998244353;
struct cn{
    int x,y,w;
    cn operator * (cn a){
        cn ans;
        ans.x=(1LL*x*a.x%mod+1LL*y*a.y%mod*w%mod)%mod;
        ans.y=(1LL*x*a.y%mod+1LL*y*a.x%mod)%mod;
        ans.w=w;
        return ans;
    }
    int operator ^ (int b){
        cn ans,x=*this;ans.x=1;ans.y=0;ans.w=w;
        while(b){
            if(b&1) ans=ans*x;
            x=x*x;
            b>>=1;
        }
        //cout<<ans.x<<" "<<ans.y<<endl;
        return ans.x;
    }
};
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int sqrt_mod(int n){
    if(n==0) return 0;
    if(pown(n,(mod-1)/2)==mod-1) return -1;
    int a,w;
    while(1){
        a=rand()%mod;
        w=(1LL*a*a-n+mod)%mod;
        if(pown(w,(mod-1)/2)==mod-1) break;
    }
    cn x;x.x=a;x.y=1;x.w=w;
    return x^((mod+1)/2);
}
int main(){
    printf("%d\n",sqrt_mod(5));
    return 0;
}
