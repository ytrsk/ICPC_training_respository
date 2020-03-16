#include <bits/stdc++.h>
using namespace std;
const int maxn=100007;
typedef long long ll;
vector<int> g[maxn];
int n,cl,dfn[maxn],low[maxn];;
int e1,head[maxn<<1],to[maxn<<2],nex[maxn<<2];
int dcnt=0;
inline void Addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
inline void Add(int u,int v){
    Addedge(u,v);Addedge(v,u);
}
int S[maxn],Top;
void tarjan(int u,int fa){
    dfn[u]=low[u]=++cl;S[++Top]=u;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                dcnt++;int x;
                Add(n+dcnt,u);
                do{x=S[Top--],Add(n+dcnt,x);} while(x!=v);
            }
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);
    }
}
const int mod=1e9+7;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int fac[maxn],inv[maxn],fac2[maxn];
void init(){
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=0;
    dcnt=cl=e1=Top=0;
    for(int i=1;i<=2*n;i++) head[i]=0;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int q[maxn],top,sz[maxn],ans,pre[maxn];
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
void del(int &x,int y){
    x-=y;
    if(x<0) x+=mod;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
int dp[207][207],sum[207][207],tot[207][207];
void dfs(int u,int fa){
    sz[u]=(u<=n);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa){
            dfs(v,u);sz[u]+=sz[v];
        }
    }
    if(u>n){
        top=0;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(v^fa) q[++top]=v;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=top;i++){
            for(int k=0;k<=top+1;k++)
            for(int z=0;z<=top+1;z++)
            dp[k][z]=sum[k][z]=tot[k][z]=0;
            dp[i][0]=sum[i][0]=tot[i][0]=fac2[sz[q[i]]]-1;
            for(int k=1;k<=top;k++) tot[i][k]=tot[i][0];
        //    add(ans,mul(mul(min(i,top-i+1),fac2[n-sz[u]]-1),dp[i][0]));
            for(int k=i+1;k<=top+1;k++){
                for(int z=1;z<=top;z++){                        
                    if(k-z>=i) add(dp[k][z],tot[k-z][z]),add(dp[k][z],sum[k-1][z]),del(dp[k][z],sum[k-z][z]); 
                    else add(dp[k][z],sum[k-1][z]);
                    if(k!=top+1){
                        dp[k][z]=mul(dp[k][z],fac2[sz[q[k]]]-1);
                        sum[k][z]=(sum[k-1][z]+dp[k][z])%mod;
                        tot[k][z]=(tot[k][z-1]+dp[k][z])%mod;
                        int mx=max(z,top+1-(k-i));
                        mx=top+2-mx;
                      
                        add(ans,mul(dp[k][z],mx));
                    }
                    else{
                        dp[k][z]=mul(dp[k][z],fac2[n-sz[u]]-1);
                        int mx=max(z,max(i,top+1-k));
                        mx=top+1-mx;  //cout<<k<<" "<<z<<" "<<mx<<" "<<dp[k][z]<<endl;
                        add(ans,mul(mx,dp[k][z]));    
                    }
                }
            }
        }
    }
    else{
        top=0;int now=0;
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
            if(v^fa) del(ans,fac2[sz[v]]-1);
        }
        add(ans,fac2[sz[u]-1]);
        add(ans,fac2[sz[u]-1]-1);
    }
}
int main(){
    fac[0]=inv[0]=fac2[0]=1;
    for(int i=1;i<=100000;i++) fac2[i]=2LL*fac2[i-1]%mod;
    for(int i=1;i<=100000;i++){
        fac[i]=1LL*fac[i]*i%mod;
        inv[i]=pown(fac[i],mod-2);
    }
	n=read();init();int m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        g[u].push_back(v);g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    dfs(1,0);
    cout<<1LL*(ans+mod-fac2[n]+1)*pown(fac2[n],mod-2)%mod;
    return 0;
}
