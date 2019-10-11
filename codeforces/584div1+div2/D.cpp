#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int fa[maxn];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int vis[maxn];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        vis[u]=vis[v]=1;
        fa[find(u)]=find(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) ans++;
        if(fa[i]==i&&vis[i]) ans--;
    }
    cout<<m-ans;
    return 0;
}
