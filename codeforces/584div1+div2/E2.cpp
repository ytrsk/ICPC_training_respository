#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int v[2007][12],id[2007],n,m;
bool cmp(int x,int y){
    return *max_element(v[x],v[x]+n)>*max_element(v[y],v[y]+n);
}
int dp[13][1<<12];
int mx[13][1<<12];
int main(){
    int t=read();
    while(t--){
        n=read(),m=read();
        for(int i=0;i<n;i++){
            for(int k=1;k<=m;k++) v[k][i]=read();
        }
        for(int i=1;i<=m;i++) id[i]=i;
        sort(id+1,id+m+1,cmp);
        for(int i=1;i<=min(n,m);i++){
            for(int k=0;k<(1<<n);k++){
                mx[i][k]=0;
                for(int z=0;z<n;z++){
                    int ans=0;
                    for(int j=0;j<n;j++){
                        if(k>>((z+j)%n)&1) ans+=v[id[i]][j];
                    }
                    mx[i][k]=max(mx[i][k],ans);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=min(n,m);i++){
            for(int k=0;k<(1<<n);k++){
                dp[i][k]=dp[i-1][k];
                for(int z=k;z;z=(z-1)&k){
                    dp[i][k]=max(dp[i][k],dp[i-1][k^z]+mx[i][z]);
                }
                ans=max(ans,dp[i][k]);
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
