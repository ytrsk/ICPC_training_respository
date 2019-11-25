#include <stdio.h>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100007;
typedef long long ll;
stack <int> s;
vector <int> g[maxn];
int cl;
int scc[maxn],dfn[maxn],low[maxn],scnt;
int e1,head[maxn],to[maxn<<1],next1[maxn<<1],sz[maxn];
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
    ++e1;next1[e1]=head[u];head[u]=e1;to[e1]=v;
}
int in[maxn],n;
void init(){
    for(int i=1;i<=scnt;i++) head[i]=in[i]=sz[i]=0;
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=scc[i]=0;
    e1=cl=scnt=0;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int out[maxn];
int fa[maxn];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	n=read();init();
	for(int i=1;i<=n;i++){
        int x=read();
        while(x){
            g[i].push_back(x);
            x=read();
        }
	}
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++){
        for(int k=0;k<g[i].size();k++)
        if(scc[g[i][k]]!=scc[i]) addedge(scc[i],scc[g[i][k]]),in[scc[g[i][k]]]++,out[scc[i]]++;
    }
    int ans=0,you=0,tot=0;
    for(int i=1;i<=scnt;i++){
        fa[i]=i;
        if(!in[i]) you++;
        if(!out[i]) tot++;
    }
    for(int i=1;i<=scnt;i++)
        for(int k=0;k<g[i].size();k++)
        fa[find(i)]=find(g[i][k]);
    int num=0;
    for(int i=1;i<=scnt;i++){
        if(fa[i]==i){
            num++;
        }
    }
    if(num==1) printf("1\n0");
    else printf("%d\n%d",you,max(you,tot));
    return 0;
}
