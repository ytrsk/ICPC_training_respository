#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define lowbit(x) (x)&(-(x))
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],v[maxn];
void add(int x,int y){
    for(int i=x;i<=100000;i+=lowbit(i)) v[i]+=y;
}
int query(int x){
    int ans=0;
    for(int i=x;i;i-=lowbit(i)) ans+=v[i];
    return ans;
}
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
bitset<30001> bit;
int ha[maxn],cl,L[maxn],R[maxn],pre[maxn],ans[maxn],a[maxn];
void dfs(int u,int fa){
    add(a[u],1);
    L[u]=++cl;pre[cl]=u;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
    }
    R[u]=cl;
    ans[u]=query(a[u]-1);
    add(a[u],-1);
}
vector<pii> g[maxn],G[maxn];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read(),ha[i]=a[i];
    sort(ha+1,ha+n+1);int len=unique(ha+1,ha+n+1)-ha-1;
    for(int i=1;i<=len;i++) a[i]=lower_bound(ha+1,ha+n+1,a[i])-ha;
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        G[L[i]-1].push_back(make_pair(a[i]-1,i));
        g[R[i]].push_back(make_pair(a[i]-1,i));
    }
    for(int i=1;i<=n;i++){
        add(a[pre[i]],1);
        for(int k=0;k<g[i].size();k++) ans[g[i][k].second]+=query(g[i][k].first);
        for(int k=0;k<G[i].size();k++) ans[G[i][k].second]-=query(G[i][k].first);
    }
    bit[0]=1;
    for(int i=1;i<=n;i++){
    //    cout<<ans[i]<<endl;
        bit|=(bit<<ans[i]);
    }
    int t=read();
    while(t--){
        int x=read();
        if(bit[x]) printf("Orz\n");
        else printf("QAQ\n");
    }
    return 0;
}
