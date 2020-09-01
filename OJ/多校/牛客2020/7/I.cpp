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
int mod;
int pown(int a,int b){
    if(b==-1) b=mod-2;
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int add(int a,int b){
    return a+b>=mod?a+b-mod:a+b;
}
int mul(int a,int b){
    return 1LL*a*b%mod;
}
int C[5007][5007],fac[5007],facp[5007],pre[5007][5007];
int main(){
    int t=read();mod=read();
    C[0][0]=1;fac[0]=1;
    for(int i=1;i<=5000;i++){
        fac[i]=1LL*fac[i-1]*i%mod;
        C[i][0]=1;
        for(int k=1;k<=i;k++){
            C[i][k]=add(C[i-1][k],C[i-1][k-1]);
        }
    }
    facp[5000]=pown(fac[5000],mod-2);facp[0]=1;
    for(int i=4999;i>=1;i--) facp[i]=mul(facp[i+1],i+1);
    for(int i=1;i<=5000;i++){
        for(int k=0;k<=i;k++) pre[i][k]=mul(fac[i],facp[k]);
    }
    while(t--){
        int n=read();
        if(n==1){
            printf("0\n");continue;
        }
        else if(n==2){
            printf("2\n");continue;
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans=add(ans,mul(mul(i,i),mul(C[n-1][i],pre[n-1][i])));}
        ans=mul(ans,n);
        printf("%d\n",ans);
    }
    return 0;
}