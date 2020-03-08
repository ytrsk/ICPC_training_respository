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
int num[maxn],a[maxn];
int powm(int a,ll b,int c){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%c;
        a=(1LL*a*a)%c;
        b>>=1;
    }
    return ans;
}
int main(){
    int ans=1,n=read(),m=read();
    for(int i=1;i<=n;i++){
        int x=read();num[x%m]++;a[i]=x;
        if(num[x%m]>=2) ans=0;
    }
    if(n>m||!ans) printf("0");
    else{
        for(int i=1;i<=n;i++){
            for(int k=i+1;k<=n;k++){
                (ans*=(abs(a[i]-a[k])%m))%=m;
            }
        }
        cout<<ans;
    }
    return 0;
}