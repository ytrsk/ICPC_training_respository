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
int len;ll a[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        int pos=0;n--;
        if(n==1){
            printf("1\n0\n");continue;
        }
        while(2LL*(1LL<<pos+1)-2<=n) pos++;
        if(2*(1LL<<pos)-2==n){
            len=pos;
            for(int i=1;i<=pos;i++){
                a[i]=1LL<<i;
            }
        }
        else{
            n-=2*(1LL<<pos)-2;
            len=pos+1;int now=0;
            int ok=1;
            for(int i=1;i<=pos;i++){
                if(n<=(1LL<<i)&&ok) a[++now]=n,ok=0;
                a[++now]=(1LL<<i);
            }
            if(ok) a[++now]=n;
        }
        printf("%d\n",len);
        a[0]=1;
        for(int i=1;i<=len;i++) printf("%d ",a[i]-a[i-1]);
        printf("\n");
    }
    return 0;
}