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
long double a[1<<20],w[21],b[1<<20];double x;
int you[1<<20];
int main(){
    int n=read();
    for(int i=0;i<(1<<n);i++) scanf("%lf",&x),a[i]=x;
    for(int k=0;k<n;k++){
    for(int i=0;i<(1<<n);i++){
            if(i>>k&1) a[i]+=a[i^(1<<k)];
        }
    }
    double ans=0;
    for(int i=1;i<(1<<n);i++){
        you[i]=you[i>>1]+(i&1);
        b[i]=1-a[((1<<n)-1)^i];
        if(a[i]<1e-7){
            printf("INF");return 0;
        }
        if((you[i]+1)&1) ans-=1/b[i];
        else ans+=1/b[i];
    }
    printf("%.10f",(double)ans);
    return 0;
}