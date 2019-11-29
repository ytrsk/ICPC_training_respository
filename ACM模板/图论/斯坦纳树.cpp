#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int inq[maxn],head[maxn],to[maxn<<1],nex[maxn<<1],w[maxn<<1];
int d[1<<10][507];queue<int> q;
int tag[maxn],e1;
void spfa(int S){
    while(!q.empty()){
        int u=q.front();q.pop();inq[u]=0;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(d[S][v]>d[S][u]+w[i]){
                d[S][v]=d[S][u]+w[i];
                if(!inq[v]){
                    inq[v]=1;q.push(v);
                }
            }
        }
    }
}
int n,K;
void init(){
    e1=0;for(int i=1;i<=n;i++) head[i]=0;
    for(int i=0;i<(1<<K);i++)
    for(int k=1;k<=n;k++)
    d[i][k]=inf;
}
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
//复杂度为3^n*n+2^n*n*m
int main(){
    int T=read();
    while(T--){
        n=read();int m=read();int r=read();K=0;
        for(int i=1;i<=n;i++){
            if(i<=r||i>=n-r+1) tag[i]=K++;
            else tag[i]=-1;
        }
        init();
        for(int i=1;i<=m;i++){
            int u=read(),v=read(),x=read();
            addedge(u,v,x);addedge(v,u,x);
        }
        for(int i=1;i<=n;i++) if(~tag[i]) d[1<<tag[i]][i]=0;
        for(int i=1;i<(1<<K);i++){
            for(int k=(i-1)&i;k;k=(k-1)&i){
                for(int z=1;z<=n;z++)
                d[i][z]=min(d[i][z],d[k][z]+d[i^k][z]);
            }
            for(int k=1;k<=n;k++){
                if(d[i][k]!=inf&&!inq[k]) q.push(k),inq[k]=1;
            }
            spfa(i);
        }
    }    
    return 0;
}