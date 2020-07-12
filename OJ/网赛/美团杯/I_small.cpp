#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int A[3007],B[3007];
int aa[3007],bb[3007];
const int mo = 998244353;
int a = 10007;
int b = 18980504;
int res = 0;
int main(){
    freopen("file1.in","r",stdin);
    aa[0]=a;aa[1]=1;bb[1]=b;
    for(int i=2;i<=3000;i++){
        read();A[i]=read();B[i]=read();
        aa[i]=1LL*aa[A[i]]*aa[B[i]]%mo;
        bb[i]=(1LL*aa[B[i]]*bb[A[i]]+bb[B[i]])%mo;
    }
    printf("%d\n",bb[3000]);
    return 0;
}