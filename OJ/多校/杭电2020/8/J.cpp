#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int mu[maxn],phi[maxn],a[maxn];
int len,p[maxn];
int you[maxn],now[maxn];
ll f[maxn],g[maxn];
int main(){
    mu[1]=1;phi[1]=1;
    for(int i=2;i<=200000;i++){
        if(!phi[i]) p[++len]=i,mu[i]=-1,phi[i]=i-1;
        for(int k=1;k<=len&&i*p[k]<=200000;k++){
            if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=mu[i]*mu[p[k]];
            else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=0;break;}
        }
    }
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=100000;i++) you[i]=0;
        for(int i=1;i<=n;i++) a[i]=read(),you[a[i]]=1;
        for(int i=1;i<=100000;i++)
        for(int k=i;k<=100000;k+=i) now[i]+=you[k];
        for(int i=2;i<=100000;i++){
            for(int k=i;k<=100000;k+=i){
                ans+=
            }
        }
    }
    return 0;
}