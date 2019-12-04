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
ll dpw[10][10],dpb[10][10];
ll c[9][9];
void solvew(){
    dpw[0][0]=1;
    for(int i=1;i<=8;i++){
        int len=((i+1)/2)*2-1;
        dpw[i][0]=1;
        for(int k=1;k<=len;k++){
            dpw[i][k]=dpw[i-1][k-1]*(len-k+1)+dpw[i-1][k];
        }
    }
}
void solveb(){
    dpb[0][0]=1;
    for(int i=1;i<=8;i++){
        int len=((i+1)/2)*2;
        dpb[i][0]=1;
        for(int k=1;k<=len;k++){
            dpb[i][k]=dpb[i-1][k-1]*(len-k+1)+dpb[i-1][k];
        }
    }
}
int main(){
    c[0][0]=1;
    for(int i=1;i<=8;i++){
        c[i][0]=1;
        for(int k=1;k<=i;k++){
            c[i][k]=c[i-1][k]+c[i-1][k-1];
        }
    }
    int n,m;solvew();solveb();
    while(n=read(),m=read(),n||m){
        ll ans=0;
        for(int i=0;i<=m;i++)
        if(i<=8&&m-i<=8)ans+=dpw[n][i]*dpb[n-1][m-i];
        printf("%lld\n",ans);
    }
    return 0;
}