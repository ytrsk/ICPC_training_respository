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
int f[1000007],inv[2000007],phi[1000007],mu[1000007],p[1000007],len,F[1000007],fac[2000007];
int C(int a,int b){
    if(a<b) return 0;
    return 1LL*fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int a[maxn];
int main(){
    int t=read();
    fac[0]=inv[0]=1;
    for(int i=1;i<=2000000;i++) fac[i]=1LL*fac[i-1]*i%mod;
    for(int i=1;i<=2000000;i++) inv[i]=pown(fac[i],mod-2);
    mu[1]=1;phi[1]=1;
    for(int i=2;i<=1000000;i++){
		if(!phi[i]) p[++len]=i,mu[i]=-1,phi[i]=i-1;
		for(int k=1;k<=len&&i*p[k]<=1000000;k++){
			if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=mu[i]*mu[p[k]];
			else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=0;break;}
		}
	}
    f[1]=1;
    for(int i=2;i<=1000000;i++) f[i]=(f[i-1]+f[i-2])%(mod-1);
    for(int i=1;i<=1000000;i++) F[i]=(pown(2,f[i])+mod-1)%mod;
    while(t--){
        int n=read(),m=read(),ans=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                int now=C(n/i+m-1,m-1);
                int len=sqrt(i+0.5);
                for(int k=1;k<=len;k++){
                    if(i%k==0){
                        ans+=1LL*now*(0LL+mod+mu[k])%mod*F[i/k]%mod;
                        ans%=mod;
                        if(k!=i/k){
                            ans+=now*(0LL+mod+mu[i/k])%mod*F[k]%mod;
                            ans%=mod;
                        }
                    }
                }
            }
        }
        cout<<1LL*ans*pown(C(n+m-1,m-1),mod-2)%mod<<"\n";
    }
    return 0;
}