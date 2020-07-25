#include<bits/stdc++.h>
 
using namespace std;
 
inline int Get_Int() {
    int num=0,bj=1;
    char x=getchar();
    while(!isdigit(x)) {if(x=='-')bj=-1;x=getchar();}
    while(isdigit(x)) {num=num*10+x-'0';x=getchar();}
    return num*bj;
}
 
#define mp make_pair
#define pii pair<int,int>
 
const int maxn=305;
 
typedef long long LL;
 
int n,m,k,a[maxn],b[maxn];
LL Map[maxn][maxn],f[maxn<<1][maxn];
vector<pii> mission;
 
int main() {
    n=Get_Int();
    m=Get_Int();
    k=Get_Int();
    memset(Map,0x0f,sizeof(Map));
    for(int i=1; i<=n; i++)Map[i][i]=0;
    for(int i=1; i<=m; i++) {
        int x=Get_Int(),y=Get_Int();
        LL v=Get_Int();
        Map[x][y]=Map[y][x]=min(Map[x][y],v);
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)Map[i][j]=min(Map[i][j],Map[i][k]+Map[k][j]);
    for(int i=1; i<=k; i++) {
        a[i]=Get_Int();
        b[i]=Get_Int();
    }
    mission.push_back(mp(1,a[1]));
    for(int i=1; i<=k; i++) {
        mission.push_back(mp(a[i],b[i]));
        if(i<k)mission.push_back(mp(b[i],a[i+1]));
    }
    k=mission.size();
    memset(f,0x0f,sizeof(f));
    f[0][0]=0;
    for(int i=1; i<=k; i++) {
        int x=mission[i-1].first,y=mission[i-1].second;
        long long now=0x0f0f0f0f0f0f0f0f; 
        for(int a=1; a<=n; a++) { //从a开始传送
            for(int b=1; b<=n; b++) { //传送到b
                f[i][b]=min(f[i][b],f[i-1][a]+Map[a][b]+Map[b][y]);
                f[i][a]=min(f[i][a],f[i-1][b]+Map[x][a]+Map[b][y]); //传送，不替换传送门
                f[i][b]=min(f[i][b],f[i-1][b]+Map[x][a]+Map[b][y]); //传送，替换传送门
            }
            for(int b=0; b<=n; b++)f[i][a]=min(f[i][a],f[i-1][b]+Map[x][a]+Map[a][y]); //不传送，留下传送门
            f[i][a]=min(f[i][a],f[i-1][a]+Map[x][y]); //不传送，不留下传送门
        }
        f[i][0]=f[i-1][0]+Map[x][y]; //没有传送门
    }
    LL ans=LLONG_MAX/2;
    for(int i=0; i<=n; i++)ans=min(ans,f[k][i]);
    printf("%lld\n",ans);
    return 0;
}