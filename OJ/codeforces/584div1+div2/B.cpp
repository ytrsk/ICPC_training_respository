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
int a[maxn],b[maxn];
int now[maxn],n;
char s[maxn];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    cin>>n>>s+1;
    int mx=0;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i],now[i]=s[i]-'0';
    for(int i=0;i<=10000;i++){
        int ans=0;
        for(int k=1;k<=n;k++){
            if(i>=b[k]&&(i-b[k])%a[k]==0) now[k]^=1;
            ans+=now[k];
        }
        mx=max(mx,ans);
    }
    cout<<mx;
    return 0;
}
