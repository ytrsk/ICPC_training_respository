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
int you[maxn],a[maxn];
int main(){
    int n,m,mod;
    while(scanf("%d%d%d",&n,&m,&mod)==3){
        int ans=1;
        for(int i=1;i<=m;i++) you[i]=0;
        for(int i=1;i<=n;i++){
            you[1]++;
            you[(a[i]=read())+1]--;
        }
        for(int i=1;i<=m;i++) you[i]+=you[i-1];
        sort(you+1,you+m+1);
        sort(a+1,a+n+1);
        for(int i=1;i<m;i++) ans=1LL*ans*you[i]%mod;
        for(int i=1;i<n;i++) ans=1LL*ans*a[i]%mod;
        printf("%d\n",ans);
    }
    return 0;
}