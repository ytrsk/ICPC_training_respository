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
int query(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int r;scanf("%d",&r);
    return r;
}
int a[maxn],b[maxn],du[maxn],vis[maxn];
int main(){
    int n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);g[v].push_back(u);
        du[u]++;du[v]++;
    }
    int top=0;
    for(int i=1;i<=n;i++) if(du[i]==1){
        a[++top]=i;
    }
    while(top>1){
        int x=a[top--],y=a[top--];
        int z=query(x,y);
        vis[x]=vis[y]=1;
        if(z==x||z==y){printf("! %d",z);return 0;}
        for(int i=0;i<g[x].size();i++){
            int v=g[x][i];du[v]--;
            if(!vis[v]&&du[v]==0) {printf("! %d",v);return 0;}
            else if(du[v]==1&&!vis[v]){
                a[++top]=v;
            }
        }
        for(int i=0;i<g[y].size();i++){
            int v=g[y][i];du[v]--;
            if(!vis[v]&&du[v]==0) {printf("! %d",v);return 0;}
            else if(du[v]==1&&!vis[v]){
                a[++top]=v;
            }
        }
    }
    printf("! %d",a[top]);
    return 0;
}