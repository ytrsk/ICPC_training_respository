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
int a[maxn];
int q[4000007],top,vis[4007];
inline void check(int x){
    vis[x]=1;q[++top]=x;
}
int sg[2][1007][2];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
   // int n;cin>>n;
    sg[0][1][0]=sg[0][1][1]=sg[1][1][0]=0;
    sg[1][1][1]=1;
    for(int i=2;i<=1000;i++){
        for(int k=0;k<2;k++)
        for(int z=0;z<2;z++){
            check(sg[0][i-1][z]);
            check(sg[1][i-1][z]);
            check(sg[k][i-1][0]);
            check(sg[k][i-1][1]);
            for(int e=1;e<=i-2;e++){
                check(sg[k][e][0]^sg[0][i-1-e][z]);
                check(sg[k][e][1]^sg[1][i-1-e][z]);
            }
            for(int e=0;;e++){
                if(!vis[e]){
                    sg[k][i][z]=e;break;
                }
            }
            for(int e=1;e<=top;e++) vis[q[k]]=0;
        }
        printf("%d : %d\n",i,sg[0][i][0]);
    }
    return 0;
}
