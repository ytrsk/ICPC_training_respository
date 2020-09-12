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
int query(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int a;scanf("%d",&a);return a;
}
int A[maxn],y[maxn];
int main(){
    int n=read(),now=1;
    for(int i=2;i<=n;i++){
        int a=query(i,now),b=query(now,i);
        if(a>b){
            A[i]=a;y[a]=1;
        }
        else{
            A[now]=b;now=i;y[b]=1;
        }
    }
    int lef=0;
    for(int i=1;i<=n;i++) if(!y[i]) lef=i;
    for(int i=1;i<=n;i++) if(!A[i]) A[i]=lef;
    printf("!");
    for(int i=1;i<=n;i++) printf(" %d",A[i]);
    return 0;
}