#include <stdio.h>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
const int maxn=100007;
typedef long long ll;
stack <int> s;
vector <int> g[maxn];
int cl;
int scc[maxn],dfn[maxn],low[maxn],scnt;
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],sz[maxn];
void tarjan(int u){
    dfn[u]=low[u]=++cl;s.push(u);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(!scc[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        scnt++;int now;
        do{
            now=s.top();s.pop();
            scc[now]=scnt;sz[scnt]++;
        }while(!s.empty()&&now!=u);
    }
}
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int in[maxn],n,vis[maxn];
void init(){
    for(int i=1;i<=scnt;i++) head[i]=in[i]=sz[i]=vis[i]=0;
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=scc[i]=0;
    e1=cl=scnt=0;
}
bitset<1001> S[1003];
void dfs(int u){
    vis[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!vis[v]){
            dfs(v);
        }
        S[u]|=S[v];
    }
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    int t=read();
    while(t--){
        n=read();int m=read();init();
        for(int i=1;i<=m;i++){
            int u=read(),v=read();
            g[u].push_back(v);
        }
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
        for(int i=1;i<=n;i++)
        for(int k=0;k<g[i].size();i++){
            int v=g[i][k];
            if(scc[i]!=scc[v]){
                addedge(scc[i],scc[v]);in[scc[v]]++;
            }
        }
        for(int i=1;i<=scnt;i++) S[i].reset();
        for(int i=1;i<=scnt;i++){
            S[i].set(i);
        }
        for(int i=1;i<=scnt;i++){
            if(!vis[i]) dfs(i);
        }
        int ans=0;
        for(int i=1;i<=scnt;i++){
            ans+=S[i].count();
        }
        for(int i=)
        if(ans==scnt*(scnt-1)/2+scnt) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
