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
int a[maxn],n,K;
void print(){
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
}
int vis[maxn];
int main(){
    n=read(),K=read();
    if(K==0){
        if(n%2==0) printf("-1");
        else{
            for(int i=1;i<=(n-1)/2;i++){
                a[i*2-1]=i;
                a[i*2]=n-i;
            }
            a[n]=n;
            print();
        }
    }
    else{
        if(n*(n+1)/2%n!=K) printf("-1");
        else{
            a[n]=n;a[n-1]=K;
            if(n-K==K){
                vis[n]=vis[K]=1;vis[n-K]=1;
                int cnt=0;
                for(int i=1;i<=n;i++){
                    if(!vis[i]&&!vis[n-i]){
                        a[++cnt]=i;a[++cnt]=n-i;
                        vis[i]=vis[n-i]=1;
                    }
                }
                print();
            }
            else printf("-1");
        }
    }
    return 0;
}