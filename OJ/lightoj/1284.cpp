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
double pown(double a,int b){
    double ans=1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        int n=read(),m=read(),q=read(),K=read();
        double ans=0;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=m;k++)
            for(int e=1;e<=q;e++){
                double x=1-1.0*((i-1)*(i-1)+(n-i)*(n-i))/(n*n);
                double y=1-1.0*((k-1)*(k-1)+(m-k)*(m-k))/(m*m);
                double z=1-1.0*((e-1)*(e-1)+(q-e)*(q-e))/(q*q);
                double r=x*y*z;
                double w=(1-pown(1-2*r,K))/2;
                ans+=w;
            }
        }
        printf("Case %d: %.8f\n",++cnt,ans);
    }
    return 0;
}
