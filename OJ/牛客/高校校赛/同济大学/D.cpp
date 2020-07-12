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
char s[13][13];
int top,X[13],Y[13],K;
int ok;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;
int you[13][13];
bool check(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='.';
}
void dfs(int o){
    if(ok) return;
    if(o==K+1){
        for(int i=1;i<=top;i++){
            if(you[X[i]][Y[i]]){
                ok=1;return;
            }
        }
        return;
    }
    else{
        rep(i,1,top){
            int px=X[i],py=Y[i];
            rep(k,0,3){
                for(;check(X[i]+dx[k],Y[i]+dy[k]);X[i]+=dx[k],Y[i]+=dy[k]);
                swap(s[X[i]][Y[i]],s[px][py]);
                dfs(o+1);
                swap(s[px][py],s[X[i]][Y[i]]);
                X[i]=px;Y[i]=py;
                if(ok) return;
            }
        }
    }
}
int main(){
    m=read(),n=read();K=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(s[i][k]=='R'){
                ++top;
                X[top]=i;Y[top]=k;
            }
            else if(s[i][k]=='D'){
                s[i][k]='.';you[i][k]=1;
            }
        }
    }
    if(top==0){
        printf("NO");return 0;
    }
    dfs(1);
    if(ok) printf("YES");
    else printf("NO");
    return 0;
}