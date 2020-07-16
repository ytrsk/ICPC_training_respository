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
int U[maxn],V[maxn];
void dfs(int u,int v){
    for(int i=0;i<g[u])
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=m;i++){
        U[i]=read(),V[i]=read();
    }
    
    int l=0,r=n;
    while(l<=r){
        int m=(l+r)>>1;
        for(int i=1;i<=n;i++)
    }
    return 0;
}