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
int a[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        int now=0;
        for(int i=1;i<=n;i++){
            int mx=0,pos=1;
            for(int k=1;k<=n;k++) if(a[k]&&__gcd(a[k],now)>mx) mx=__gcd(a[k],now),pos=k;
            printf("%d ",a[pos]);
            now=mx,a[pos]=0;
        }
        printf("\n");
    }
    return 0;
}