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
    int t=read();
    while(t--){
        int n=read();
        int lx=0,ly=0,ok=1;
        for(int i=1;i<=n;i++){
            int x=read(),y=read();
            if(x<lx||y<ly||x-lx<y-ly) ok=0;
            lx=x;ly=y; 
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}