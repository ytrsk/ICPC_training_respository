#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int w[maxn<<1],e1,head[maxn],to[maxn<<1],nex[maxn<<1],dfn[maxn],cl,d[maxn],st[maxn][21],n;
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;;
}
int lca(int u,int v){
	if(d[u]<d[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(d[st[u][i]]>=d[v]) u=st[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--) if(st[u][i]^st[v][i]) u=st[u][i],v=st[v][i];
	return st[u][0];
}
void dfs(int u,int fa){
	st[u][0]=fa;d[u]=d[fa]+1;dfn[u]=++cl;
	for(int i=1;i<=20;i++) st[u][i]=st[st[u][i-1]][i-1];
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v!=fa) dfs(v,u);
	}
}
vector<int> g[maxn];
map<string,int> aa;int id;
void Init(){
    cl=e1=id=0;aa.clear();
    for(int i=1;i<=n;i++){
        head[i]=0;g[i].clear();
    }
}
bool cmp(int x,int y){
    return dfn[x]<dfn[y];
}
int dis(int x,int y){
    return d[x]+d[y]-2*d[lca(x,y)]; 
}
int disl[maxn],disr[maxn],D[maxn];
int main(){
    int q;
    while(scanf("%d%d",&n,&q)==2){
        Init();
        for(int i=1;i<=n;i++){
            string s;cin>>s;
            if(!aa.count(s)) aa[s]=++id;
            g[aa[s]].push_back(i);
        }
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            addedge(u,v);addedge(v,u);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++){
            if(g[i].size()==1){
                disl[i]=disr[i]=g[i][0];
            }
            else if(g[i].size()>1){
                disl[i]=g[i][0];disr[i]=g[i][1];D[i]=dis(g[i][0],g[i][1]);
                for(int k=2;k<g[i].size();k++){
                    int v=g[i][k];
                    int d1=dis(disl[i],v),d2=dis(disr[i],v);
                    if(d1>=d2&&d1>=D[i]) D[i]=d1,disr[i]=v;
                    else if(d2>=d1&&d2>=D[i]) D[i]=d2,disl[i]=v;
                }
            }
        }
        for(int i=1;i<=q;i++){
            string s1,s2;cin>>s1;cin>>s2;
            if(!aa.count(s1)||!aa.count(s2)){
                printf("-1\n");
            }
            else{
                int u=aa[s1],v=aa[s2];
                printf("%d\n",1+max(max(dis(disl[u],disl[v]),dis(disl[u],disr[v])),max(dis(disr[u],disl[v]),dis(disr[u],disr[v]))));
            }
        }
    }
    return 0;
}