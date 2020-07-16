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
ll a[maxn];
int you[101];
int main(){
    int t=read();
    while(t--){
        memset(you,0,sizeof(you));
        int n=read(),m=read(),ok=1;
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++){
            for(int k=0;k<=63;k++){
                if(!a[i]) break;
                if(a[i]%m>1) ok=0;
                else if(a[i]%m==1){
                    if(you[k]) ok=0;
                    you[k]++;
                }
                a[i]/=m;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}