#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int vis[107][107];
int main(){
    int n=read(),m=read(),sx=read(),sy=read();
    printf("%d %d\n",sx,sy);
    vis[sx][sy]=1;int st=sx;
    for(int i=1;i<=m;i++){
        if(!vis[sx][i]){
            sy=i;
            vis[sx][sy]=1;
            printf("%d %d\n",sx,sy);
        }
    }
    for(int i=1;i<=n;i++){
        if(i==st) continue;
        sx=i;
        printf("%d %d\n",sx,sy);
        vis[sx][sy]=1;
        for(int k=1;k<=m;k++){
            if(!vis[sx][k]){
                sy=k;vis[sx][sy]=1;
                printf("%d %d\n",sx,sy);
            }
        }
    }
    return 0;
}