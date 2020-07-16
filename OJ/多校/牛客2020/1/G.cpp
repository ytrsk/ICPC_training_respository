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
const int mod=998244353;
int v[maxn][3];
int main(){
    int n=read(),m=read(),q=read();
    unsigned z=read(),a=read(),b=read();
    for(int i=1;i<=n;i++)
    for(int j=0;j<3;j++){
        z=z*a+b;
        v[i][j]=z%mod;
    }
    return 0;
}