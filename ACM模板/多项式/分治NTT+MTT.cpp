#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=300007;
const ll Mod=1337006139375617;
const int mod=100003,G=3;
int rev[maxn<<2];
ll fm(ll a,ll b,ll mod) {
    return (a*b - (ll)((long double)a/mod*b)*mod+mod)%mod;
}
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
ll pown(ll a,ll b,ll mod){
	if(b<0){
		b=-b;a=pown(a,mod-2,mod);
	}
	ll ans=1;
	while(b){
		if(b&1) ans=fm(ans,a,mod);
		a=fm(a,a,mod);
		b>>=1;
	}
	return ans;
}

void ntt(vector<ll> &a,int n,int dft){
	for(int i=0;i<n;i++)
	if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1){
		ll wn=pown(G,dft*(Mod-1)/(i*2),Mod);
		for(int k=0;k<n;k+=i<<1){
			ll wnk=1;
			for(int j=k;j<k+i;j++){
				ll x=a[j],y=fm(wnk,a[j+i],Mod);
				a[j]=(x+y)%Mod;a[j+i]=(x-y+Mod)%Mod;
				wnk=fm(wnk,wn,Mod);
			}
		}
	}
	if(dft==-1){
		ll inv1=pown(n,Mod-2,Mod);
		for(int i=0;i<n;i++) a[i]=fm(a[i],inv1,Mod);
	}
}
int e1;
struct poly{
    int len;vector<ll> a;
    poly(vector<ll> a):a(a){
        len=a.size()-1;
    }
    poly(){
        len=0;
    }
    void change(){
        while(len&&a[len]==0) len--,a.pop_back();
    }
    poly operator * (poly x){
        poly nex;nex.len=len+x.len;
        int bit=1;
        while((1<<bit)<=nex.len) bit++;
        for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
        vector<ll> A,B;
        for(int i=0;i<=len;i++) A.push_back(a[i]);
        for(int i=0;i<=x.len;i++) B.push_back(x.a[i]);
        for(int i=len+1;i<(1<<bit);i++) A.push_back(0);
        for(int i=x.len+1;i<(1<<bit);i++) B.push_back(0);
        ntt(A,1<<bit,1);ntt(B,1<<bit,1);
        for(int i=0;i<(1<<bit);i++) A[i]=fm(A[i],B[i],Mod);
        ntt(A,1<<bit,-1);
        for(int i=0;i<=nex.len;i++) nex.a.push_back(A[i]%mod);
        return nex;
    }
    void print(){
        for(int i=0;i<=len;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
}pp[100007];
unordered_map<int,int> aa;
poly ntt(int l,int r){
    if(l==r) return pp[l];
    int m=(l+r)>>1;
    return ntt(l,m)*ntt(m+1,r);
}
int zz[100007],val[100007];
int pre[100007];
int c(int x,int y){
    return 1LL*pre[x]*pown(pre[y],mod-2,mod)%mod*pown(pre[x-y],mod-2,mod)%mod;
}
int main(){
    int n,q,a;cin>>n>>a>>q;
    zz[0]=1;
    pre[0]=1;
    for(int i=1;i<=n;i++) pre[i]=1LL*pre[i-1]*i%mod;
    for(int i=1;i<mod-1;i++) zz[i]=1LL*zz[i-1]*a%mod;
    for(int i=1;i<=n;i++){
        val[i]=read();
        pp[i].len=1;
        pp[i].a.push_back(1);
        pp[i].a.push_back(zz[val[i]%100002]);
    }
    poly A=ntt(1,n);
    for(int i=1;i<=q;i++){
        int r=read();
        printf("%d\n",1LL*(A.a[r]-c(n,r)+mod)%mod*pown(a-1,mod-2,mod)%mod);
    }
    return 0;
}
