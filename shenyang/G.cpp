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
ll ans;
int c[3007][3007];
void dfs(int o,int tot,int sum,ll ji){
    if(ji>tot*tot) return;
    if(sum+tot-(o-1)==ji){
        (ans+=c[tot][o-1])%=mod;
    }
    if(o==15||o==tot+1) return;
    for(int i=2;i<=tot;i++){
        dfs(o+1,tot,sum+i,ji*i);
    }
}
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    c[0][0]=1;
    for(int i=1;i<=3000;i++){
        c[i][0]=1;
        for(int k=1;k<=i;k++){
            c[i][k]=(c[i-1][k]+c[i-1][k-1])%mod;
        }
    }
    for(int i=1;i<=20;i++){
        ans=0;
        dfs(1,i,0,1);
        printf("%d %lld\n",i,ans);
    }
    return 0;
}
