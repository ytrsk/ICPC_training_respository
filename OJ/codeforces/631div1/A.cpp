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
int a[maxn];
int id[maxn],ans[maxn];
bool cmp(int x,int y){
    return a[x]>a[y];
}
int delta[maxn];
int main(){
    int n=read(),m=read();int now=0;
    ll sum=0;
    for(int i=1;i<=m;i++) a[i]=read(),sum+=a[i];
    int x=inf,ok=1;

    for(int i=m;i;i--){
        if(i==m){
            now=n-a[i]+1,ans[i]=now;
        }
        else{
            if(now>1){
                ans[i]=min(n-a[i]+1,now-1);now=ans[i];delta[i]=ans[i+1]-ans[i];
            }
            else ok=0;
        }
    }
    x=now-1;
    if(sum>=n&&ok){
        for(int i=m;i>1;i--){
            int y=ans[i]-delta[i-1]-max(ans[i]-a[i-1],1);
            ans[i-1]=ans[i]-delta[i-1]-min(x,y);
            x-=min(x,y);
        }
        if(!x) for(int i=1;i<=m;i++) printf("%d ",ans[i]);
        else printf("-1");
    }
    else{
        printf("-1");
    }
    return 0;
}