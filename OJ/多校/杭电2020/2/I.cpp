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
int a[407][407];
char s[4000007];
int c[407][407];
int top,q[4000007];
int vis[160007];
int main(){
    int t=read();
    while(t--){
        int n=read(),m=read(),Q=read();
        for(int i=1;i<=n;i++){
            for(int k=1;k<=m;k++){
                a[i][k]=read();
            }
        }
        rep(i,1,Q){
            int x=read(),y=read();scanf("%s",s+1);
            int x0=x,y0=y,xmn=x,xmx=x,ymn=y,ymx=y;
            int len=strlen(s+1);
            for(int i=1;i<=len;i++){
                if(s[i]=='R') c[x+1][y+1]++,x++;
                else if(s[i]=='L') c[x][y+1]++,x--;
                else if(s[i]=='U') y++;
                else y--;
                xmn=min(xmn,x);
                xmx=max(xmx,x);
                ymn=min(ymn,y);
                ymx=max(ymx,y);
            }
            top=0;
            for(int i=xmn+1;i<=xmx;i++){
                int tag=0;
                for(int k=ymn+1;k<=ymx;k++){
                    tag+=c[i][k];
                    if(tag&1) q[++top]=a[i][k];
                }
            }
            int ans=0;
            rep(i,1,top){
                ans+=!vis[q[i]];
                vis[q[i]]=1;
            }
            rep(i,1,top) vis[q[i]]=0;
            x=x0,y=y0;
            for(int i=1;i<=len;i++){
                if(s[i]=='R') c[x+1][y+1]--,x++;
                else if(s[i]=='L') c[x][y+1]--,x--;
                else if(s[i]=='U') y++;
                else y--;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}