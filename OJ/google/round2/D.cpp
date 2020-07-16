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
vector<int> g[maxn];
int d[maxn],w[maxn],head[maxn],to[maxn],nex[maxn],e1,a[maxn],b[maxn];
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
int main(){
    int T=read(),ee=0;
    while(T--){
        e1=0;
        int n=read(),m=read();
        rep(i,1,n) head[i]=0;
        rep(i,1,n) d[i]=-1;
        a[1]=0;
        rep(i,1,n-1) a[i+1]=-read();
        rep(i,1,m){ 
            int u=read(),v=read();
            addedge(u,v,i);addedge(v,u,i);
        }
        d[1]=0;
        int now=1,S=1;
        int x=1;
        int Mx=0;
        while(now<n){
            vector<int> g;
            for(int i=1;i<=n;i++){
                if(a[i]==S){
                    g.push_back(i);now++;
                }
            }
            int mx=0;
            for(auto x:g){
                for(int k=head[x];k;k=nex[k]){
                    int v=to[k];
                    if(a[v]<S){
                        mx=max(mx,Mx+1);
                    }
                }
            }
            for(auto x:g){
                d[x]=mx;
                for(int k=head[x];k;k=nex[k]){
                    int v=to[k];
                    if(a[v]<S){
                        b[w[k]]=d[x]-d[v];
                    }
                    else if(a[v]==S){
                        b[w[k]]=1000000;
                    }
                }
            }
            Mx=mx;
            S++;
        }
        printf("Case #%d: ",++ee);
        rep(i,1,m){
            printf("%d ",b[i]);
        }
        printf("\n");
    }
    return 0;
}