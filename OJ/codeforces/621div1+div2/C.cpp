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
char s[100007];
ll num[26][26];
int pre[100007][26];
int main(){
    cin>>s+1;
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        int ch=s[i]-'a';
        for(int k=0;k<26;k++) num[k][ch]+=pre[i-1][k],pre[i][k]=pre[i-1][k]+(k==ch);
    }
    ll ans=0;
    for(int i=0;i<26;i++)
    for(int k=0;k<26;k++)
    ans=max(max(ans,1LL*pre[len][i]),num[i][k]);
    cout<<ans;
    return 0;
}