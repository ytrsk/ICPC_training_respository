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
int a[maxn],b[maxn],vis[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    int pos=0;
    int ans=inf;
    for(int i=1;i<=n;i++){
        if(b[i]==1) pos=i;
    }
    if(pos){
        int ok=1;
        for(int i=pos;i<=n;i++){
            if(b[i]!=i-pos+1) ok=0;
        }
        if(ok){
            for(int i=1;i<=n;i++) vis[a[i]]=1;
            int mx=n-pos+1;
            for(int i=n-pos+1+1;i<=n;i++){
                if(vis[i]) mx++;
                vis[b[i-(n-pos+1)]]=1;
            }
            if(mx==n) ans=pos-1;
        }
    }
    int l=n,r=2*n;
    while(l<=r){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) vis[a[i]]=1;
        int mid=(l+r)>>1;
        for(int i=1;i<=mid-n;i++) vis[b[i]]=1;
        int ok=1;
        for(int i=1;i<=n;i++){
            if(!vis[i]) ok=0;
            if(mid-n+i<=n) vis[b[mid-n+i]]=1;
        }
        if(ok) r=mid-1,ans=min(ans,mid);
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}