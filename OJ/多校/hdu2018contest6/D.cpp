#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct node{
    long long a,b;
    node(long long a,long long b):a(a),b(b){}
    bool operator < (node x) const{
        return b*x.a>a*x.b;
    }
};
map<node,int> aa;int top;
int H[maxn],L[maxn],R[maxn];ll W[maxn];
ll dp[605][605],you[605];int id[maxn];
bool cmp(int x,int y){
    return R[x]<R[y];
}
int zz[maxn];
int main(){
    int T=read();
    while(T--){
        int n=read();top=0;aa.clear();
        for(int i=1;i<=n;i++){
            H[i]=read(),L[i]=read(),R[i]=read(),W[i]=read();
            node a1(H[i],L[i]),a2(H[i],R[i]);
            if(aa.count(a1)) L[i]=aa[a1];
            else L[i]=aa[a1]=++top;
            if(aa.count(a2)) R[i]=aa[a2];
            else R[i]=aa[a2]=++top;
        }int xx=0;
        for(auto i:aa) zz[i.second]=++xx;
        memset(dp,127/3,sizeof(dp));
        dp[0][0]=0;
        memset(you,0,sizeof(you));
        for(int i=1;i<=n;i++){ 
            L[i]=zz[L[i]];R[i]=zz[R[i]];
            swap(L[i],R[i]);
            for(int k=L[i];k<=R[i];k++) you[k]=max(you[k],W[i]);
        }
        for(int i=1;i<=n;i++) id[i]=i;
        sort(id+1,id+n+1,cmp);
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<=R[id[n]];i++) ans=min(ans,dp[n][i]);
        cout<<ans<<"\n";
    }
    return 0;
}