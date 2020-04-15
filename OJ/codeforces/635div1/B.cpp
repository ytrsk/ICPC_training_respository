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
ll a[maxn],b[maxn],c[maxn];
ll calc(ll x,ll y,ll z){
    return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
}      
ll ans=0x7f7f7f7f7f7f7f7f;
void ope(ll *a,ll *b,ll *c,int n1,int n2,int n3,int i){
    int b1=lower_bound(b+1,b+n2+1,a[i])-b;
    int b2=upper_bound(b+1,b+n2+1,a[i])-b-1;
    if(b1!=n2+1){
        int c1=lower_bound(c+1,c+n3+1,(a[i]+b[b1])/2)-c;
        int c2=upper_bound(c+1,c+n3+1,(a[i]+b[b1])/2)-c-1;
        if(c1!=n3+1){
            ans=min(ans,calc(a[i],b[b1],c[c1]));
        }
        if(c2){
            ans=min(ans,calc(a[i],b[b1],c[c2]));
        }
    }
    if(b2){
        int c1=lower_bound(c+1,c+n3+1,(a[i]+b[b2])/2)-c;
        int c2=upper_bound(c+1,c+n3+1,(a[i]+b[b2])/2)-c-1;
        if(c1!=n3+1){
            ans=min(ans,calc(a[i],b[b2],c[c1]));
        }
        if(c2){
            ans=min(ans,calc(a[i],b[b2],c[c2]));
        }
    }
}
int main(){
    int t=read();
    while(t--){
        int n1=read(),n2=read(),n3=read();
        for(int i=1;i<=n1;i++) a[i]=read();
        for(int i=1;i<=n2;i++) b[i]=read();
        for(int i=1;i<=n3;i++) c[i]=read();
        sort(a+1,a+n1+1);
        sort(b+1,b+n2+1);
        sort(c+1,c+n3+1);            
        ans=0x7f7f7f7f7f7f7f7f;
        for(int i=1;i<=n1;i++){
            ope(a,b,c,n1,n2,n3,i);
            ope(a,c,b,n1,n3,n2,i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}