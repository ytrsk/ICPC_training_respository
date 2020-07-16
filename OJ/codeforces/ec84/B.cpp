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
int a[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) a[i]=0;
        int pos=0;
        for(int i=1;i<=n;i++){
            int x=read();vector<int> g;
            while(x--){
                int u=read();g.push_back(u);
            }
            int ok=0;
            for(auto x:g){
                if(!a[x]){
                    a[x]=1;ok=1;break;
                }
            }
            if(!ok) pos=i;
        }
        if(!pos) printf("OPTIMAL\n");
        else{
            int x=0;
            for(int i=1;i<=n;i++) if(!a[i]) x=i;
            printf("IMPROVE\n");
            printf("%d %d\n",pos,x);
        }
    }
    return 0;
}