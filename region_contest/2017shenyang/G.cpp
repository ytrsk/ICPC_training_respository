#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=150007;
const int inf=1<<29;
const int mod=1e9+7;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
unsigned long long g[maxn][19],now[maxn];
int to[maxn][19],a[maxn];
int id[maxn],n,ha[maxn];
char s[maxn];
inline bool cmp(int x,int y){
    if(a[x]!=a[y]) return a[x]>a[y];
    for(register int i=18;~i;--i) if(g[x][i]==g[y][i]) x=to[x][i],y=to[y][i];
    return a[to[x][0]]>a[to[y][0]];
}
int main(){
    int t=read(),cnt=0;
    while(t--){
        ++cnt;
        n=read();scanf("%s",s+1);for(int i=1;i<=n;i++)
        for(int i=1;i<=n;i++){
            a[i]=s[i]-'0';
            int x=i-1;
            int v=(1LL*x*x+1)%n+1;
            to[i][0]=v;g[i][0]=a[v]+1;
        }
        now[0]=11;
        for(int i=1;i<=18;i++) now[i]=1LL*now[i-1]*now[i-1];
        for(int i=1;i<=18;i++)
            for(int k=1;k<=n;k++)
            to[k][i]=to[to[k][i-1]][i-1],
            g[k][i]=g[k][i-1]*now[i-1]+g[to[k][i-1]][i-1];
        for(int i=1;i<=n;i++) id[i]=i;
        nth_element(id+1,id+1,id+n+1,cmp);
        printf("Case #%d: ",cnt);
        int z=n,rr=id[1];
        while(z--){
            printf("%d",a[rr]);
            rr=to[rr][0];
        }
        printf("\n");

    }
    return 0;
}
