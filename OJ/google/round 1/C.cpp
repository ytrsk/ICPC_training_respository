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
short int fa[1007][1007][5],n,m;
int find(int a,int b,int c){
    if(c==1||c==2) return fa[a][b][c]==a?fa[a][b][c]:find(fa[a][b][c],b,c);
    if(c==3||c==4) return fa[a][b][c]==b?fa[a][b][c]:find(a,fa[a][b][c],c);
    return 0;
}
pii found(int a,int b,int c){
    int x=find(a,b,c);
    if(c==1||c==2) return (x>=1&&x<=n)?mp(x,b):mp(0,0);
    else return (x>=1&&x<=m)?mp(a,x):mp(0,0);
}
int a[1007][1007],vis[1007][1007];vector<pii> nex,Y,g;
int main(){
    int t=read(),cnt=0;
    while(t--){
        n=read(),m=read();
        ll Sum=0;
        for(int i=1;i<=n;i++)
        for(int k=1;k<=m;k++){
            a[i][k]=read();Sum+=a[i][k];
            fa[i][k][1]=fa[i][k][2]=i;vis[i][k]=0;
            fa[i][k][3]=fa[i][k][4]=k;
        }
        for(int i=1;i<=n;i++) fa[i][0][3]=0,fa[i][m+1][4]=m+1;
        for(int i=1;i<=m;i++) fa[0][i][1]=0,fa[n+1][i][2]=n+1;
        g.clear();
        for(int i=1;i<=n;i++)
        for(int k=1;k<=m;k++)
        g.push_back(mp(i,k));
        ll ans=0;
       int cc=0;
        while(1){
            nex.clear();Y.clear();
            int ok=0;++cc;
            ll pre=0;
            for(int e=0;e<g.size();e++){
                int i=g[e].first,k=g[e].second;
                if(vis[i][k]) continue;
                int you=0,sum=0;
                for(int z=1;z<=4;z++){
                    pii now;
                    if(z==1) now=found(i-1,k,z);
                    if(z==2) now=found(i+1,k,z);
                    if(z==3) now=found(i,k-1,z);
                    if(z==4) now=found(i,k+1,z);
                    if(now==mp(0,0)) continue;
                    you++,sum+=a[now.first][now.second];
                }
                if(sum>you*a[i][k]){
                    Y.push_back(mp(i,k));
                }
            }
            for(int e=0;e<Y.size();e++){
                int i=Y[e].first,k=Y[e].second;
                Sum-=a[i][k];pre+=a[i][k],ok=1;
                fa[i][k][1]=i-1;
                fa[i][k][2]=i+1;
                fa[i][k][3]=k-1;
                fa[i][k][4]=k+1;
                for(int z=1;z<=4;z++){
                    pii now=found(i,k,z);
                    if(now==mp(0,0)) continue;
                    if(!vis[now.first][now.second]) nex.push_back(now);
                }
            }
            ans+=Sum+pre;
            swap(nex,g);
            if(!ok) break;
        } 
        printf("Case #%d: ",++cnt);
        printf("%lld\n",ans);
    }
    return 0;
}