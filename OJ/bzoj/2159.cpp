#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <complex>
using namespace std;
typedef long long ll;
const int maxn=50007;
const int mod=10007;
int dp1[maxn][151],dp2[maxn][151],K;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}

int add(int x,int y){
    return (x+y)%mod;
}
int mul(int x,int y){
    return x*y%mod;
}
int s[157][157];
inline void tran(int *fi,int *ed){
    ed[0]=fi[0];
    for(register int i=1;i<=K;++i) ed[i]=(i*fi[i-1]+fi[i])%mod;
}
int inv[maxn],fac[maxn];
int C(int a,int b){
    if(a<b) return 0;
    return mul(fac[a],mul(inv[b],inv[a-b]));
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int head[maxn],to[maxn<<1],nex[maxn<<1],e1;
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int tmp[157];
void dfs(int u,int fa){
    dp1[u][0]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa){
            dfs(v,u);
            tran(dp1[v],dp2[v]);
            for(int k=0;k<=K;k++) dp1[u][k]=add(dp1[u][k],dp2[v][k]);
        }
    }
}
int U[maxn],V[maxn],n;
void Uncompress() { int N, k, L, i, now, A, B, Q, tmp; scanf("%d%d%d", &N, &k, &L); scanf("%d%d%d%d", &now, &A, &B, &Q);  n=N, K=k; for (i = 1; i < N; i ++) { now = (now * A + B) % Q; tmp = (i < L) ? i : L; U[i]=i - now % tmp,V[i]= i + 1; } } 
int ans[maxn][151];
void DFS(int u,int fa){
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa){
            for(register int k=0;k<=K;k++){
                tmp[k]=(ans[u][k]-dp2[v][k]+mod)%mod;
            }
            tran(tmp,ans[v]);
            for(register int k=0;k<=K;k++) ans[v][k]=add(ans[v][k],dp1[v][k]);
            DFS(v,u);
        }
    }
}
int main(){
    fac[0]=inv[0]=1;Uncompress();
    int N=300;
    s[0][0]=1;
    for(int i=1;i<=K;i++)
    for(int k=1;k<=i;k++){
        s[i][k]=(s[i-1][k-1]+1LL*k*s[i-1][k])%mod;
    }
    for(int i=1;i<=N;i++) fac[i]=1LL*fac[i-1]*i%mod;
    inv[N]=pown(fac[N],mod-2);
    for(int i=N-1;i;i--) inv[i]=mul(inv[i+1],i+1);
    for(int i=1;i<n;i++){
        addedge(U[i],V[i]);addedge(V[i],U[i]);
    }
    dfs(1,0);for(int i=0;i<=K;i++) ans[1][i]=dp1[1][i];DFS(1,0);
    for(int i=1;i<=n;i++){
        int Ans=0;
        for(int k=0;k<=K;k++) Ans=add(Ans,mul(s[K][k],ans[i][k]));
        printf("%d\n",Ans);
    }
	return 0;
}
