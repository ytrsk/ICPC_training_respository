#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
vector<pii> g[maxn],G[maxn];
int id(int x,int y){
    return x*10+y;
}
int pre[107][maxn],ban[107],bl[107][107];
pii q[maxn];
int ans=0,K;
void dfs(int o){
    if(o==K+1){
        ans++;return;
    }
    for(int i=1;i<=o;i++){
        int now=id(o,i);
        if(!ban[now]){
            vector<int> p(101);
            for(int k=1;k<=100;k++) if(bl[now][k]){
                p[k]=ban[k];ban[k]=1;
            }
            dfs(o+1);
            for(int k=1;k<=100;k++) if(bl[now][k]){
                ban[k]=p[k];
            }
        }
    }
}
int main(){
    int n=read(),m=read();K=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),x=read();
        g[u].push_back(mp(x,v));
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
        int rk=0;
        for(auto x:g[i]){
            ++rk;
            int now=id(g[i].size(),rk);
            if(pre[now][x.second]) ban[now]=1;
            pre[now][x.second]=i;
        }
    }
    for(int i=1;i<=n;i++){
        int top=0;
        for(int k=1;k<=100;k++){
            if(pre[k][i]){
                q[++top]=mp(k,pre[k][i]);
            }
        }
        sort(q+1,q+top+1);
        for(int k=1;k<=top;k++){
            for(int z=k+1;z<=top;z++){
                if(q[z].second!=q[k].second){
                    bl[q[k].first][q[z].first]=1;
                }
            }
        }
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}