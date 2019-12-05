#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
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
char s[maxn];
int new_node(int x){
    ++e1;
    memset(tr[e1],0,sizeof(tr[e1]));L[e1]=x;
    return e1;
}
int val[maxn];
void ins(int c,int n){
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
    LL[n]=L[las];
}
int na[maxn],nb[maxn];
void count(){
    for(int i=e1;i>1;i--) sz[fail[i]]+=sz[i],na[fail[i]]+=na[i],nb[fail[i]]+=nb[i];
}
//该算法必须保证S[0]不等于字符串中的任何字符
char A[maxn],B[maxn];
int main(){
    int cnt=0;
    int T=read();
    while(T--){
        scanf("%s%s",A+1,B+1);
        int la=strlen(A+1),lb=strlen(B+1);
        init();
        strcpy(s+1,A+1);
        for(int i=1;i<=la;i++) ins(A[i]-'a',i);
        las=0;
        strcpy(s+1,B+1);
        for(int i=1;i<=lb;i++) ins(B[i]-'a',i);
        int now=0;
        for(int i=1;i<=e1;i++) na[i]=nb[i]=0;
        int nowA=0,nowB=0;
        for(int i=1;i<=la;i++){
            int ch=A[i]-'a';
            nowA=max(nowA,1);
            while(A[i-L[nowA]-1]!=A[i]) nowA=fail[nowA];
            if(tr[nowA][ch]) nowA=tr[nowA][ch];
            na[nowA]++;
        }
        for(int i=1;i<=lb;i++){
            int ch=B[i]-'a';
            nowB=max(nowB,1);
            while(B[i-L[nowB]-1]!=B[i]) nowB=fail[nowB];
            if(tr[nowB][ch]) nowB=tr[nowB][ch];
            nb[nowB]++;
        }
        count();
        ll ans=0;
        for(int i=2;i<=e1;i++){
            //cout<<na[i]<<" "<<nb[i]<<"\n";
            ans+=1LL*na[i]*nb[i];
        }
        printf("Case #%d: %lld\n",++cnt,ans);
    }
    return 0;
}
