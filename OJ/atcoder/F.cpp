#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
vector<int> g[maxn];
int aa[maxn],pre[maxn];
int a[maxn];
int lowbit(int x){return  x&(-x);}
int ans[maxn];
map<int,int> aaa;
void dfs(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v^fa){
           ans[v]=1;
           queue<int> G;
           for(int i=a[v];i;i-=lowbit(i)) ans[v]=max(ans[v],aa[i]);
           int x=ans[v];aaa[ans[v]]++;
           for(int i=a[v]+1;i<=200000;i+=lowbit(i))
           G.push(aa[i]),aa[i]=max(aa[i],ans[v]+1); 
           for(int i=200000;i;i-=lowbit(i)) ans[v]=max(ans[v],aa[i]-1);
           dfs(v,u);    
           aaa[x]--;
           if(!aaa[x]) aaa.erase(x);        
           for(int i=a[v]+1;i<=200000;i+=lowbit(i))
           aa[i]=G.front(),G.pop();
        }
    }
}
int A[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) A[i]=read(),a[i]=A[i];
    sort(A+1,A+n+1);
    int len=unique(A+1,A+n+1)-A-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(A+1,A+len+1,a[i])-A;
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans[1]=1;
    for(int i=a[1]+1;i<=200000;i+=lowbit(i)) aa[i]=max(aa[i],ans[1]+1);
    aaa[1]++;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}