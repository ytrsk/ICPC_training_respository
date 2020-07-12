#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],w[maxn];
int you[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        int ok=1;
        for(int i=1;i<=n;i++) a[i]=read(),w[a[i]]=i,you[i]=0;
        int pos=1;
        while(pos<=n){
            if(!you[w[pos]]){
                int x=w[pos];
                while(x<=n&&!you[x]) {you[x]=1;
                if(x!=w[pos]){
                    ok=0;break;
                }
                x++,pos++;}
                if(!ok) break;   
            }
            else{
                ok=0;break;
            }
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}