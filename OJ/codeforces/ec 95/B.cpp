#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],lo[maxn];
int top,q[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();top=0;
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++){
            lo[i]=read();
            if(!lo[i]){
                q[++top]=a[i];
            }
        }
        sort(q+1,q+top+1);
        for(int i=1;i<=n;i++){
            if(!lo[i]){
                a[i]=q[top--];
            }
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}