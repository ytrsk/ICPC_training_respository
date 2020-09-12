#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1200007;
const ll inf=0x3f3f3f3f3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll d[maxn];
int n,e1,head[maxn],to[maxn<<1],nex[maxn<<1],vis[maxn],w[maxn<<1];
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
inline void dijkstra(int s){
    for(int i=1;i<=n;++i) d[i]=inf,vis[i]=0;
    priority_queue<pair<ll,int>> q;d[s]=0;q.push(mp(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(d[v]>d[u]+w[i]){
                d[v]=d[u]+w[i];
                q.push(mp(-d[v],v));
            }
        }
    }
}
void init(){
    for(int i=1;i<=n;i++) head[i]=0;e1=0;
}
char S[maxn];
int id(int x,int y){
    return x*2-y;
}
int a[maxn];
int main(){
    int t=read();
    while(t--){
        int N=read(),m=read(),SS=read(),TT=read(),X=read();
        scanf("%s",S+1);
        n=2*N+2;init();
        int s=n-1,t=n;
        for(int i=1;i<=N;i++){
            a[i]=(S[i]=='L')?0:1;
            addedge(id(i,0),id(i,1),X);
            addedge(id(i,1),id(i,0),X);
        }
        for(int i=1;i<=m;i++){
            int u=read(),v=read(),x=read();
            for(int k=0;k<2;k++){
                for(int z=0;z<2;z++){
                    if(k!=z) continue;
                    if(z==a[v]||S[v]=='M'){
                        addedge(id(u,k),id(v,z),x);
                    }
                    if(z==a[u]||S[u]=='M'){
                        addedge(id(v,k),id(u,z),x);
                    }
                }
            }
        }
        for(int i=0;i<2;i++){
            if(i==a[SS]||S[SS]=='M') addedge(s,id(SS,i),0);
        }
        addedge(id(TT,0),t,0);
        addedge(id(TT,1),t,0);
        dijkstra(s);
        printf("%lld\n",d[t]);
    }
}