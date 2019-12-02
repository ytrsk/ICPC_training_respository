#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
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
    int t=read();
    while(t--){
        int a=read(),b=read(),c=read();
        int r=max(a,max(b,c));
        if(r>=a+b+c-r){
            cout<<a+b+c-r<<"\n";
        }
        else cout<<(a+b+c)/2<<"\n";
    }
    return 0;
}