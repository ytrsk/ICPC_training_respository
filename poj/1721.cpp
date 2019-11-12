#include <stdio.h>
#include <iostream>
#include <algorithm>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=1007;
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
int a[maxn][maxn],b[maxn][maxn],c[maxn],r[maxn],vis[maxn];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int pown(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b&1) (ans*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return ans;

}
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n=read(),m=read();
    for(int i=0;i<n;i++) r[i]=read(),r[i]--;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int u=i,top=++a[0][0];
            while(!vis[u]){
                vis[u]=1;
                a[top][a[0][top]++]=u;
                u=r[u];
            }
        }
    }
    for(int i=1;i<=a[0][0];i++) for(int k=0;k<a[0][i];k++) b[i][k*pown(2,m,a[0][i])%a[0][i]]=a[i][k];
    b[0][0]=a[0][0];for(int i=1;i<=a[0][0];i++) b[0][i]=a[0][i];
    for(int i=1;i<=b[0][0];i++) for(int k=0;k<b[0][i];k++) c[b[i][k]]=b[i][(k+1)%b[0][i]];
    for(int i=0;i<n;i++) printf("%d\n",c[i]+1);
    return 0;
}
