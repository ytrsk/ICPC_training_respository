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
        int n=read(),sum=0;
        for(int i=1;i<=n;i++) sum+=read();
        if(sum<=n/2){
            printf("%d\n",n/2);
            for(int i=1;i<=n/2;i++) printf("0 ");
            printf("\n");
        }
        else{
            printf("%d\n",n/2+(n/2)%2);
            for(int i=1;i<=(n/2)+(n/2)%2;i++) printf("1 ");
            printf("\n");
        }
    }
    return 0;
}