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
int main(){
    int test=read();
    while(test--){
        int n=read(),m=read();
        int mn=inf;
        for(int i=1;i<=n;i++){
            int a=read(),b=read();
            mn=min(mn,((m-1)/a+1)*b);
        }
        printf("%d\n",mn);
    }
    return 0;
}