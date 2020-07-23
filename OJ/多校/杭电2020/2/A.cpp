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
int fa[maxn],a[maxn],id[maxn];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int cmp(int x,int y){
    return a[x]<a[y];
}
vector<int> g[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read(),m=read();
        for(int i=1;i<=n;i++) fa[i]=i,g[i].clear();
        for(int i=1;i<=n;i++) a[i]=read(),id[i]=i;
        sort(id+1,id+n+1,cmp);
        for(int i=1;i<=m;i++){
            int u=read(),v=read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ll ans=0;
        for(int i=n;i>=1;--i){
            int u=id[i];
            ans+=a[u];
            for(auto v:g[u]){
                int rt=find(v);
                if(find(u)!=rt&&a[rt]>=a[u]){
                    ans-=a[u];
                    fa[find(u)]=rt;    
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2
3 2
3 2 3
1 2
2 3
8 7
4 6 3 5 1 2 3 1
1 3
2 3
3 4
3 6
5 6
6 7
6 8
*/