#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=4000007;
const ll inf=0x3f3f3f3f3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll d[maxn];
int N,e1,head[maxn],to[maxn<<1],nex[maxn<<1],vis[maxn],w[maxn<<1];
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
inline void dijkstra(int s){
    for(int i=1;i<=N;++i) d[i]=inf,vis[i]=0;
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
int n,m;
int id(int a,int b){
    if(a==0||a==n) return n*n+1;
    else if(b==0||b==n) return n*n+2;
    return (a-1)*n+b;
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        int l=read(),r=read();
        char s[4];scanf("%s",s+1);
        int x=read();
        if(s[1]=='L'){
            addedge(id(l,r-1),id(l,r),x),addedge(id(l,r),id(l,r-1),x);
        }
        else{
            addedge(id(l-1,r-1),id(l,r-1),x),addedge(id(l,r-1),id(l-1,r-1),x);
        }
    }
    N=n*m+2;
    dijkstra(n*n+1);
    printf("%lld",d[n*n+2]==inf?-1:d[n*n+2]);
    return 0;
}