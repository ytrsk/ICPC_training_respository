#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
typedef unsigned long long ull;
ull ran(){
	static ull x=233;
	x^=x<<13;
	x^=x>>7;
	x^=x<<17;
	return x;
}
ull a=0;
map<ull,int> aa;
ll dp[maxn];
int main(){
    freopen("file1.in","r",stdin);
    dp[1]=1;
    for(ll i=2;i<=3000;++i){
        int x=read(),y=read(),z=read();
        dp[i]=dp[y]+dp[z];
    }
    cout<<dp[3000];
    return 0;
}
