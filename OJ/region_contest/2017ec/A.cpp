#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
const int mod=1e9+7;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
void sub(int &x,int y){
    x-=y;
    if(x<0) x+=mod;
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        int n=read(),m=read();
        ++cnt;
        if(m>n){
            printf("Case #%d: 0\n",cnt);continue;
        }
        int sum=1,now=1,ans=pown(2,n);
        for(int i=1;i<m;i++){
            now=1LL*now*(n-i+1)%mod*pown(i,mod-2)%mod;
            add(sum,now);
        }
        sub(ans,sum);
        printf("Case #%d: %d\n",cnt,ans);

    }
    return 0;
}
