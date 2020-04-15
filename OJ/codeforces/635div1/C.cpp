#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[3007],t[3006];
vector<int> nex,dp;
const int mod=998244353;
int add(int a,int b){
    return (a+b)%mod;
}
int main(){
    scanf("%s",s+1);
    int ls=strlen(s+1);
    scanf("%s",t+1);
    int lt=strlen(t+1);
    dp.resize(3005);
    for(int i=0;i<=ls;i++) dp[i]=1;
    int ans=0;
    for(int i=1;i<=ls;i++){
        nex.clear();nex.resize(3005);
        for(int k=0;k<=ls;k++){
            if(k+i<=lt&&s[i]==t[k+i]||k+i>lt) nex[k]=add(nex[k],dp[k]);
            if(k&&(k<=lt&&t[k]==s[i]||k>lt)) nex[k-1]=add(nex[k-1],dp[k]);
        }
        for(int k=0;k<=ls;k++){
     //       cout<<i<<" "<<k<<" "<<nex[k]<<endl;
        }
        if(i>=lt) ans=add(ans,nex[0]);
        swap(dp,nex);
    }
    cout<<ans;
    return 0;
}