#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
#define lowbit(x) (x)&(-(x))
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=300007;
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
vector<pii> g[maxn];
int n,q,a[maxn],ans[maxn],val[maxn],up;
int binary_lifting(int x){
    int pos=0,ans=up;
    for(int i=20;i>=0;i--){
        if(pos+(1<<i)<=n){
            if(ans+val[pos+(1<<i)]>=x){
                pos+=(1LL<<i);
                ans+=val[pos];
            }
        }
    }
    return pos;
}
int query(int x){
    int ans=0;
    for(int i=x;i;i-=lowbit(i)) ans+=val[i];
    return ans; 
}
void update(int x){
    if(x>n) return;
    for(int i=x;i<=n;i+=lowbit(i)) val[i]--; 
}
int main(){
    n=read(),q=read();
    rep(i,1,n) a[i]=read();
    rep(i,1,q){
        int x=read(),y=read();
        g[n-y].push_back(mp(x+1,i));
    }
    rep(i,1,n){
        if(i-a[i]>=0){
            int pos=min(binary_lifting(i-a[i]),i);
            up++;
            update(pos+1);
        }
        for(auto x:g[i]){
            ans[x.second]=up+query(x.first);
        }
    }
    rep(i,1,q) printf("%d\n",ans[i]);
    return 0;
}