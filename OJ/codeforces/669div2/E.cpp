#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=500007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
vector<int> g[maxn][2];
int b[maxn],w[maxn],dp[maxn];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        g[v][read()].push_back(u);
    }
    queue<int> q;
    q.push(n);
    dp[n]=0;
    fill(b+1,b+n+1,n);
    fill(w+1,w+n+1,n);
    w[n]=b[n]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:g[u][0]){
            if(b[v]>dp[u]+1){
                b[v]=dp[u]+1;
                dp[v]=max(b[v],w[v]);
                if(dp[v]<n) q.push(v);
            }
        }
        for(auto v:g[u][1]){
            if(w[v]>dp[u]+1){
                w[v]=dp[u]+1;
                dp[v]=max(b[v],w[v]);
                if(dp[v]<n) q.push(v);
            }
        }
    }
        printf("%d\n",max(w[1],b[1])==n?-1:max(w[1],b[1]));
        for(int i=1;i<=n;i++){
            printf("%d",w[i]<b[i]?0:1);
        }
    return 0;
}