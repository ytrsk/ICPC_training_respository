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
vector<int> g[maxn],G[maxn];
int sz[maxn],tag;
vector<int> sol;
int col[maxn];
int DFS(int u,int fa){
    sz[u]=1;
    vector<int> now;int ok=0;
    for(auto v:g[u]){
        if(v==fa) continue;
        int x=DFS(v,u),z=x%tag;
        if(x<0){
            ok=1;break;
        }
        sz[u]+=sz[v];
    }   
     if(ok){return -1;}
    for(auto v:g[u]){
        if(v==fa) continue;
        int z=sz[v]%tag;
        col[z]++;
        if(col[z]==1) now.push_back(z);
    }
    for(auto c:now) {
        if(c==0) continue;
        if(col[c]){
            if(2*c==tag) {if(col[c]&1) ok++;continue;}
            int x=min(col[c],col[tag-c]);
            col[tag-c]-=x;col[c]-=x;
            if(col[c]) ok++;
        }
    }
    for(int i=0;i<now.size();i++) col[now[i]]=0;
    return ok<=1?sz[u]%tag:-1;
}
int ans[maxn];
int main(){
    int n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if((n-1)%i==0) sol.push_back(i);
    }
    for(int i=0;i<sol.size();i++){
        tag=sol[i];if(~DFS(1,0)) ans[tag]=1;
    }
    for(int i=1;i<=n;i++) printf("%d",ans[i]);
    return 0;
}
/*
13
1 2
2 3
2 4
4 5
2 6
6 7
6 8
6 9
9 10
8 11
11 12
12 13
*/