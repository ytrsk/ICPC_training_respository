#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int a[maxn],pos[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i;
        int mn=n+1,mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,pos[i]);mn=min(mn,pos[i]);
            if(mx-mn+1==i) printf("1");
            else printf("0"); 
        }
        printf("\n");
    }
    return 0;
}