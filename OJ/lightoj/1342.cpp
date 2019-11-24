#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
double f[2][5007];
int main(){
    int t=read(),cnt=0;
    while(t--){
        int n=read();
        int suma=0,a=0,sumb=0,b=0;
        for(int i=1;i<=n;i++){
            int x=read(),y=read();
            if(y==1) suma+=x,a++;
            else sumb+=x,b++;
        }
        double pa=1.0*suma/a,pb=1.0*sumb/b;
        if(a==0) pa=0;
        if(b==0) pb=0;
        for(int i=a;~i;i--){
            int now=i&1,nex=now^1;
            for(int k=b;~k;k--){
                f[now][k]=0;
                if(i<a) f[now][k]+=f[nex][k]*(a-i)/(n-i-k);
                if(k<b) f[now][k]+=f[now][k+1]*(b-k)/(n-i-k);
                if(a-i||b-k) f[now][k]+=pa/(n-i-k)*(a-i),f[now][k]+=pb/(n-i-k)*b;
            }
        }
        printf("Case %d: %.8f\n",++cnt,f[0][0]);
    }
    return 0;
}
