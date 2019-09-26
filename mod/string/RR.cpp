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
int a[30];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    for(int i=1;i<=1000000000;i++,a[1]=i){
    a[1]=-a[1];
    a[1]+=a[1]>>31&998244353;
    if(a[1]!=998244353-i) cout<<i<<" "<<a[1]<<endl;
    }
    return 0;
}
