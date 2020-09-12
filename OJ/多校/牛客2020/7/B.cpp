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
vector<int> g;
void dfs(int n,int m){
    if(n==0||m==0) return;
    if(n<m) swap(n,m);
    for(int i=1;i<=(n/m)*m;i++){
        g.push_back(m);
    }
    dfs(m,n%m);
}
int main(){
    int t=read();
    while(t--){
        int n=read(),m=read();
        if(n<m) swap(n,m);
        int gcd=__gcd(n,m);
        g.clear();
        dfs(n,m);
        printf("%d\n",g.size());
        for(auto v:g) printf("%d ",v);
        printf("\n");
    }
    return 0;
}