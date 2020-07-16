#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
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
int you[maxn][13];
int vis[10007][1007];
int main(){
    int n=read(),m=read();
    for(int i=0;i<=n;i++) d[i]=read();
    sort(d+1,d+m+1);
    int g=read(),r=read();
    for(int i=0;i<=n;i++) vis[i][0]=1;
    for(int i=1;i<=g;i++)
    for(int k=1;k<=m;k++){
        if(k){
            int x=2*(d[k]-d[k-1]);
            if(i>=x&&vis[k-1][i-x]) vis[k][i]=1;
        }
        if(k<m){
            int x=2*(d[k+1]-d[k]);
            if(i>=x&&vis[k+1][i-x]) vis[k][i]=1;
        }
    }
    for(int i=1;i<=m)
    return 0;
}