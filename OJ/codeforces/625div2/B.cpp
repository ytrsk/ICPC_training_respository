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
long long b[1000007];
int main(){
    int n=read(),mx=0;
    for(int i=1;i<=n;i++){
        int x=read();b[x+n-i]+=x;mx=max(mx,x+n-i);
    }
    sort(b+1,b+mx+1);
    cout<<b[mx];
    return 0;
}