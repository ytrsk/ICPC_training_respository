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
int mu[maxn],phi[maxn],len,p[maxn],pm[maxn];
int sum[maxn];
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (node nd) const{
        if(x^nd.x) return x>nd.x;
        else return y<nd.y;
    }
}q[maxn*30];
int main(){
    mu[1]=1;phi[1]=1;
	for(int i=2;i<=100000;i++){
		if(!phi[i]) p[++len]=i,mu[i]=-1,phi[i]=i-1,pm[i]=i;
		for(int k=1;k<=len&&i*p[k]<=100000;k++){
			if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=mu[i]*mu[p[k]],pm[i*p[k]]=p[k];
			else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=0;pm[i*p[k]]=pm[i];break;}
		}
	}
    int n;while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++) sum[i]=read(),sum[i]+=sum[i-1];
        int cnt=0;
        ll ans=0;
        for(int i=1;i<=n;i++){
            int x=i;
            while(x-1){
                q[++cnt]=node(pm[x],i);
                x/=pm[x];
                ans+=sum[n]-sum[i-1];
            }
        }
        sort(q+1,q+cnt+1);
        int l=1,r=n;
        for(int i=1;i<=cnt;i++){
            if(q[i].y>r) continue;
            ll x=0,y=max(q[i].y,l);
            if((x=2*(sum[r]-sum[y-1])-sum[n])>0){
                ans-=x;
                l=y;
            }
            else r=q[i].y-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}