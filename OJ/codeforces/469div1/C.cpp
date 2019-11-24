#include<bits/stdc++.h>
using namespace std;
const int maxn=200007;
typedef long long ll;
stack <int> s;
vector<int> g[maxn];
int clock1,num;
int scc[maxn],dfn[maxn],low[maxn],scnt;
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
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
void addedge(int u,int v){
    g[u].push_back(v);
}
int sz[maxn];
vector<int> G[maxn];
int in[maxn],a[maxn];
int main(){
	int n=read(),m=read(),h=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++){
        int u=read(),v=read();
        if((a[u]+1)%h==a[v]) addedge(u,v);
        if((a[v]+1)%h==a[u]) addedge(v,u);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) sz[scc[i]]++;
	for(int i=1;i<=n;i++)
    for(int k=0;k<g[i].size();k++){
        if(scc[i]!=scc[g[i][k]]) in[scc[i]]++;
    }
    int ans=2*n,pos=-1;
    for(int i=1;i<=scnt;i++)
    if(!in[i]){

        if(sz[i]<ans){
            ans=sz[i];pos=i;
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) if(scc[i]==pos) printf("%d ",i);
    return 0;
}
