#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=400007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}

int tr[maxn][27];
int fail[maxn],L[maxn],e1,las,LL[maxn],sz[maxn],num[maxn];
void init(){
    L[0]=0;fail[0]=1;L[1]=-1;fail[1]=0;e1=1;las=0;
    memset(tr[0],0,sizeof(tr[0]));
    memset(tr[1],0,sizeof(tr[1]));
}
char s[maxn];int A[maxn],B[maxn];
int new_node(int x){
    ++e1;A[e1]=B[e1]=0;
    memset(tr[e1],0,sizeof(tr[e1]));L[e1]=x;
    return e1;
}
int val[maxn];
void ins(char *s,int c,int n,int opt){
    int u=las;
    while(s[n-L[u]-1]!=s[n]) u=fail[u];
    if(!tr[u][c]){
        int now=new_node(L[u]+2);
        int v=fail[u];
        while(s[n-L[v]-1]!=s[n]) v=fail[v];
        fail[now]=tr[v][c];
        tr[u][c]=now;
    }
    las=tr[u][c];sz[las]++;
    LL[n]=L[las];if(opt) A[las]++;else B[las]++;
}
void count(){
    for(int i=e1;i>1;i--) sz[fail[i]]+=sz[i],A[fail[i]]+=A[i],B[fail[i]]+=B[i];
}
//该算法必须保证S[0]不等于字符串中的任何字符
char sa[maxn],sb[maxn];
int main(){
    int T=read(),cnt=0;
    while(T--){
        scanf("%s%s",sa+1,sb+1);
        int la=strlen(sa+1),lb=strlen(sb+1);
        init();
        for(int i=1;i<=la;i++) ins(sa,sa[i]-'a',i,1);
        las=0;for(int i=1;i<=lb;i++) ins(sb,sb[i]-'a',i,0); 
        int c1=0,c2=0,c3=0;count();
        for(int i=2;i<=e1;i++) if(A[i]>B[i]) c1++;else if(A[i]==B[i]) c2++;else c3++;
        printf("Case #%d: %d %d %d\n",++cnt,c1,c2,c3);
    }
    return 0;
}
