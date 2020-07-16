#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        sort(a+1,a+n+1);
        int l=0,r=1e9,ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            int ok=1;
            int mn=0x7f7f7f7f,mx=-0x7f7f7f7f;
            for(int i=1;i<=n;i++){
                if(abs(a[i])>mid){
                    ok=0;mn=min(mn,a[i]);
                    mx=max(mx,a[i]);
                } 
            }
            if(ok||0LL+mx-mid<=0LL+mn+mid) ans=mid,r=mid-1;
            else l=mid+1; 
        }
        printf("%d\n",ans);
    }
    return 0;
}