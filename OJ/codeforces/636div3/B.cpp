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
int main(){
    int t=read();
    while(t--){
        int n=read();
        if(n%4)cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            ll sum=0;
            for(int i=1;i<=n/2;i++){
                printf("%d ",i*2);sum+=i*2;
            }
            for(int i=1;i<=n/2-1;i++){
                printf("%d ",i*2-1);sum-=i*2-1;
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}