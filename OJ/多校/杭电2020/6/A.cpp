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
const int mod=1e9+7;
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int a[maxn];
int pre[maxn];
int mul(int a,int b){
    return 1LL*a*b%mod;
}
int add(int a,int b){
    return a+b>=mod?a+b-mod:a+b;
}
int dec(int a,int b){
    return a-b<0?a-b+mod:a-b;
}
int solve(int a,int b){
    if(a<b) swap(a,b);
    int ans=b+1;
    ans=add(ans,mul(b+1,dec(pre[a+1],pre[b+1])));
    ans=dec(ans,b);
    ans=add(ans,mul(a+b+2,dec(pre[a+b+1],pre[a+1])));
    return ans;
}
int main(){
    for(int i=1;i<=200000;i++) pre[i]=add(pre[i-1],pown(i,mod-2));
    int t=read();
    while(t--){
        int n=read(),ans=0;
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++){
            ans=add(ans,mul(solve(i-1,n-i),a[i]));
        }
        printf("%d\n",mul(ans,pown(add(1LL*n*(n-1)/2%mod,n),mod-2)));
    }
    return 0;
}