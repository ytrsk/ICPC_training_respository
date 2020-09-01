#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn =800007;
int ans;
int n,m,q,tot;
vector<pii> g[maxn<<2];
int fa[maxn],sz[maxn],sa[maxn];
inline int find(int x){
   return fa[x]==x?x:find(fa[x]);
}
inline void merge(int x,int y){
    if(x==y) return;
    tot-=(sz[x]==1&&sa[x]==1);
    tot-=(sz[y]==1&&sa[y]==1);
    ans-=(sa[x]&&sa[y]);
    if(sz[x]<sz[y]) fa[x]=y,sz[y]+=sz[x],sa[y]+=sa[x];
    else fa[y]=x,sz[x]+=sz[y],sa[x]+=sa[y];
}
int Ans[maxn];
struct node{
    int fx,sx,fy,sy,x,y,sax,say,tot,ans;
};
inline void build(int o,int l,int r){
    vector<node> s;
    for(int i=0;i<g[o].size();i++){
        int x=find(g[o][i].first),y=find(g[o][i].second);
        s.push_back(node{fa[x],sz[x],fa[y],sz[y],x,y,sa[x],sa[y],tot,ans});
        merge(x,y);
    }
    if(l==r){
        if(tot!=0){
            Ans[l]=-1;
        }
        else{
            Ans[l]=ans;
        }
        for(int i=g[o].size()-1;i>=0;i--){
            int x=s[i].x,y=s[i].y;
            fa[x]=s[i].fx;
            sz[x]=s[i].sx;
            fa[y]=s[i].fy;
            sz[y]=s[i].sy;
            sa[x]=s[i].sax;
            sa[y]=s[i].say;
            tot=s[i].tot;
            ans=s[i].ans;
        }
        return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);build(o<<1|1,m+1,r);
    for(int i=g[o].size()-1;i>=0;i--){
        int x=s[i].x,y=s[i].y;
        fa[x]=s[i].fx;
        sz[x]=s[i].sx;
        fa[y]=s[i].fy;
        sz[y]=s[i].sy;
        sa[x]=s[i].sax;
        sa[y]=s[i].say;
        tot=s[i].tot;
        ans=s[i].ans;
    }
}
inline void update(int o,int l,int r,int ql,int qr,int x,int y){
    if(l==ql&&r==qr){
        g[o].push_back(mp(x,y));
        return;
    }
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m,x,y),update(o<<1|1,m+1,r,m+1,qr,x,y);
    else if(ql<=m) update(o<<1,l,m,ql,qr,x,y);
    else update(o<<1|1,m+1,r,ql,qr,x,y);
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
map<int,int> aa[maxn];
int main(){
    n=read(),m=read(),q=read();tot=ans=m;  
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1,sa[i]=0;
    for(int i=n+1;i<=n+m;i++) fa[i]=i,sz[i]=1,sa[i]=1;
    for(int i=1;i<=n;i++){
        int x=read();
        while(x--){
            int y=read();
            aa[y][i]=1;
        }
    }
    for(int i=1;i<=q;i++){
        int u=read(),v=read();
        if(aa[u].count(v)){
            if(i>=2)
            update(1,1,q,aa[u][v],i-1,n+u,v);
            aa[u].erase(v);
        }
        else aa[u][v]=i;
    }
    for(int i=1;i<=m;i++){
        for(auto v:aa[i]) update(1,1,q,v.second,q,n+i,v.first);
    }
    build(1,1,q);
    for(int i=1;i<=q;i++){
        printf("%d\n",Ans[i]);
    }
    return 0;
}