#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=1e9+7;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
void del(int x,int y){
    x-=y;
    if(x<0) x+=mod;
}
int fac[maxn],inv[maxn];
int C(int a,int b){
    if(a<b) return 0;
    return 1LL*fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int val[maxn];
int mu[maxn],phi[maxn],sum[maxn];
int len,p[2000007];
int main(){
    mu[1]=1;phi[1]=1;
	for(int i=2;i<=100009;i++){
		if(!phi[i]) p[++len]=i,mu[i]=-1,phi[i]=i-1;
		for(int k=1;k<=len&&i*p[k]<=100000;k++){
			if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=mu[i]*mu[p[k]];
			else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=0;break;}
		}
	}
    for(int i=1;i<=100000;i++) if(mu[i]==-1) mu[i]=mod-1;
    int n=read(),K=read();
    for(int i=1;i<=K;i++){
        for(int k=i;k<=K;k+=i) add(val[k],mul(i,mu[k/i]));
    }
    int sum=0;
    for(int i=1;i<=K;i++){
        add(sum,mul(val[i],pown(K/i,n)));
    }
    cout<<sum;
    return 0;
}