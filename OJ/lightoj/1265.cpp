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
double p[1007][1007];
int c(int x){
    return x*(x-1)/2;
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        int n=read(),m=read();
        for(int i=0;i<=m;i++) p[0][i]=1;
        for(int i=1;i<=n;i++)
        for(int k=0;k<=m;k++){
            p[i][k]=0;
            double x=0,z=0;
            if(i>=2){
                z+=p[i-2][k]*c(i)/c(i+k+1);
            }
            if(k){
                z+=p[i][k-1]*(i*k)/c(i+k+1);
                x=1.0*c(k)/c(i+k+1);
                double e=(z+1.0*k/c(i+k+1)*p[i][k-1])/(1-x);
                if(e<p[i][k-1]){
                    p[i][k]=e;
                }
                else p[i][k]=z/(1-x-1.0*k/c(i+k+1));
            }
            else{
                p[i][k]=z/(1-x);
            }
        }
        printf("Case %d: %.8f\n",++cnt,p[n][m]);
    }
    return 0;
}
