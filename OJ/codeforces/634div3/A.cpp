#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],pre[maxn][207];
vector<int> g[207];
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=200;i++) g[i].clear();
        for(int i=1;i<=n;i++) a[i]=read(),g[a[i]].push_back(i);
        for(int i=1;i<=n;i++){
            for(int k=1;k<=200;k++) pre[i][k]=pre[i-1][k];
            pre[i][a[i]]++;
        }
        int ans=0;
        for(int i=1;i<=200;i++){
            ans=max(ans,(int)g[i].size());
            int L=1,R=n;
            for(int k=1;k<=(int)g[i].size()/2;k++){
                while(a[L]^i) L++;
                while(a[R]^i) R--;
                for(int z=1;z<=200;z++){
                    ans=max(ans,k*2+pre[R-1][z]-pre[L][z]);
                }
                L++;R--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}