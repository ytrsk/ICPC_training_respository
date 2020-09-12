#include <bits/stdc++.h>
#define mp make_pair
#define re register
#define cs const
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=40007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int fac[maxn],inv[maxn];
int dp[3007][3007],f[3007][3007],C[6007][6007];
const int mod=998244353,inv2=mod+1>>1;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(int a,int b){return a<b?a-b+mod:a-b;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int pown(int a,int b){
    int res=1;
	while(b){
		if(b&1)res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
int a[3007],g[3007][3007],pre[3007];
int main(){
	pre[0]=1;
	for(int i=1;i<=3000;i++) pre[i]=mul(2,pre[i-1]);
    C[0][0]=1;
    for(int i=1;i<=6000;i++){
        C[i][0]=1;
        for(int k=1;k<=i;k++) C[i][k]=add(C[i-1][k],C[i-1][k-1]);
    }
    fac[0]=inv[0]=1;
    int N=1000000;
    for(int i=1;i<=N;i++) fac[i]=1LL*fac[i-1]*i%mod;
    inv[N]=pown(fac[N],mod-2);
    for(int i=N-1;i;i--) inv[i]=1LL*inv[i+1]*(i+1)%mod;
	f[0][0]=g[0][0]=0;
	for(int i=0;i<=3000;i++)
	for(int k=0;k<=3000;k++){
		if(i==0&&k==0) continue;
		f[i][k]=add(f[i][k],mul(2*k,f[i][k-1]));
		if(i) f[i][k]=add(f[i][k],mul(2*i,f[i-1][k]));
		
	}
	int t=read();
	while(t--){
		int n=read();
		for(int i=1;i<=2*n+1;i++) a[i]=read()%mod;
		int ans=0,tot=n;
		for(int i=2;i<=2*n+1;i++){
			if(i%2==0){
				ans=add(ans,mul(f[(i/2)-1][n-(i/2-1)],dec(a[i],a[i-1])));
			}
			else ans=add(ans,mul(f[n-(i/2-1)][(i/2)-1],dec(a[i],a[i-1])));
		}
		cout<<ans<<endl;
		printf("%d\n",mul(ans,mul(inv[n],pown(pre[n],mod-2))));
	}
    return 0;
}