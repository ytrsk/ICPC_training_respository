#include<bits/stdc++.h>
using namespace std;
const int maxn=1600007;
typedef long long ll;
stack <int> s;
vector<int> g[maxn];
int clock1,num;
int read(){
    char ch=getchar();int x=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x;
}
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
void addedge(int u,int v){
    g[u].push_back(v);
}
int you[maxn];
int main(){
	int n=read(),p=read(),M=read(),m=read();
	for(int i=1;i<=n;i++){
        int u=read(),v=read();
        addedge(u+p,v);addedge(v+p,u);
	}
	for(int i=1;i<=p;i++){
        int u=read(),v=read();
        addedge(i,2*p+u);
        addedge(2*p+M+u,i+p);
        if(v<M) {
            addedge(i,2*p+M+v+1);
            addedge(2*p+v+1,i+p);
        }
	}
	for(int i=2;i<=M;i++){
        addedge(2*p+i,2*p+i-1);
        addedge(2*p+M+i-1,2*p+M+i);
	}
	addedge(2*p+M+1,2*p+1);
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        addedge(u,v+p);addedge(v,u+p);
	}
    for(int i=1;i<=2*p+2*M;i++) if(!dfn[i]) tarjan(i);
    int ok=1,x=0;
    for(int i=2*p+1;i<=2*p+M;i++){
       // cout<<"scc"<<scc[i]<<" "<<scc[i+M]<<endl;
        if(scc[i]<scc[i+M]) x=max(x,i-2*p);//cout<<33<<" "<<i-2*p<<endl;
        else if(scc[i]==scc[i+M]) ok=0;
     //   else cout<<i-2*p<<endl;
    }
    int cnt=0;
    for(int i=1;i<=p;i++){
        if(scc[i]<scc[i+p]) you[i]=1,++cnt;
        else if(scc[i]==scc[i+p]) ok=0;
    }
    if(!ok){
        printf("-1");
    }
    else{
        printf("%d %d\n",cnt,x);
        for(int i=1;i<=p;i++){
            if(you[i]) printf("%d ",i);
        }
    }
    return 0;
}
