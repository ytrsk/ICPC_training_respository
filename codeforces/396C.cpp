#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#define mp make_pair
#define pii pair<int,int>
#define lowbit(x) (x)&(-(x))
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=300007;
const int mod=1e9+7;
const int inf=(1LL<<29);
ll read(){
    ll x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],d[maxn];
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int cl,L[maxn],R[maxn];
void dfs(int u){
    L[u]=++cl;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        d[v]=d[u]+1;dfs(v);
    }
    R[u]=cl;
}
int v1[maxn],v2[maxn],n;
void add(int &x,int y){
    (x+=y)%=mod;
}
void add1(int o,int x){
    for(int i=o;i<=n;i+=lowbit(i)) add(v1[i],x);
}
void add2(int o,int x){
    for(int i=o;i<=n;i+=lowbit(i)) add(v2[i],x);
}
int query1(int o){
    int ans=0;
    for(int i=o;i;i-=lowbit(i)) add(ans,v1[i]);
    return ans;
}
int query2(int o){
    int ans=0;
    for(int i=o;i;i-=lowbit(i)) add(ans,v2[i]);
    return ans;
}
int main(){
    //freopen("test.in","r",stdin);
    n=read();for(int i=2;i<=n;i++) {
        int x=read();addedge(x,i);
    }
    dfs(1);
    int m=read();
    for(int i=1;i<=m;i++){
        int opt=read();
        if(opt==2){
            int u=read();
            printf("%d\n",(query1(L[u])+1LL*query2(L[u])*d[u])%mod);
        }
        else{
            int u=read(),x=read(),y=read();
            int A=(x+1LL*d[u]*y)%mod,B=mod-y;
            add1(L[u],A);add1(R[u]+1,mod-A);
            add2(L[u],B);add2(R[u]+1,mod-B);
        }
    }
    return 0;
}
