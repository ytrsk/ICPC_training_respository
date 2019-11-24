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
int gcd(int a,int b){
    return !b?a:gcd(b,a%b);
}
int main(){
  //  cin.tie(0);ios_base::sync_with_stdio(false);
    int n,a,b;cin>>n>>a>>b;
    b*=5;
    int x=gcd(a,b);
    if(n>a*b){
        cout<<n%x;
    }
    else{
        int ans=n;
        for(int i=0;i<=100;i++)
        for(int k=0;k<=100;k++){
            if(a*i+b*k<=n) ans=min(ans,n-a*i-b*k);
        }
        cout<<ans;
    }
    return 0;
}
