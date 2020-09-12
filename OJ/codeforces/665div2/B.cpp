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
int ans=0;
void solve(int &x,int &y,int a){
    int now=min(x,y);
    x-=now;y-=now;ans+=a*now;
}
int main(){
    int t=read();
    while(t--){
        ans=0;
        int x0=read(),x1=read(),x2=read();
        int y0=read(),y1=read(),y2=read();
        solve(x2,y1,2);solve(x2,y2,0);
        solve(x1,y1,0);solve(x0,y2,0);solve(x1,y2,-2);
        printf("%d\n",ans);
    }
    return 0;
}