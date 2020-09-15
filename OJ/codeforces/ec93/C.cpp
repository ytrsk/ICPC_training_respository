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
map<ll,int> aa;
char s[maxn];
int main(){
    int t=read();
    while(t--){
        ll ans=0,sum=0;
        int n=read();aa.clear();
        aa[0]=1;scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            sum+=s[i]-'0';
            ans+=aa[sum-i];
            aa[sum-i]++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}