#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int e[57],a[57],b[57],c[57],d[57],n,K;
int A,B,C,D;
vector<int> g[57];
int top,q[maxn];
ll ans=0;
inline void dfs(int o){
    if(o==top+1){
        ans=max(ans,1LL*A*B*C*D);return;
    }
    for(auto x:g[q[o]]){
        A+=a[x];B+=b[x];C+=c[x];D+=d[x];
        dfs(o+1);
        A-=a[x];B-=b[x];C-=c[x];D-=d[x];
    }
}
int main(){
    int t=read();
    while(t--){
        n=read(),K=read();
        ans=0;
        for(int i=1;i<=K;i++) g[i].clear();
        A=100;B=100;C=100;D=100;
        for(int i=1;i<=n;i++){
            g[read()].push_back(i);
            a[i]=read();b[i]=read();
            c[i]=read();d[i]=read();
        }top=0;
        for(int i=1;i<=K;i++){
            if(g[i].size()==1){
                A+=a[g[i][0]];
                B+=b[g[i][0]];
                C+=c[g[i][0]];
                D+=d[g[i][0]];
            }
            else if(g[i].size()>1)q[++top]=i;
        }
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}