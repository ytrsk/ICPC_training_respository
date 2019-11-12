#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#define mp make_pair
#define pii pair<int,int>
#define lowbit(x) (x)&(-x)
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
const int inf=(1LL<<29);
ll read(){
    ll x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
void add(int o,int l,int r,int x){
    tag[o]=max(tag[o],x);a
}
void pushdown(int o)
void update(int o,int l,int r,int x,int y){



}
int main(){
    //freopen("test.in","r",stdin);
    n=read();int m=read();int top=0;
    for(int i=1;i<=n;i++) a[i]=read(),p[++top]=nd(0,a[i],i,1),pos[a[i]]=i;
    for(int i=1;i<=m;i++){
        int x=read();x=pos[x];
        p[++top]=nd(i,a[x],x,-1);
    }
    sort(p+1,p+top+1);
    cdq(1,top);
    for(int i=1;i<=m;i++) ans[i]=ans[i-1]-ans[i],printf("%lld\n",ans[i-1]);
    return 0;
}
