#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll a[107][107],b[107];
int main(){
    int t=read();
    int cnt=0;
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++){
            a[i][k]=read();
        }
        ll sum=0;
        for(int i=1;i<=n;i++) sum+=a[i][i];
        int r=0,c=0;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++) b[k]=a[i][k];
            sort(b+1,b+n+1);
            int len=unique(b+1,b+n+1)-b-1;
            if(len!=n) r++;
        }
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++) b[k]=a[k][i];
            sort(b+1,b+n+1);
            int len=unique(b+1,b+n+1)-b-1;
            if(len!=n) c++;
        }
        printf("Case #%d: %lld %d %d\n",++cnt,sum,r,c);
    }
    return 0;
}