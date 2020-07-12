#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[1000007];
int val[1007];
int val2[1007],pre[1000007];
int id(int x,int y){
    return x*200+y+1;
}
ll d[maxn];
int n,e1,head[maxn],to[4000007],nex[4000007],vis[maxn],w[4000007],p,N;int L[107];
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
inline void dijkstra(){
    n=40000;
    for(int i=1;i<=n;++i) d[i]=inf,vis[i]=0;priority_queue<pair<ll,int>> q;
    for(int i=1;i<=N;i++){
        int now=id(val[i],val2[i]);
        d[now]=min(d[now],1LL*L[i]);q.push(mp(-d[now],now));
    }
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

int main(){
    N=read(),p=read();pre[0]=1;
    for(int i=1;i<=1000000;i++){
        pre[i]=(10LL*pre[i-1])%p;
    }
    for(int i=1;i<=N;i++){
        scanf("%s",s+1);
        int len=strlen(s+1);L[i]=len;
        for(int k=1;k<=len;k++){
            val[i]=(val[i]+pre[len-k]*(s[k]-'0'))%p;
        }
        val2[i]=pre[len];
    }
    for(int i=0;i<p;i++){
        for(int k=0;k<p;k++){
            for(int z=1;z<=N;z++){
                int x=(i+k*val[z])%p,y=(k*val2[z])%p;
                addedge(id(i,k),id(x,y),L[z]);
            }
        }
    }
    dijkstra();
    ll ans=inf;
    for(int i=0;i<200;i++) ans=min(d[id(0,i)],ans);
    cout<<(ans==inf?-1:ans);
    return 0;
}