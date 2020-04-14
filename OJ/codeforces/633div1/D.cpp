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
int dp[maxn][2];
vector<int> g[maxn];
void dfs(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v^fa){
            dfs(v,u);
            
        }
    }
}
int main(){
    int n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);g[v].push_back(u);
    }
    dfs(1,0);
    return 0;
}