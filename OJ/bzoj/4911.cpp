#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=30007;
const int inf=0x3f3f3f3f;
typedef long long ll;
const int mod=10007;
inline int powm(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int inv2=powm(2,mod-2);
inline void fwt_xor(int *a,int n,int opt){
    for(register int i=1;i<n;i<<=1)
    for(register int k=0;k<n;k+=i<<1)
    for(register int j=k;j<i+k;++j)
    {
        int x=a[j],y=a[j+i];
        a[j]=(x+y)%mod;a[j+i]=(x-y+mod)%mod;
        if(opt==-1) a[j]=a[j]*inv2%mod,a[j+i]=a[j+i]*inv2%mod;
    }
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int R;
struct matrix{
    int a[128],b[128],c[128],d[128];
    matrix operator * (matrix x){
        matrix New;
        for(register int i=0;i<R;++i){
            New.a[i]=(a[i]+x.a[i]+b[i]*x.c[i])%mod;
            New.b[i]=(x.b[i]+b[i]*x.d[i])%mod;
            New.c[i]=(c[i]+d[i]*x.c[i])%mod;
            New.d[i]=d[i]*x.d[i]%mod;
        }
        return New;
    }
}g[maxn<<2];
int cl,n,dfn[maxn],f[maxn],d[maxn],sz[maxn],id[maxn];
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],tp[maxn];
int son[maxn],bt[maxn];
int G[maxn][128],F[maxn][128],val[maxn];
int Gans[maxn][128],Fans[maxn][128],tot[maxn][128];
int gans[maxn][128],fans[maxn][128];
inline void pushup(int o){
    g[o]=g[o<<1|1]*g[o<<1];
}
inline void build(int o,int l,int r){
    if(l==r){
        for(int i=0;i<R;i++){
            g[o].a[i]=Gans[id[l]][i];
            g[o].b[i]=g[o].c[i]=g[o].d[i]=tot[id[l]][i];
        }
        return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    pushup(o);
}
inline void modify(int o,int l,int r,int x){
    if(l==r){
        for(int i=0;i<R;i++){
            g[o].a[i]=Gans[id[l]][i];
            g[o].b[i]=g[o].c[i]=g[o].d[i]=tot[id[l]][i];
        }
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) modify(o<<1,l,m,x);
    else modify(o<<1|1,m+1,r,x);
    pushup(o);
}
matrix query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return g[o];
    }
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return query(o<<1|1,m+1,r,m+1,qr)*query(o<<1,l,m,ql,m);
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr);
}
int Fzero[maxn][128],Gzero[maxn][128];
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int tmp[128];
void Fcheck(int u){
    memset(tmp,0,sizeof(tmp));
    tmp[val[u]]=1;fwt_xor(tmp,R,1);
    for(int i=0;i<R;i++){
        tot[u][i]=tmp[i]*(Fzero[u][i]?0:F[u][i])%mod;
        tmp[i]=tot[u][i];
    }
    for(int i=0;i<R;i++){
        Fans[u][i]=(fans[u][i]+tot[u][i])%mod;
    }
    memcpy(tot[u],tmp,sizeof(tmp));
}
void Gcheck(int u){
    memset(tmp,0,sizeof(tmp));
    tmp[val[u]]=1;fwt_xor(tmp,R,1);
    for(int i=0;i<R;i++){
        tot[u][i]=tmp[i]*(Gzero[u][i]?0:G[u][i])%mod;
        tmp[i]=tot[u][i];
    }
    for(int i=0;i<R;i++){
        Gans[u][i]=(gans[u][i]+tot[u][i])%mod;
    }
    memcpy(tot[u],tmp,sizeof(tmp));
}
void dfs1(int u,int fa){
    f[u]=fa;
    sz[u]=1;son[u]=0;
    for(int i=0;i<R;i++) F[u][i]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        d[v]=d[u]+1;
        dfs1(v,u);
        for(int k=0;k<R;k++) (fans[u][k]+=Fans[v][k])%=mod;
        for(int k=0;k<R;k++) if(tot[v][k]+1!=mod) (F[u][k]*=(tot[v][k]+1))%=mod;else Fzero[u][k]++;
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]){
            son[u]=v;
        }
    }
    Fcheck(u);
}
void dfs2(int u,int t){
    for(int i=0;i<R;i++) G[u][i]=1;
    tp[u]=t;dfn[u]=++cl;id[cl]=u;
    if(!son[u]){
        Gcheck(u);
        bt[u]=u;return;
    }
    dfs2(son[u],t);bt[u]=bt[son[u]];
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==son[u]||v==f[u]) continue;       
        for(int k=0;k<R;k++) (gans[u][k]+=Fans[v][k])%=mod;
        for(int k=0;k<R;k++) if(tot[v][k]+1!=mod) (G[u][k]*=(tot[v][k]+1))%=mod;else Gzero[u][k]++;
        dfs2(v,v);
    }
    Gcheck(u);
}
matrix ask(int x){
    return query(1,1,n,dfn[x],dfn[bt[x]]);
}
void Update(int x,int y){
    val[x]=y;Gcheck(x);
    while(x){
        matrix last=ask(tp[x]);
        modify(1,1,n,dfn[x]);
        matrix now=ask(tp[x]);
        x=f[tp[x]];
        for(int i=0;i<R;i++){
            (gans[x][i]+=(now.a[i]-last.a[i]+mod))%=mod;
            if(last.b[i]+1==mod) Gzero[x][i]--;
            else (G[x][i]*=powm(last.b[i]+1,mod-2))%=mod;
            if(now.b[i]+1==mod) Gzero[x][i]++;
            else (G[x][i]*=(now.b[i]+1))%=mod;
        }
        Gcheck(x);
    }
}
void init(){
    for(int i=1;i<=n;i++) head[i]=0;
    e1=cl=0;
}
int main(){
    n=read();R=read();
    for(int i=1;i<=n;i++) val[i]=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs1(1,0);dfs2(1,1);
    build(1,1,n);int m=read();
    for(int i=1;i<=m;i++){
        char s[12];scanf("%s",s+1);
        if(s[1]=='C'){
            int x=read(),y=read();Update(x,y);
        }
        else{
            int x=read();
            matrix now=ask(1);
            fwt_xor(now.a,R,-1);
           printf("%d\n",now.a[x]);
        }
    }
    return 0;
}
