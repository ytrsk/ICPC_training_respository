#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int vis[maxn][maxn];
int tag[maxn][maxn][2];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int d[maxn][maxn],n;
bool check(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=n;
}
void dfs(int u,int v){
    for(int i=0;i<4;i++){
        int x=u+dx[i],y=v+dy[i];
        if(check(x,y)&&tag[x][y][0]==tag[u][v][0]&&tag[x][y][1]==tag[u][v][1]&&d[x][y]<0){
            d[x][y]=i^1;dfs(x,y);
        }
    }
}
void Dfs(int u,int v){
    for(int i=0;i<4;i++){
        int x=u+dx[i],y=v+dy[i];
        if(check(x,y)&&tag[x][y][0]==-1){
            d[u][v]=i;
            return;
        }
    }
}
int main(){
    memset(d,-1,sizeof(d));
    n=read();
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            tag[i][k][0]=read();
            tag[i][k][1]=read();
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++)
        if(tag[i][k][0]==i&&tag[i][k][1]==k){
            d[i][k]=4;dfs(i,k);
        }
    }
    int ok=1;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            if(tag[i][k][0]>=0&&d[i][k]<0) ok=0;
        }
    }
    if(ok){
        for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++){
            if(tag[i][k][0]==-1){
                Dfs(i,k);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            if(d[i][k]<0) ok=0;
        }
    }
    if(ok){
        printf("VALID\n");
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                if(d[i][k]==0) putchar('R');
                else if(d[i][k]==1) putchar('L');
                else if(d[i][k]==2) putchar('D');
                else if(d[i][k]==3) putchar('U');
                else putchar('X');
            }
            printf("\n");
        }
    }
    else printf("INVALID");
    return 0;
}