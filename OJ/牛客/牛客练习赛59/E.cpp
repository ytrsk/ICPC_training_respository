#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int pre[maxn],a[maxn];
typedef pair<ll,pii> tu;
ll calc(int x,int y){
    if(x%y==0) return 1LL*(x/y)*(x/y)*y;
    else return 1LL*(x%y)*(x/y+1)*(x/y+1)+1LL*(y-x%y)*(x/y)*(x/y);
}
ll solve(int x,int y){
    return calc(x,y)-calc(x,y+1);
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    int q=read();
    for(int i=1;i<=q;i++){
       // for(int k=1;k<=n;k++) a[k]=pre[k];
        int x=read(),v=read();a[x]=v;
        priority_queue<tu> q;
        for(int k=1;k<=n;k++){
            q.push({solve(a[k],1),mp(a[k],1)});
        }
        int now=m-n;
        while(now>0){
            now--;
            tu zz=q.top();q.pop();
            int two=zz.second.first,th=zz.second.second+1;
            q.push({solve(two,th),mp(two,th)});
        }
        ll ans=0;
        while(!q.empty()){
            tu zz=q.top();q.pop();
            ans+=calc(zz.second.first,zz.second.second);
        }
        printf("%lld\n",ans);
    }
    return 0;
}