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
vector<int> g;
int main(){
    int t=read();
    while(t--){
        int n=read(),x=read(),y=read();
        if(x+y<=n+1&&1LL*x*y>=n){
            printf("YES\n");int fi=1;
            int now=n;
            int you=(n+1)-x-y;
            g.clear();
            while(now){
                if(now==n){
                    for(int i=now-y+1;i<=now;i++){
                        g.push_back(i);
                    }
                    now-=y;
                }
                else{
                    int cnt=max(1,min(y,min(now,you+1)));
                    for(int i=now-cnt+1;i<=now;i++){
                        g.push_back(i);
                    }
                    you-=(cnt-1);
                    now-=cnt;
                }
            }
            reverse(g.begin(),g.end());
            fi=1;
            for(auto v:g){
                if(fi) fi=0;
                else printf(" ");
                printf("%d",v);
            }
            printf("\n");
        }
        else printf("NO\n");
    }
    return 0;
}