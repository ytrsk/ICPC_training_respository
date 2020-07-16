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
int vis[maxn],a[maxn],to[maxn],pre[maxn];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> g;
            int x=i;
            while(!vis[x]){
                g.push_back(x);
                vis[x]=1;
                x=a[x];
            }
            int len=g.size();
            for(int k=0;k<len;k++) to[(1LL*k*m)%len]=k;
            for(int k=0;k<len;k++) pre[k]=g[to[k]];
            for(int k=0;k<len;k++) a[pre[k]]=pre[(k+1)%len];
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}