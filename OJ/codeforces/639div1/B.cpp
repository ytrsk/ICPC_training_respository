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
char s[1007][1007];
int vis[1007][1007];
int dx[4]={0,0,1,-1};
int n,m,dy[4]={1,-1,0,0};
int check(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='#';
}
void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        if(check(x+dx[i],y+dy[i])&&!vis[x+dx[i]][y+dy[i]]){
            dfs(x+dx[i],y+dy[i]);
        } 
    }
}
int xX[1007],yY[1007],X[1007],Y[1007];
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(s[i][k]=='#') X[i]=Y[k]=xX[i]=yY[k]=1;
            if(!vis[i][k]&&s[i][k]=='#'){
                dfs(i,k);cnt++;
            }
        }
    }
    int ok=1;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(!X[i]&&!Y[k]){
                xX[i]=yY[k]=1;
            }
        }
    }
    for(int i=1;i<=n;i++) if(!xX[i]) ok=0;
    for(int i=1;i<=m;i++) if(!yY[i]) ok=0;
    for(int i=1;i<=n;i++){
        int you1=0,you0=0;
        for(int k=1;k<=m;k++){
            if(s[i][k]=='#'){
                if(you0) ok=0;
                you1=1;
            }
            else if(you1) you0=1;
        }
    }
    for(int i=1;i<=m;i++){
        int you1=0,you0=0;
        for(int k=1;k<=n;k++){
            if(s[k][i]=='#'){
                if(you0) ok=0;
                you1=1;
            } 
            else if(you1) you0=1;
        }
    }
    if(ok) cout<<cnt;
    else cout<<-1;
    return 0;
}