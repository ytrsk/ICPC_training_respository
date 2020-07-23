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
vector<int> g[maxn];
int L[maxn],R[maxn],cl,id[maxn],d[maxn],pos[maxn<<2],pre[maxn<<2],ti[maxn<<2];
int CL=0;
int st[maxn][21],tag[maxn<<2];
void check(int o){
    pos[o]=ti[o]==CL?pos[o]:pre[o];
}
void pushup(int o){
    check(o<<1);check(o<<1|1);
    ti[o]=CL;pos[o]=d[pos[o<<1]]>d[pos[o<<1|1]]?pos[o<<1]:pos[o<<1|1];
}
void build(int o,int l,int r){
    if(l==r){
        pre[o]=pos[o]=id[l];return;
    }
    int mid=(l+r)>>1;
    build(o<<1,l,mid);build(o<<1|1,mid+1,r);    
    pushup(o);pre[o]=pos[o];
}
void modify(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        ti[o]=CL;pos[o]=0;return;
    }
    int mid=(l+r)>>1;
    if(ql<=mid&&qr>mid) modify(o<<1,l,mid,ql,mid),modify(o<<1|1,mid+1,r,mid+1,qr);
    else if(ql<=mid) modify(o<<1,l,mid,ql,qr);
    else modify(o<<1|1,mid+1,r,ql,qr);
    pushup(o);
}
int find(int u,int x){
    if(d[u]<=x) return 1;
    for(int i=0;i<=20;i++) if(x>>i&1) u=st[u][i];
    return u;
}
void dfs(int u,int fa){
    L[u]=++cl;id[cl]=u;d[u]=d[fa]+1;st[u][0]=fa;
    for(int i=1;i<=20;i++) st[u][i]=st[st[u][i-1]][i-1];
    for(auto v:g[u]){
        dfs(v,u);
    }
    R[u]=cl;
}
int ans[maxn];
int main(){
    int n;
    while(scanf("%d",&n)==1){
        cl=CL=0;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=2;i<=n;i++) g[read()].push_back(i);
        dfs(1,0);
        build(1,1,n);
        for(int i=1;i<=n;i++) ans[i]=inf;
        for(int i=1;i<=n;i++){
            ++CL;
            int cnt=0;
            check(1);
            while(pos[1]){
                int x=pos[1];
                x=find(x,i);
                modify(1,1,n,L[x],R[x]);
                ++cnt;
            }
            ans[cnt]=min(ans[cnt],i);
        }
        ans[0]=inf;ll sum=0;
        for(int i=1;i<n;i++) ans[i]=min(ans[i],ans[i-1]),sum+=ans[i];
        printf("%lld\n",sum);
    }
    return 0;
}