#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=500007;
const ll inf=1<<29;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll c[maxn],sum[maxn];
struct node{
    vector<int> s;
    bool operator < (node a) const{
        if(s.size()!=a.s.size()) return s.size()<a.s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]!=a.s[i]) return s[i]<a.s[i];
        }
        return false;
    }
}nd[maxn];
map<node,ll> aa;
int main(){
    int t=read();
    while(t--){
        int n=read(),m=read();
        ll x=0;
        for(int i=1;i<=n;i++){
            sum[i]=0;
            c[i]=read();
            nd[i].s.clear();
        }
        for(int i=1;i<=m;i++){
            int u=read(),v=read();
            sum[u]+=c[v];nd[v].s.push_back(u);
        }
        aa.clear();
        for(int i=1;i<=n;i++) sort(nd[i].s.begin(),nd[i].s.end()),aa[nd[i]]+=c[i];
        for(auto i:aa) if(i.first.s.size()>=1) x=gcd(x,i.second);
        printf("%lld\n",x);
    }
    return 0;
}