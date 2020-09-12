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
ll a[26][26],now[53];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            a[i][k]=(i%2)*(1LL<<(i+k-2));
            printf("%lld ",a[i][k]);
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
    }
    int q;scanf("%d",&q);
    for(int i=1;i<=q;i++){
        ll x;scanf("%lld",&x);
        for(int k=1;k<=2*n-1;k++) now[k]=x>>(k-1)&1;
        int nowx=1,nowy=1;
        printf("%d %d\n",1,1);
        fflush(stdout);
        for(int k=2;k<=2*n-1;k++){
            if(now[k]==nowx%2)nowy++;
            else nowx++;
            printf("%d %d\n",nowx,nowy);
            fflush(stdout);
        }
    }
    return 0;
}