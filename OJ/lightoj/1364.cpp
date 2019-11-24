#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int you[5];
pair<double,bool> aa[16][16][16][16][5][5];
bool vis[16][16][16][16][5][5];
struct node{
    int a[7];
    pair<double,bool>& rep(){
        return aa[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]];
    }
    bool& rev(){
        return vis[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]];
    }
};
void dfs(node u){
    if(u.rev()) return; //u.print();
    u.rev()=1;
    //u.print();
    if(u.a[4]>=you[4]&&u.a[1]>=you[1]&&u.a[2]>=you[2]&&u.a[3]>=you[3]){
        u.rep()=mp(0.0,true);return;
    }
    int sum=0;double tot=0;
    for(int i=1;i<=4;i++){
        int x=u.a[i]-(u.a[5]==i)-(u.a[6]==i);
        if(x<13){
            node now=u;now.a[i]++;
            dfs(now);
            if(!now.rep().second) continue;
            sum+=13-x;
            tot+=now.rep().first*(13-x);
        }
    }
    if(!u.a[5]||!u.a[6]){
        int x=(!u.a[5])+(!u.a[6]),y=1-(!u.a[5]);
        double zz=1e9;
        for(int i=1;i<=4;i++){
            node now=u;
            now.a[5+y]=i;now.a[i]++;
            dfs(now);
            if(!now.rep().second) continue;
            if(now.rep().first<zz){
                zz=now.rep().first;
            }
        }
        if(zz!=1e9){
            sum+=x;
            tot+=x*zz;
        }
    }
    if(sum==0) u.rep()=mp(0.0,false);
    else u.rep()=mp(tot/sum+1,true);
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        for(int i=1;i<=4;i++) you[i]=read();
        printf("Case %d: ",++cnt);
        memset(vis,0,sizeof(vis));
        node now;memset(now.a,0,sizeof(now.a));now.a[5]=now.a[6]=0;
        dfs(now);
        if(now.rep().second==false) printf("-1\n");
        else printf("%.8f\n",now.rep().first);
    }
    return 0;
}
