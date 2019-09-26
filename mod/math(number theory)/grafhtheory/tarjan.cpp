#include<bits/stdc++.h>
using namespace std;
const int maxn=100007;
typedef long long ll;
stack <int> s;
vector<int> g[maxn];
int clock1,num;
int scc[maxn],dfn[maxn],low[maxn],scnt;
int e1,head[maxn],to[maxn<<1],next1[maxn<<1];
void tarjan(int u){
    dfn[u]=low[u]=++clock1;s.push(u);
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
            scc[now]=scnt;
        }while(!s.empty()&&now!=u);
    }
}
void addedge(int u,int v){
    ++e1;next1[e1]=head[u];head[u]=e1;to[e1]=v;
}
int in[maxn],n;
void init(){
    while(!s.empty()) s.pop();
    for(int i=1;i<=scnt;i++) sz[i]=head[i]=in[i]=0,gg[i].clear();
    for(int i=1;i<=n;i++) dfn[i]=low[i]=scc[i]=0,g[i].clear();
    e1=0;clock1=0;scnt=0;
    ans.clear();
}
int main(){
	int m;cin>>n>>m;
	for(int i=1;i<=n;i++){
    	int x;scanf("%d",&x);g[i].push_back(x);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++){
        for(int k=0;k<g[i].size();k++)
        if(scc[g[i][k]]!=scc[i]) addedge(scc[i],scc[g[i][k]]),in[scc[i]]++;
    }
    return 0;
}
