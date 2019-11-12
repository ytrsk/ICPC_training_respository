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
int n,m,x;
struct edge{
    int u,v,w,c;
    bool operator < (edge a) const{
        if(w!=a.w) return w<a.w;
        return c<a.c;
    }
}e[maxn];
int ans,fa[maxn];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool check(int c){
    int tot=0;ans=0;
    for(int i=1;i<=m;i++) if(!e[i].c) e[i].w-=c;
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        if(find(u)!=find(v)){
            fa[find(u)]=find(v);
            if(!e[i].c) tot++;
            ans+=e[i].w;
        }
    }

    for(int i=1;i<=m;i++) if(!e[i].c) e[i].w+=c;
    return tot>=x;
}
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    n=read(),m=read(),x=read();
    for(int i=1;i<=m;i++){
        e[i].u=read();e[i].v=read();e[i].w=read();e[i].c=read();
        e[i].u++;e[i].v++;
    }
    int l=-100,r=100,now=-1;
    while(l<=r){
        int m=(l+r)>>1;
        if(check(m)) r=m-1,now=ans+x*m;
        else l=m+1;
    }
    printf("%d",now);
    return 0;
}
