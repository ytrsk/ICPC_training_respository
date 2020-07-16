
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
int a[maxn],you[maxn],vis[107],len,b[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read(),m=read();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) a[i]=read(),vis[a[i]]=1;len=0;
        for(int i=1;i<=n;i++){
            if(vis[i]) b[++len]=i;
        }
        if(len<=m){
            printf("%d\n",max(m,n)*m);
            for(int i=1;i<=max(m,n);i++)
            for(int k=1;k<=m;k++){
                printf("%d ",k<=len?b[k]:1);
            }
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}