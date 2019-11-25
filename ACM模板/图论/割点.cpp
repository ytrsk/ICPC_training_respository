#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100007;
typedef long long ll;
vector<int> g[maxn];
int n,cl,dfn[maxn],low[maxn],cut[maxn];
void tarjan(int u,int fa){
    int rc=0;
    dfn[u]=low[u]=++cl;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!dfn[v]){
            rc++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]) cut[u]=1;
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);
    }
    if(!fa&&rc==1) cut[u]=0;
}
void init(){
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=cut[i]=0;
    cl=0;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
	n=read();init():
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    int num=0;
    for(int i=1;i<=n;i++){
        if(cut[i]) num++;
    }
    printf("%d\n",num);
    return 0;
}
