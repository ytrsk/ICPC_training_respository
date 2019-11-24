#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=1000007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
char s[1000007];
int a[1000007];
int n,m;
bool check(int a,int b){
    return a>=1&&a<=n&&b>=1&&b<=m;
}
int id(int x,int y){
    if(!check(x,y)) return 0;
    return (x-1)*m+y;
}
int vis[1000007],vis2[1000007];
int you[1000007],you2[1000007],aa[1000007];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s+1;
        for(int k=1;k<=m;k++) if(s[k]=='.') a[id(i,k)]=1;
    }
    vis[id(1,1)]=1;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(a[id(i,k)]&&(vis[id(i-1,k)]||vis[id(i,k-1)])) vis[id(i,k)]=1;
        }
    }
    vis2[id(n,m)]=1;
    for(int i=n;i;i--)
        for(int k=m;k;k--)
        if(a[id(i,k)]&&(vis2[id(i+1,k)]||vis2[id(i,k+1)])) vis2[id(i,k)]=1;
    if(!vis[id(n,m)]) printf("0");
    else{
        int ok=0;
        for(int i=1;i<=n;i++)
        for(int k=1;k<=m;k++){
            if(vis[id(i,k)]&&vis2[id(i,k)]) aa[id(i,k)]=1;
        }
        for(int i=1;i<=n;i++)
        for(int k=m;k;k--){
            you[id(i,k)]=(you[id(i-1,k)]|you[id(i,k+1)]|aa[id(i,k)]);
        }
        for(int i=n;i;i--)
        for(int k=1;k<=m;k++){
            you2[id(i,k)]=(you2[id(i+1,k)]|you2[id(i,k-1)]|aa[id(i,k)]);
        }
        for(int i=1;i<=n;i++)
        for(int k=1;k<=m;k++){
            if(!(i==1&&k==1||i==n&&k==m)){
                if(!you[id(i-1,k+1)]&&!you2[id(i+1,k-1)]){
                    ok=1;
                }
            }
        }
        if(ok) printf("1");
        else printf("2");
    }
    return 0;
}
