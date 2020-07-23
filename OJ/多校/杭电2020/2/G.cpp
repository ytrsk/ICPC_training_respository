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
vector<int> g[maxn];
int n,m,L[maxn],R[maxn];ll A[maxn],B[maxn];
int now;
ll ans=0;
int e1,head[maxn],to[maxn<<1],nex[maxn<<1];
ll a[maxn<<1],b[maxn<<1];
ll aa[maxn<<1],bb[maxn<<1];
void addedge(int u,int v,int pa,int pb){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
    aa[e1]=pa;bb[e1]=pb;
}
void dfs(int u,int fa){
    //cout<<u<<" "<<fa<<endl;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        if(aa[i]<bb[i]) now++;
        ans+=min(aa[i],bb[i]);
        dfs(v,u);
    }
}
int main(){
    int t=read();
    while(t--){
        n=read(),m=read();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            L[i]=u;R[i]=v;A[i]=read();B[i]=read();
        }
        ll l=-1e9,r=1e9;
        ll Ans=0;
        while(l<=r){
            ll mid=(l+r)>>1;e1=0;
            for(int i=1;i<=n;i++) head[i]=0;
            for(int i=1;i<n;i++) a[i]=A[i]-mid*B[i],b[i]=B[i];
            for(int i=1;i<n;i++){
                addedge(L[i],R[i],a[i],b[i]);
                addedge(R[i],L[i],a[i],b[i]);
            }
            ans=0;now=0;
            dfs(1,0);
            if(now>=m){
                Ans=ans+m*mid;r=mid-1;
            }
            else l=mid+1;
        }
        printf("%lld\n",Ans);
    }
    return 0;
}