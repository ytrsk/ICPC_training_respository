#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
ll a[507][507];
int vis[10007];
int main(){
    int n=read(),m=read();
    if(n==1&&m==1) cout<<"0\n";
    else{
        if(n==1){
            for(int i=1;i<=m;i++) a[1][i]=i+1;
        }
        else if(m==1){
            for(int i=1;i<=n;i++) a[i][1]=i+1;
        }
        else{
            int r=n+m;
            int x=r/2,now=3;
            if(m<=x){
                for(int i=1;i<=m;i++) a[1][i]=2*i,vis[2*i]=1;
                for(int i=2;i<=n;i++){
                    while(vis[now]) now++;
                    a[i][1]=now++;
                }
            }
            else{
                for(int i=1;i<=n;i++) a[i][1]=2*i,vis[2*i]=1;
                for(int i=2;i<=m;i++){
                    while(vis[now]) now++;
                    a[1][i]=now++;
                }
            }
            for(int i=2;i<=n;i++)
            for(int k=2;k<=m;k++)
            a[i][k]=a[i][1]*a[1][k];
        }
        for(int i=1;i<=n;i++){
            for(int k=1;k<=m;k++) printf("%lld ",a[i][k]);
            printf("\n");
        }
    }
    return 0;
}