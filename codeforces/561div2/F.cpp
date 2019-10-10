#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
map<pii,int> aa;
int fa[maxn];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
unordered_map<int,int> a[maxn];
void merge(int x,int y){
    fa[x]=y;
    for(auto i:a[x]) a[y][i.first]=1;
}
void addedge(int u,int v,int x){
    if(aa.count(mp(v,x))) merge(find(u),find(aa[mp(v,x)]));
    if(aa.count(mp(u,x))) merge(find(v),find(aa[mp(u,x)]));
    aa[mp(v,x)]=u;
    aa[mp(u,x)]=v;
}
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n=read(),m=read(),c=read(),q=read();
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),x=read();
        addedge(u,v,x);a[find(u)][v]=a[find(v)][u]=1;
    }
    for(int i=1;i<=q;i++){
        char ss[10];scanf("%s",ss+1);
        if(ss[1]=='?'){
            int u=read(),v=read();
            if(a[find(u)].count(v)||find(u)==find(v)) printf("Yes\n");
            else printf("No\n");
        }
        else{
            int u=read(),v=read(),x=read();
            addedge(u,v,x);
            a[find(u)][v]=a[find(v)][u]=1;
        }
    }
    return 0;
}
