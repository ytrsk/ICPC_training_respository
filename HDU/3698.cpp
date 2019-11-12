#include <stdio.h>
#include <algorithm>
#include <string.h>
#define mp make_pair
#define pii pair<int,int>
#include <iostream>
#define lowbit(x) (x)&(-(x))
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=1e9;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int t[157][5007],f[157][5007],dp[157][5007];
int now=1,ID[5007],n,m,ID2[5007];
bool cmp(int x,int y){
    return -f[now][x]-x<=-f[now][y]-y;
}
bool Cmp(int x,int y){
    return x-f[now][x]<=y-f[now][y];
}
bool cmp2(int x,int y){
    return f[now+1][x]-x<=f[now+1][y]-y;
}
bool cmp3(int x,int y){
    return f[now+1][x]+x<=f[now+1][y]+y;
}
int mx[5007];
void add(int o,int x){
    for(int i=o;i<=m;i+=lowbit(i)) mx[i]=min(mx[i],x);
}
int query(int o){
    int ans=2e9;
    for(int i=o;i;i-=lowbit(i)) ans=min(ans,mx[i]);
    return ans;
}
void add2(int o,int x){
    for(int i=o;i;i-=lowbit(i)) mx[i]=min(mx[i],x);
}
int query2(int o){
    int ans=2e9;
    for(int i=o;i<=m;i+=lowbit(i)) ans=min(ans,mx[i]);
    return ans;
}
int main(){
  //  freopen("test.in","r",stdin);
    while(scanf("%d%d",&n,&m)==2&&(n||m)){
        for(int i=1;i<=n;i++)
            for(int k=1;k<=m;k++)
            scanf("%d",&t[i][k]);
            for(int i=1;i<=n;i++)
                for(int k=1;k<=m;k++)
                scanf("%d",&f[i][k]);
        for(int i=1;i<=m;i++) dp[1][i]=t[1][i];
        for(int i=2;i<=n;i++){
            now=i-1;
            for(int k=1;k<=m;k++) ID[k]=ID2[k]=k;
            sort(ID+1,ID+m+1,cmp);     sort(ID2+1,ID2+m+1,cmp2);
            for(int k=1;k<=m;k++) mx[k]=2e9;
            int top=1;
            for(int k=1;k<=m;k++){
                while(top<=m&&-f[now][ID[top]]-ID[top]<=f[i][ID2[k]]-ID2[k]) add(ID[top],dp[now][ID[top]]),top++;
                dp[i][ID2[k]]=query(ID2[k])+t[i][ID2[k]];
            }
            sort(ID2+1,ID2+m+1,cmp3);
            sort(ID+1,ID+m+1,Cmp);
            top=1;
            for(int k=1;k<=m;k++) mx[k]=2e9;
            for(int k=1;k<=m;k++){
                while(top<=m&&ID[top]-f[now][ID[top]]<=ID2[k]+f[i][ID2[k]]) add2(ID[top],dp[now][ID[top]]),top++;
                dp[i][ID2[k]]=min(dp[i][ID2[k]],query2(ID2[k])+t[i][ID2[k]]);
            }
        }
        int ans=2e9;
        for(int i=1;i<=m;i++) ans=min(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
