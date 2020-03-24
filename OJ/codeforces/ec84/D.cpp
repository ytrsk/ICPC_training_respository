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
int c[maxn],p[maxn],vis[maxn];
vector<int> g[maxn];
vector<int> y[maxn];
int yan[maxn];
int main(){
    for(int i=1;i<=200000;i++)
    for(int k=i;k<=200000;k+=i)
    y[k].push_back(i);
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) p[i]=read(),vis[i]=0;
        for(int i=1;i<=n;i++) c[i]=read();
        int now=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int x=i;++now;g[now].clear();
                while(!vis[x]){
                    g[now].push_back(x);
                    vis[x]=1;x=p[x];
                }
            }
        }
        int ans=n+100;
        for(int i=1;i<=now;i++){
            for(int k=0;k<y[g[i].size()].size();k++){
                int x=y[g[i].size()][k];for(int k=0;k<x;k++) yan[k]=0;
                int ok=0;
                for(int z=0;z<g[i].size();z++){
                    int col=c[g[i][z]];
                    if(yan[z%x]==0) yan[z%x]=col;
                    else if(yan[z%x]!=col) yan[z%x]=-1;
                }
                for(int k=0;k<x;k++){
                    if(~yan[k]) ok=1;
                }
                if(ok) ans=min(ans,x);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}