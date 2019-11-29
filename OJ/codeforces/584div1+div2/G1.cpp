#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],now[maxn],nex[maxn],shu[maxn];
int main(){
    int n=read(),q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=n;i;--i){
        nex[i]=now[a[i]];
        now[a[i]]=i;shu[a[i]]++;
    }
    int l=1,r=1,mx=0,ans=0;
    for(int i=1;i<=n;i++){
        if(i==r+1){
            ans+=r-l+1-mx;l=r=i;mx=shu[a[i]];
        }
        mx=max(mx,shu[a[i]]);
        if(nex[i]) r=max(r,nex[i]);
    }
    cout<<ans+r-l+1-mx;
    return 0;
}
