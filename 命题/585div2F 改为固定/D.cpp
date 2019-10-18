#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=400007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int e1,head[maxn],to[maxn<<2],nex[maxn<<2],sz[maxn];
void addedge(int u,int v){
   // cout<<"edge "<<u<<" "<<v<<endl;
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
vector<int> g[400007],G[400007];
int you[400007];
int main(){
    int tot=0;
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n,p,M,m;cin>>n>>p>>M>>m;
    for(int i=1;i<=n;i++){
        int u=read(),v=read();
        addedge(u+p,v);
        addedge(v+p,u);
    }
    for(int i=1;i<=p;i++){
        int x=read(),y=read();
        g[x].push_back(i);
        G[y+1].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        addedge(u,v+p);
        addedge(v,u+p);
    }
    int SZ=0;
    for(int i=1;i<=p;i++){
        for(int k=head[i+p];k;k=nex[k]){
            int v=to[k];tot++;sz[v]++;
            printf("u %d %d\n",i+p,v);
        }
    }
    for(int i=1;i<=M;i++){
        for(int k=0;k<g[i].size();k++){
            int u=g[i][k];SZ+=sz[u];you[u]=1;SZ-=sz[u+p];
            for(int z=head[u];z;z=nex[z]){
                int v=to[z];
                tot++;sz[v]++;
                printf("u %d %d\n",u,v);
                if(!you[v-p]) SZ++;
            }
            for(int z=head[u+p];z;z=nex[z]){
                int v=to[z];
                tot--;sz[v]--;
                printf("d %d %d\n",u+p,v);
                if(you[v]) SZ--;
            }
        }
        printf("%d %d %d\n",i,tot,SZ);
        for(int k=0;k<G[i].size();k++){
            int u=G[i][k];SZ-=sz[u];you[u]=0;
            for(int z=head[u];z;z=nex[z]){
                int v=to[z];
                tot--;sz[v]--;
                if(!you[v-p]) SZ--;
            }
            SZ+=sz[u+p];
            for(int z=head[u+p];z;z=nex[z]){
                int v=to[z];
                tot++;sz[v]++;
                if(you[v]) SZ++;
            }
        }
        if(tot==SZ){
            int ans=0;
            for(int k=1;k<=p;k++){
                if(you[k]){
                    ans++;
                }
            }
            printf("%d %d\n",ans,i);
            for(int k=1;k<=p;k++){
                if(you[k]) printf("%d ",k);
            }
            return 0;
        }
    }
    printf("-1");
    return 0;
}
