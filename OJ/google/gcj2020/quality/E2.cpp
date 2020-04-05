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
int top,a[6][6][6],A[80][6],q[1000007][6][6],you[6][6],vis[6][6];
int ans[6][100007][6][6];
void dfs(int o,int x){
    if(o==x+1){
        int sum=0;
        for(int i=1;i<=x;i++) sum+=a[i][i][x];A[sum][x]=1;
        for(int i=1;i<=x;i++)
        for(int k=1;k<=x;k++){
            ans[x][sum][i][k]=a[i][k][x];
        }
        return;
    }
    for(int i=1;i<=top;i++){
        int ok=1;
        for(int k=1;k<o;k++){
            for(int z=1;z<=x;z++){
                if(a[k][z][x]==q[i][z][x]) ok=0;
            }
        }
        if(ok){
            for(int k=1;k<=x;k++) a[o][k][x]=q[i][k][x];
            dfs(o+1,x);
        }
    }
}
void Dfs(int o,int x){
    if(o==x+1){
        ++top;
        for(int i=1;i<=x;i++) q[top][i][x]=you[i][x];return;
    }
    for(int i=1;i<=x;i++){
        if(!vis[i][x]){
            vis[i][x]=1;you[o][x]=i;
            Dfs(o+1,x);
            vis[i][x]=0;
        }
    }
}
int main(){
    for(int i=2;i<=5;i++) top=0,Dfs(1,i),dfs(1,i);
    int t=read();int cnt=0;
    while(t--){
        printf("Case #%d: ",++cnt);
        int n=read(),K=read();
        if(A[K][n]){
            printf("POSSIBLE\n");
            for(int i=1;i<=n;i++)
            {
                for(int k=1;k<=n;k++) printf("%d ",ans[n][K][i][k]);
                printf("\n");
            }
        }
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}