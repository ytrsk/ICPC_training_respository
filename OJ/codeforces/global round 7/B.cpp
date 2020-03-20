#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int b[maxn],a[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) b[i]=read();
    int mx=0;
    for(int i=1;i<=n;i++){
        
            a[i]=b[i]+mx;
        
        mx=max(mx,a[i]);
        printf("%d ",a[i]);
    }
    //printf("")
    return 0;
}