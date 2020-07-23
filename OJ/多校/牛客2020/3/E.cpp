#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=2000007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int top=0,q[maxn],val[maxn];
int p[maxn],mu[maxn],len,phi[maxn];
int a,b;
int ok=0;ll ans[4];
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;return;
	}
	exgcd(b,a%b,y,x);y-=x*(a/b);
}
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
ll mx=4000000000000LL;
void dfs(int o,int now){
    if(o==top+1){
        if(now==1) return;
        ll x,y;exgcd(now,b/now,x,y);x*=a;
        ll s=b/now;
        x=(x%s+s)%s;
        if(x==0) x+=s;
        x=x+(mx-x)/s*s;
        y=(a-now*x)/(b/now);
        //  cout<<now<<" "<<x<<" "<<b/now<<" "<<y<<endl;
        if(x<=mx&&y<0&&-y<=mx) ok=1,ans[0]=x,ans[1]=b/now,ans[2]=-y,ans[3]=now;
        s=now;
        exgcd(now,b/now,x,y);y*=a;
        y=(y%s+s)%s-s;
        y=y-(mx+y)/s*s;
        x=(a-1LL*b/now*y)/now;
        //cout<<x*now+y*b/now<<endl;
        if(x>0&&x<=mx&&y<0&&-y<=mx&&x*now+b/now*y==a) {//这行注释掉能过
            ok=1,ans[0]=x,ans[1]=b/now,ans[2]=-y,ans[3]=now;
        }
        return;
    }
    dfs(o+1,now*val[o]);
    dfs(o+1,now);
}
int main(){
    mu[1]=1;
    for(int i=2;i<=2000000;i++){
		if(!phi[i]) p[++len]=i,mu[i]=i,phi[i]=i-1;
		for(int k=1;k<=len&&i*p[k]<=2000000;k++){
			if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=p[k];
			else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=mu[i];break;}
		}
	}
    int t=read();
    while(t--){
        a=read(),b=read();
        top=ok=0;
        int pre=b;
        ll g=gcd(a,b);
        if(gcd(a,b)>1) {
            printf("%lld %lld %lld %lld\n", a/g+1, b/g, 1ll, b/g);
            continue;
        }
        while(b!=1){
            if(mu[b]==q[top]) val[top]=val[top]*mu[b];
            else q[++top]=mu[b],val[top]=mu[b];
            b/=mu[b];
        }
        b=pre;
        if(mu[b]==b){
            if(a%b==0&&b!=1){
                printf("%d %d %d %d\n",a/b+1,1,1,1);
            }
            else printf("-1 -1 -1 -1\n");
            continue;
        }
        dfs(1,1);
        if(ok){
            printf("%lld %lld %lld %lld\n",ans[0],ans[1],ans[2],ans[3]);
        }
        else printf("%d %d %d %d\n",-1,-1,-1,-1);
    }
    return 0;
}