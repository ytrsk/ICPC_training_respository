#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[507][507],v[507][507];
int top,sum[507];
int V[1000007];
int len[507][507];
void solve(){

}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++) a[i][k]=read();
    }
    for(int i=1;i<=n;i++)
    for(int k=1;k<=m;k++)
    v[i][k]=v[i][k-1]+a[i][k]+v[i-1][k];
    for(int i=1;i<=m;i++){
        for(int k=n;k>=1;k--){
            if(a[k][i]){
                v[i][k]=
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=i+1;k<=n;k++){
            for(int z=1;z<=m;z++){
                if(!a[i][z]||!a[k][z]){
                    solve();
                }
                ++top,sum[top]=2*(v[k][z]-v[i-1][z])+500000-(k-i+1)*z;
            }
            solve();
        }
    }
    return 0;
}