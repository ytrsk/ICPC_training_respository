#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
bool check(int n,int m){
    double x=1;
    for(int i=n;i>=n-m+1;i--) x=x*(1.0*i/n);
    return x<=0.5;
}
int main(){
    int n=read(),cnt=0;
    while(n--){
        int x=read();
        int ans=0;
        for(int i=1;i<=x;i++) if(!check(x,i)){
            ans=i;
        }
        else break;
        printf("Case %d: %d\n",++cnt,ans);
    }
    return 0;
}
