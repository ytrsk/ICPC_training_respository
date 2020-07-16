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
int a[maxn],b[maxn];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        if(!a[i]&&b[i]) y++;
        else if(a[i]&&!b[i]) x++,y--;
    }
    if(y<0){
        printf("1");
    }
    else{
        y++;
        if(x==0){
            printf("-1");
        }
        else printf("%d",(y-1)/x+1+1);
    }
    return 0;
}