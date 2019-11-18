# DP
## 决策单调性
~~~ c++
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
ll col[100007],dp[21][100007],a[100007],ans=0,l1,r1;
void modify(int x,int y){
    int z=a[x];
    ans-=col[z]*(col[z]-1)/2;col[z]+=y;ans+=col[z]*(col[z]-1)/2;
}
void move(int l2,int r2){
    while(r1<r2) modify(r1+1,1),++r1;
    while(l1>l2) modify(l1-1,1),--l1;
    while(r1>r2) modify(r1,-1),--r1;
    while(l1<l2) modify(l1,-1),++l1;
}
inline void solve(int o,int l,int r,int L,int R){
    if(l>r) return;
    int m=(l+r)>>1;
    int pos=-1;
    ll val=(1LL<<60);
    for(int i=L;i<=min(m,R);i++){
        move(i,m);
        if(dp[o-1][i-1]+ans<=val){
            val=dp[o-1][i-1]+ans;pos=i;
        }
    }
    dp[o][m]=val;
    solve(o,l,m-1,L,pos);
    solve(o,m+1,r,pos,R);
}
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=m;i++){
        for(int k=1;k<=n;k++) col[k]=0;
        l1=1,r1=0,ans=0;
        if(i!=1) solve(i,1,n,1,n);
        else solve(i,1,n,1,1);
    }
    cout<<dp[m][n];
    return 0;
}
~~~
## 数位dp
~~~ c++
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const double eps=1e-6;
int len,num[107],mlen;
long long dp[107][10][2][2];
long long dfs(int pos,int pre,int you1,int you2,int limit){
	if(pos==0){
		if(you2) return 1;else return 0;
	}
	if(pos!=mlen&&!limit) if(dp[pos][pre][you1][you2]!=-1) {return dp[pos][pre][you1][you2];}
	else dp[pos][pre][you1][you2]=0;
	int start=(pos==mlen)?1:0,end=limit?num[pos]:9;
	long long ans=0;
	for(int i=start;i<=end;i++){
		ans+=dfs(pos-1,i,pos==mlen?0:(i>pre),you2|(you1&(i>pre)),limit&(i==end));
	}
	if(pos!=mlen&&!limit) dp[pos][pre][you1][you2]=ans;
	return ans;
}
long long check(long long x){
	len=0;
	while(x){
		num[++len]=x%10;
		x/=10;
	}
	long long ans=0;
	for(int i=1;i<len;i++){
		mlen=i;ans+=dfs(i,0,0,0,0);
	}
	mlen=len;ans+=dfs(mlen,0,0,0,1);
	return ans;
}
bool equal(double x,double y){
	return fabs(x-y)<eps;
}
int main(){
	memset(dp,-1,sizeof(dp));
	long long l=1,r=1;
	double u;scanf("%lf",&u);
	for(int i=0;i<=18;i++){
		long long ans=-1;
		while(l<r){
			long long mid=(l+r)>>1;
			long long x=check(mid);
			double u1=1.0*x/mid;
			if(u1>u||equal(u1,u)){
				ans=mid;r=mid-1;
			}
			else l=mid+1;
		}
		if(ans!=-1){
			printf("%lld",ans);return 0;
		}
		if(i<18) r*=10;
	}
	printf("%lf",0);
	return 0;
}
~~~
## 斜率优化
~~~ c++
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=1000007;
int ql=1,qr=0,q[maxn];
ll sum[maxn],dp[maxn];
ll gety(int x){
	return -dp[x]-sum[x]*sum[x];
}
ll getx(int x){
	return sum[x];
}
bool check_k(int a,int b,int x){
	if(gety(b)-gety(a)>=x*(getx(b)-getx(a))) return true;
	else return false;
}
bool check_poly(int a,int b,int c){
	if((gety(c)-gety(b))*(getx(b)-getx(a))>=(gety(b)-gety(a))*(getx(c)-getx(b))) return true;
	else return false;
}
//dp[i]=dp[k]+(sum[i]-sum[k])^2+m
//y=kx+b --> b=sum[i]^2+m-dp[i] k=-2*sum[i] x=sum[k] y=-dp[k]-sum[k]^2 b --> max 
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		ql=1,qr=0;
		q[++qr]=0;
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);sum[i]=sum[i-1]+x;
			while(ql<qr&&check_k(q[ql],q[ql+1],-2*sum[i])) ql++;
			dp[i]=dp[q[ql]]+(sum[i]-sum[q[ql]])*(sum[i]-sum[q[ql]])+m;
			while(ql<qr&&check_poly(q[qr-1],q[qr],i)) qr--;
			q[++qr]=i;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
~~~
## 斜率优化+凸包上二分
~~~ c++
#include <stdio.h>
#include <algorithm>
#include <iostream>
#define make_pair mp
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int maxn=100007;
const int inf=(1LL<<29);
int a[maxn],sum[maxn],q[maxn],ql,qr;
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
        ql=1,qr=0;
        double tot=-1e9;
        for(int i=m;i<=n;i++){
            while(ql<qr&&1LL*(sum[q[qr]]-sum[q[qr-1]])*(i-m-q[qr])>=1LL*(sum[i-m]-sum[q[qr]])*(q[qr]-q[qr-1])) qr--;
            q[++qr]=i-m;
            int l=ql,r=qr,ans=0;
            while(l<=r){
                int mid=(l+r)>>1;
                if(mid==qr||1LL*(sum[q[mid+1]]-sum[q[mid]])*(i-q[mid+1])>=1LL*(sum[i]-sum[q[mid+1]])*(q[mid+1]-q[mid])){
                    r=mid-1;ans=mid;
                }
                else l=mid+1;
            }
            tot=max(tot,1.0*(sum[i]-sum[q[ans]])/(i-q[ans]));
        }
        printf("%d\n",(int)(tot*1000.0));
    }
    return 0;
}
~~~