#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=300007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    int l=0,r=m,ans;
    int now=0;
    while(l<=r){
        int mid=(l+r)>>1;now=0;
        int ok=1;
        for(int i=1;i<=n;i++){
            if(a[i]<now){
                if(now-a[i]>mid) ok=0;
            }
            else if(now+m-a[i]>mid) now=a[i]; 
        }
        if(ok) r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}