#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],b[maxn];
int main(){
    int n=read(),m=read(),p=read(),pa=0,pb=0;
    for(int i=1;i<=n;i++) a[i]=read()%p,pa=a[i]?i-1:pa;
    for(int i=1;i<=m;i++) b[i]=read()%p,pb=b[i]?i-1:pb;
    cout<<pa+pb;
    return 0;
}