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
map<int,int> aa[maxn],bb[maxn];
vector<int> g[maxn];
int ans[maxn];
int now=0,n,id=0,z;
void dfs(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v^fa){
            if(!aa[u].count(v)) aa[u][v]=aa[v][u]=ans[bb[u][v]]=now++;
        }
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v^fa){
            dfs(v,u);
        }
    }
}
int main(){
    n=read();z=n-2;
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);g[v].push_back(u);
        bb[u][v]=bb[v][u]=i;
    }
    if(n==2){
        printf("0");return 0;
    }
    int rt=1;
    for(int i=1;i<=n;i++){
        if(g[i].size()==1){
            aa[i][g[i][0]]=aa[g[i][0]][i]=1;
            ans[bb[i][g[i][0]]]=now++;
        }
    }
    dfs(rt,0);
    for(int i=1;i<n;i++) cout<<ans[i]<<"\n";
    return 0;
}