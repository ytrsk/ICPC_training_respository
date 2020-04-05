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
    int x=read();
    int len=sqrt(x+0.5);
    for(int i=2;i<=len;i++){
        if(x%i==0) {while(x%i==0) x/=i,printf("%d",i);}
    }
    if(x-1>1) printf("%d",x);
    return 0;
}