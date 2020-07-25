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
int a[maxn],id[maxn],b[maxn];
int head[maxn],
void dfs(int u,int v){
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
    }
}
int main(){
    int n=read(),ans=inf;
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        for(int k=0;k<n;k++){
            id[(k+i)%n+1]=k+1;
        }
        int mx=0,cnt=0;
        for(int k=1;k<=n;k++){
            b[k]=id[a[k]];
            if(mx>b[k]) cnt++;
            mx=max(mx,b[k]);
        }
        ans=min(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}