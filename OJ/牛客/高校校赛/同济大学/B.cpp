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
pii read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    if(ch=='+') return mp(x,1);
    else if(ch=='d')return mp(x,2);
    else return mp(x,0);
}
char s[10007];
int main(){
    double ans=0;
    while(1){
        pii X=read();
        if(X.second==2){
            pii Y=read();        
            ans+=1.0*X.first*(1.0+Y.first)/2;
            if(!Y.second) break;
        }
        else if(X.second==1){
            ans+=X.first;
        }
        else{
            ans+=X.first;break;
        }
    }
    ll now=ans+0.0001;
    if(fabs(ans-now)<1e-5) printf("%lld",now);
    else printf("%.1lf",ans);
    return 0;
}