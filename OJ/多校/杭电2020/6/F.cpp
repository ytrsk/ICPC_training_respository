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
int a[maxn];
int e1,head[maxn],to[maxn<<1],nex[maxn<<1];
int fa[maxn],sz[maxn];
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
void merge(int u,int v){
    
}
int main(){
    int t=read();
    while(t--){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        merge(u,v);
    }
    }
    return 0;
}