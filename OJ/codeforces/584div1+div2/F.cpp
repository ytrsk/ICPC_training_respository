#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=2000007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int n,m,e1,head[maxn],nex[maxn],to[maxn],w[maxn];
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
void add(int u,int v,int x){
    int last=v;
    while(x>=10){
        ++n;addedge(n,last,x%10);last=n;x/=10;
    }
    addedge(u,last,x);
}
int vis[maxn],ans[maxn];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    n=read(),m=read();
    int pre=n;
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        add(u,v,i);
        add(v,u,i);
    }
    queue<vector<int>> q;q.push(vector<int>{1});
    while(!q.empty()){
        vector<int> now=q.front();q.pop();
        for(int k=0;k<=9;k++){
            vector<int> Nex;
            for(int z=0;z<now.size();z++){
                int u=now[z];
                for(int i=head[u];i;i=nex[i]){
                        int v=to[i];
                        if(w[i]==k&&!vis[v]){
                            vis[v]=1;
                            Nex.push_back(v);
                            ans[v]=(ans[u]*10LL+k)%mod;
                        }
                    }
                }
            if(Nex.size()) q.push(Nex);
        }
    }
    for(int i=2;i<=pre;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
