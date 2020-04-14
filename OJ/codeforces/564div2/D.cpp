#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int pre[maxn],inv[maxn];
const int mod=998244353;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
vector<int> g[maxn];
int now=1;
int mul(int a,int b){
    return 1LL*a*b%mod;
}
int add(int a,int b){
    return (a+b)%mod;
}
void dfs(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v^fa){
            now=mul(now,pre[g[v].size()]);
            dfs(v,u);
        }
    }
}
int ans=0;
void Dfs(int u,int fa){
    ans=add(ans,now);int x=now;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v^fa){
            now=mul(mul(x,inv[g[u].size()+1]),g[v].size()+1);
         //   Dfs(v,u);
        }
    }
}
int main(){
    int n=read();
    pre[0]=1;for(int i=1;i<=n;i++) pre[i]=(1LL*pre[i-1]*i)%mod;
    for(int i=1;i<=n;i++) inv[i]=pown(i,mod-2);
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);g[v].push_back(u);
    }
    now=mul(now,pre[g[1].size()]);
    dfs(1,0);
    now=mul(now,n);
    printf("%d\n",now);
    return 0;
}