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
int cnt=0;
int id[maxn],L[maxn],R[maxn],ans[maxn];
bool cmp(int x,int y){
    if(L[x]==L[y]) return R[x]<R[y];
    return L[x]<L[y];
}
int main(){
    int t=read();
    while(t--){
        printf("Case #%d: ",++cnt);
        int n=read();
        for(int i=1;i<=n;i++) L[i]=read(),R[i]=read(),id[i]=i;
        sort(id+1,id+n+1,cmp);
        int x1=-1,x2=-1,ok=1;
        for(int i=1;i<=n;i++){
            if(L[id[i]]>=x1) x1=R[id[i]],ans[id[i]]=1;
            else if(L[id[i]]>=x2) x2=R[id[i]],ans[id[i]]=2;
            else ok=0;
        }
        if(!ok) printf("IMPOSSIBLE");
        else for(int i=1;i<=n;i++){
            if(ans[i]==1) printf("C");
            else printf("J");
        }
        printf("\n");
    }
    return 0;
}