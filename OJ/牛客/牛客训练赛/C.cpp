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
int tot[16],a[16][16],pre[16][16],sum[16];
int main(){
    int n=read(),m=read(),K=read();
    for(int i=0;i<n;i++)
    for(int k=0;k<m;k++)
    a[i][k]=read(),tot[k]+=a[i][k];
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        int x=__builtin_popcount(i);
        if(x<=K){
            int now=0;
            for(int k=0;k<m;k++) sum[k]=tot[k]; 
            for(int k=0;k<n;k++){
                if(i>>k&1){
                    for(int z=0;z<m;z++) sum[z]-=a[k][z],now+=a[k][z];
                }
            }
            sort(sum,sum+m);
            int len=min(m,K-x);
            for(int i=m-len;i<m;i++) now+=sum[i];
            ans=max(ans,now);
        }
    }
    cout<<ans;
    return 0;
}