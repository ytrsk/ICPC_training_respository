#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct edge{
    int v;
    ll x;
};
vector<edge> g[maxn];
ll a[maxn],w[maxn];
ll nd[maxn];
struct node{
    ll pre,x;
    node(ll pre,ll x):pre(pre),x(x){
    }
    bool operator < (node a) const{
        return pre<a.pre;
    }
};
void dfs(int u,int fa,ll x){
    w[u]=a[u]+x;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(v==fa) continue;
        dfs(v,u,-g[u][i].x*2);
        w[u]+=w[v];
    }
}
void Dfs(int u,int fa,ll x){
    vector<node> q1,q2;
    for(auto v:g[u]){
        if(v.v==fa) continue;
        Dfs(v.v,u,v.x);
    }
    for(auto v:g[u]){
        if(v.v==fa) continue;
        if(w[v.v]>=0) q1.push_back(node{nd[v.v],w[v.v]});
        else q2.push_back(node{nd[v.v]+w[v.v],-w[v.v]});
    }
    sort(q1.begin(),q1.end());
    sort(q2.begin(),q2.end());
    ll now=0;nd[u]=x;
    now+=a[u];
    for(auto x:q1){
        if(now<x.pre) nd[u]+=x.pre-now,now=x.pre;
        now+=x.x;
    }
    for(auto x:q2){
        now-=x.x;
    }
    if(now<0) nd[u]+=(-now),now=0;
    for(auto x:q2){
        if(now<x.pre) nd[u]+=x.pre-now,now=x.pre;
        now+=x.x;
    }
   // cout<<u<<" "<<nd[u]<<"asd"<<now<<endl;
}
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        for(int i=1;i<n;i++){
            int u=read(),v=read(),x=read();
            g[u].push_back(edge{v,x});
            g[v].push_back(edge{u,x});
        }
        dfs(1,0,0);
        Dfs(1,0,0);
        printf("%lld\n",nd[1]);
    }
    return 0;
}