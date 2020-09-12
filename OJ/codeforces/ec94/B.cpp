#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
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
        int ans=0;
        int p=read(),f=read();
        int cnts=read(),cntw=read();
        int s=read(),w=read();
        if(s>w) swap(s,w),swap(cnts,cntw);
        for(int i=0;i<=min(p/s,cnts);i++){
            int x=min(cntw,(p-i*s)/w);
            int y=min(cnts-i,f/s);
            ans=max(ans,x+y+i+min(cntw-x,f/w));
        }
        printf("%d\n",ans);
    }
    return 0;
}