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
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int a,b,c;cin>>a>>b>>c;
    int st=max(0,c-b);
    int ed=min(c,a);
    cout<<ed-st+1;
    return 0;
}
