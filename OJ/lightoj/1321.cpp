#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int e1,n,inq[maxn],head[maxn],to[maxn],nex[maxn];
double w[maxn],d[maxn];
void addedge(int u,int v,double x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
void spfa(){
    queue<int> q;q.push(1);
    for(int i=1;i<=n;i++) d[i]=0;d[1]=1;
    inq[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();inq[u]=0;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(d[v]<d[u]*w[i]){
                d[v]=d[u]*w[i];
                if(!inq[v]){
                    inq[v]=1;q.push(v);
                }
            }
        }
    }
    //cout<<d[n]<<endl;
}
void init(){
    e1=0;for(int i=1;i<=n;i++) head[i]=0;
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        n=read();int m=read();init();
        int x=read(),y=read();
        for(int i=1;i<=m;i++){
            int u=read(),v=read(),w=read();++u;++v;
            addedge(u,v,w/100.0);
            addedge(v,u,w/100.0);
        }
        spfa();
        double p=d[n];
        printf("Case %d: %.8f\n",++cnt,1LL*x*2*y/p);
    }
    return 0;
}
