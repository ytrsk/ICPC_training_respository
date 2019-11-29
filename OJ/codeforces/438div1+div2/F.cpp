#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
struct node{
    ll x,y;
    node operator + (node a){
        return node{(x+a.x)%mod,(y+a.y)%mod};
    }
    node operator - (node a){
        return node{(x-a.x+mod)%mod,(y-a.y)%mod};
    }
    node operator * (node a){
        return node{x*a.x%mod,(x*a.y+y)%mod};
    }
    void print(){
        cout<<x<<" "<<y<<"\n";
    }
};
node pownode(node a,ll b){
    node ans=node{1,0};
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
node e{1,0},zero{0,0};
ll gcd(ll a,ll b){
    return !b?a:gcd(b,a%b);
}
ll pown(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) (ans*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return ans;
}
ll inv2=pown(2,mod-2);
ll inv(ll x){
    return pown(x,mod-2);
}
node inv(node a){
    ll x=a.x,y=a.y;
    return node{inv(x),(mod-y*inv(x)%mod)%mod};
}
node G(node x,node a,ll b){
    if(b==0) return node{0,0};
    if(a.x==1) return node{b*x.x%mod,(b*(b+1)/2%mod*a.y%mod*x.x%mod+b*x.y%mod)%mod};
    ll z=(pown(a.x,b+1)-a.x+mod)%mod*pown(a.x-1+mod,mod-2)%mod;
    return node{x.x*z%mod,(a.y*x.x%mod*(z-b+mod)%mod*pown(a.x-1,mod-2)%mod+x.y*b%mod)%mod};
}
ll calc(ll n,ll k,node A,node B,node s1,node s2){
    if(k==0){
        node z=A-e;
        return (s2.x*(mod-z.y*pown(z.x,mod-2)%mod)%mod+s2.y)%mod;
    }
    node A1=inv(A),B1=inv(B);
    node nA=pownode(A1,n/k-1)*B1,nB=pownode(A1,n/k)*B1;
    node ns1=s1+G(s2,A,n/k);
    node ns2=s1+G(s2,A,n/k-1);
    return calc(k,n%k,nA,nB,ns1,ns2);
}
int main(){
 //   cin.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;
    while(n--){
        ll a,b;cin>>a>>b;ll g=gcd(a,b);a/=g;b/=g;
        cout<<calc(a,b,node{1,1},node{inv2,1},node{1,0},node{1,0})*pown(a,mod-2)%mod<<"\n";
    }
    return 0;
}
