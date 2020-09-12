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
int a[maxn];
int id[maxn];
int cmp(int x,int y){
    if(a[x]!=a[y]) return a[x]<a[y];
    else return x<y;
}
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) id[i]=i,a[i]=read();
        sort(id+1,id+n+1,cmp);
        int ok=1;
        for(int i=1;i<=n;i++){
            if(a[i]%a[id[1]]!=0&&i!=id[i]) ok=0;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}