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
int d[maxn],fa[maxn];
int rt,tmp1=1,vis[maxn];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int u,int f){
   
    int leaf=0;
    if(f==rt) leaf=rt;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v!=f){
            d[v]=d[u]^1;
            dfs(v,u);
            if(g[v].size()==1){   
                if(leaf) fa[find(v)]=find(leaf);
                leaf=v;
            }
        }
    }
    if(d[u]==1&&g[u].size()==1) tmp1=0;
}
int main(){
    int n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);
        g[v].push_back(u);  
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()==1) rt=i;
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    dfs(rt,0);
    if(tmp1) printf("1 ");
    else printf("3 ");
    int cnt=n-1;
    for(int i=1;i<=n;i++){
        if(find(i)!=i) cnt--;
    }
    cout<<cnt;
    return 0;
}