#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
string s[maxn];
ull base[maxn*10];
map<ull,int> aa;
char S[maxn*10];
int fail[maxn*10];
int val[maxn*10];
int main(){
    int n=read();
    base[0]=1;
    for(int i=1;i<=1000000;i++) base[i]=base[i-1]*27;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        ull now=0,nowB=1;
        for(int k=s[i].length()-1;~k;--k){
            now=now+(s[i][k]-'a'+1)*nowB;
            nowB*=27;
            aa[now]++;
        }
    }
    int ans=0,mod=998244353;
    for(int i=1;i<=n;i++){
        ull now=0;
        int len=s[i].length();
        for(int k=0;k<len;k++){
            now=now*27+s[i][k]-'a'+1;
            S[k+1]=s[i][k];
            val[k+1]=aa[now];
        }
        int last=0;
        (ans+=val[1])%=998244353;
        for(int i=2;i<=len;i++){
		    while(last&&S[last+1]!=S[i]) last=fail[last];
		    if(S[last+1]==S[i]) last++;
		    fail[i]=last;
            (ans+=(1LL*val[i]*i%mod*i%mod-1LL*val[i]*fail[i]*fail[i]%mod+mod)%mod)%=mod;
	    }
    }
    cout<<ans;
    return 0;
}