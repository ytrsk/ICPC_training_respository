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
int a[maxn];
bool you[507][507],sum[507][507];
int mx[507][507],mn[507][507],MX[507][507],num[507][507];

int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read(),sum[i][i]=a[i],you[i][i]=1,mx[i][i]=a[i],MX[i][i]=0,mn[i][i]=a[i];
    for(int i=n-1;i;i--){
        for(int k=i+1;k<=n;k++){
            mn[i][k]=min(a[k],mn[i][k-1]);
            mx[i][k]=max(a[k],mx[i][k-1]);
            int now=0,ok=0;
            if(mx[i][k]-mn[i][k]<=20){
                for(int z=i;z<=k;z++)
                now+=(1<<a[z]-mn[i][k]);
                if(!((now-1)&now)) ok=1;
            }
            
            for(int z=i;z<k;z++){
                if(you[i][z]&&you[z+1][k]&&ok) you[i][k]=1;
                MX[i][k]=max(MX[i][k],MX[i][z]+MX[z+1][k]);
            }
            if(you[i][k]) MX[i][k]=k-i;
        }
    }
    cout<<n-MX[1][n];
    return 0;
}