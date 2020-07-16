#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=300007;
const int inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],dfn[maxn],cl,d[maxn],st[maxn][21];
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int sz[maxn],num[maxn][21];
int lca(int u,int v){
	if(d[u]<d[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(d[st[u][i]]>=d[v]) u=st[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--) if(st[u][i]^st[v][i]) u=st[u][i],v=st[v][i];
	return st[u][0];
}
void dfs(int u,int fa){
	st[u][0]=fa;d[u]=d[fa]+1;dfn[u]=++cl;sz[u]=1;
	for(int i=1;i<=20;i++) st[u][i]=st[st[u][i-1]][i-1];
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v^fa) dfs(v,u),sz[u]+=sz[v];
	}
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa) num[v][0]=sz[u]-sz[v];
    }
}
int s[maxn],top;
vector<int> g[maxn];
int mm[maxn];
void Addedge(int u,int v){
    g[u].push_back(v);
}
void init(int x){
    g[x].clear();
}
void ins(int u){
    init(u);
    if(top==1) {if(u>1) s[++top]=u;}
    else{
        int x=lca(u,s[top]);
        if(x!=s[top]){
            while(top>1&&dfn[s[top-1]]>=dfn[x]) Addedge(s[top-1],s[top]),top--;
            if(x!=s[top]) init(x),Addedge(x,s[top]),s[top]=x;
        }
        s[++top]=u;
    }
}
int you[maxn];
pii dp[maxn];pii lr[maxn];
pii kfather(int x,int y){
    int ans=0;
    for(int i=20;~i;i--) if(y>>i&1) ans+=num[x][i],x=st[x][i];
    return mp(ans,x);
}
void DFS(int u){
    vector<pii> pre;pre.resize(g[u].size());    
    if(you[u]) dp[u]=mp(d[u],u);
    else dp[u]=mp(inf,inf);
    int pos=0;pii mn=mp(inf,inf);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];DFS(v);dp[u]=min(dp[u],dp[v]);
        pre[pos++]=mn;mn=min(mn,dp[v]);
    }
    mn={inf,inf};
    for(int i=g[u].size()-1;i>=0;--i){
        int v=g[u][i];lr[v]=min(mn,pre[--pos]);
        mn=min(mn,dp[v]);
    }
}
void DP(int u,pii x){
    if(you[u]) x=mp(0,u);
    int TOT=sz[u];
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        pii z=kfather(v,d[v]-d[u]-1);
        TOT-=sz[z.second];
        pii up=min(x,mp(lr[v].first-d[u],lr[v].second));
        pii down=mp(dp[v].first-d[v],dp[v].second);
        DP(v,mp(up.first+d[v]-d[u],up.second));        
        up.first+=1;
        int tl=d[v]-d[u];
        if(up.first<1e8||down.first<1e8){
            if(tl==1){
                continue;
            }
            if(up.first+tl-1<down.first) mm[up.second]+=kfather(v,tl-1).first;
            else if(down.first+tl-1<up.first) mm[down.second]+=kfather(v,tl-1).first;
            else{
                int X=down.first-up.first+tl+1;
                if(X%2==0){
                    X/=2;      
                    if(X==tl){
                        mm[up.second]+=kfather(v,tl-1).first;
                        continue;
                    }
                    if(up.second<down.second){
                        pii now=kfather(v,tl-X-1);
                        mm[down.second]+=now.first;
                        mm[up.second]+=kfather(now.second,X).first;
                    }
                    else{
                        pii now=kfather(v,tl-X);
                        mm[down.second]+=now.first;
                        mm[up.second]+=kfather(now.second,X-1).first;
                    }
                }
                else{
                    X/=2;
                    pii now=kfather(v,tl-X-1);
                    mm[up.second]+=kfather(now.second,X).first;mm[down.second]+=now.first;
                }
            }
        }
    }
    pii zz=min(x,mp(dp[u].first-d[u],dp[u].second));
    if(zz.second<1e8) mm[zz.second]+=TOT;
}
bool cmp(int x,int y){
    return dfn[x]<dfn[y];
}
int a[maxn],b[maxn];
int main(){
    int n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs(1,0);
    for(int k=1;k<=20;k++)
    for(int i=2;i<=n;i++){
        num[i][k]=num[st[i][k-1]][k-1]+num[i][k-1];
    }
    int q=read();
    while(q--){
        int tot=read();s[top=1]=1;init(1);
        for(int i=1;i<=tot;i++){
            a[i]=read();you[a[i]]=1;mm[a[i]]=0;b[i]=a[i];
        }
        sort(a+1,a+tot+1,cmp);
        for(int i=1;i<=tot;i++) ins(a[i]);
        while(top>1) Addedge(s[top-1],s[top]),top--;
        DFS(1);DP(1,mp(inf,inf));
        for(int i=1;i<=tot;i++){
            printf("%d ",mm[b[i]]);
        }
        printf("\n");
        for(int i=1;i<=tot;i++) you[a[i]]=0;
    }
    return 0;
}