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
ll a[maxn],vis[maxn];
int main(){
    ll u=read(),v=read();
    if(u==0&&v==0){
        printf("0\n");return 0;
    }
    for(ll i=0;i<=60;i++){
        if(u>>i&1) v-=1LL<<i,a[1]+=1LL<<i;
    }
    if(v<0){
        printf("-1");
    }
    else{
        if(v==0){
            printf("1\n%lld",u);
        }
        else{
            int ok=0,ok2=0,you=0;
            for(ll i=60;~i;i--){
                if(v>>i&1){
                    if(ok){
                        a[2]+=1LL<<i;vis[i]=1;
                        if(a[1]>>i&1) ok2=1;
                    }
                    else ok=1;
                }
                else{
                    if(ok){
                        a[2]+=1LL<<i;vis[i]=1;
                        if(a[1]>>i&1) ok2=1;
                    }
                    ok=0;
                }
            }
            if(ok){
                printf("-1");
            }
            else if(!ok2){
                for(ll i=60;~i;i--){
                    if(vis[i]) a[1]+=1LL<<i;
                }
                printf("2\n%lld %lld",a[1],a[2]);
            }
            else{
                
                printf("3\n%lld %lld %lld",a[1],a[2],a[2]);
            }
        }
    }
    return 0;
}