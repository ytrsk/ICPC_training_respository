#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
const int modb=20;
int head[modb],next1[80007],e1;
ll from[80007],to[80007];
inline void insert(ll u,ll v){
	++e1;from[e1]=u;to[e1]=v;next1[e1]=head[u%modb];head[u%modb]=e1;
}
inline ll find(ll x){
	for(int i=head[x%modb];i;i=next1[i])
	if(from[i]==x) return to[i];
	return -1;
}
inline ll powm(ll a,ll b,ll mod){
	/*ll ans=0;
	while(b){
    //    printf("a");
		if(b&1) ans=(ans+a)%mod;
		a=(a<<1)%mod;
		b>>=1;
	}
	return (ans+mod)%mod;*/
	return (a*b-(ll)((long double)a*b/mod)*mod+mod)%mod;
}
inline ll bsgs(ll a,ll b,ll c,ll mod){
	memset(head,0,sizeof(head));e1=0;
	if(b==1) return 0;
	int len=(int)sqrt(c+0.5);
	ll x=1,p=1;
	for(ll i=0;i<len;i++,p=powm(p,a,mod)) insert(powm(p,b,mod),i);
	for(ll i=len;;i+=len){
		x=powm(x,p,mod);ll j=find(x);
		if(j!=-1) return i-j;
		if(i>c) return -1;
	}
}
//copy from wiki
ll m[maxn],r[maxn];
inline ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;return a;
	}
	else{ll gcd=exgcd(b,a%b,y,x);y-=x*(a/b);return gcd;}
}
inline ll exchina(int n){
	ll x,y;ll tot=m[1],ans=r[1];
	for(int i=2;i<=n;i++){
		ll a=tot,b=m[i],c=(r[i]-ans%m[i]+m[i])%m[i];
		ll gcd=exgcd(a,b,x,y);
		if(c%gcd!=0) return -1;
		x=powm(x,c/gcd,b/gcd);
		ans+=x*tot;
		tot*=(b/gcd);
		ans=(ans%tot+tot)%tot;
	}
	return ans;
}
inline ll pown(ll a,ll b,ll mod){
    ll ans=1;
    while(b){
        if(b&1) ans=powm(ans,a,mod);
        a=powm(a,a,mod);
        b>>=1;
    }
    return ans;
}
inline ll pohlig_hellman(ll a,ll b,ll p,ll e,ll mod){
    ll r=pown(a,pown(p,e-1,mod),mod),x=0;
    for(ll i=0;i<e;++i){
        ll h=pown(powm(pown(pown(a,mod-2,mod),x,mod),b,mod),pown(p,e-1-i,mod),mod);
      //  printf("%lld %lld %lld %lld\n",r,h,p,mod);
        ll d=bsgs(r,h,p,mod);
        x=x+pown(p,i,mod)*d;
    }
    return x;
}
inline ll pohlig_hellman_ex(ll a,ll b,ll p[],ll e[],int len,ll mod){
    for(int i=1;i<=len;i++){
        ll aa=pown(a,(mod-1)/pown(p[i],e[i],mod),mod);
        ll bb=pown(b,(mod-1)/pown(p[i],e[i],mod),mod);
        m[i]=pown(p[i],e[i],mod);
        r[i]=pohlig_hellman(aa,bb,p[i],e[i],mod);
    }
    return exchina(len);
}
ll pp[5],e[3];
inline bool prime_root(ll x,ll p[],int len,ll mod){
    for(register int i=1;i<=len;i++){
        if(pown(x,mod/p[i],mod)==1) return false;
    }
    return true;
}
int main(){
    //freopen("testA.in","r",stdin);
    //freopen("testA.out","w",stdout);
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        ll p,a,b;cin>>p>>a>>b;
        e[1]=e[2]=0;
        ll x=p-1;
        ll g=0;
        while(x%2==0){
            x/=2;e[1]++;
        }
        while(x%3==0){
            x/=3;e[2]++;
        }
        ll lef=-1,rig=-1;
        int len=1;
        if(e[1]&&!e[2]){
            pp[1]=2;
        }
        else if(!e[1]&&e[2]){
            pp[1]=3;e[1]=e[2];//lef=pohlig_hellman_ex(g,a,pp,e,1,p);rig=pohlig_hellman_ex(g,b,pp,e,1,p);
        }
        else{
            pp[1]=2;pp[2]=3;len=2;//lef=pohlig_hellman_ex(g,a,pp,e,1,p);rig=pohlig_hellman_ex(g,b,pp,e,1,p);
        }
        for(int i=2;;i++){
            if(prime_root(i,pp,len,p)){
                g=i;break;
            }
        }
        lef=pohlig_hellman_ex(g,a,pp,e,len,p);rig=pohlig_hellman_ex(g,b,pp,e,len,p);
        if(lef==-1||rig==-1) printf("-1\n");
        else{
            ll xx,yy;
            ll gcd=exgcd(lef,p-1,xx,yy);
            ll bg=(p-1)/gcd;
            if(rig%gcd){printf("-1\n");continue;}
            xx=powm(xx,rig/gcd,bg);
            xx=(xx%bg+bg)%bg;
           // printf("%lld %lld %lld %lld %lld %lld\n",xx,bg,lef,rig,g,powm(lef,xx,p-1));
            printf("%lld\n",xx);
        }
    }
    return 0;
}
