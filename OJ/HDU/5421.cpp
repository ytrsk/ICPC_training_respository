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
ll ans;
struct Pam{
    int tr[maxn][27];
    int fail[maxn],L[maxn],e1,LL[maxn];
    void init(){
        ans=0;
        L[0]=0;fail[0]=1;L[1]=-1;fail[1]=0;e1=1;
        memset(tr[0],0,sizeof(tr[0]));
        memset(tr[1],0,sizeof(tr[1]));
    }
    int new_node(int x){
        ++e1;
        memset(tr[e1],0,sizeof(tr[e1]));L[e1]=x;
        return e1;
    }
    void ins(char *s,int c,int n,int &las){
        int u=las;
        while(s[n-L[u]-1]!=s[n]) u=fail[u];
        if(!tr[u][c]){
            int now=new_node(L[u]+2);
            int v=fail[u];
            while(s[n-L[v]-1]!=s[n]) v=fail[v];
            fail[now]=tr[v][c];
            tr[u][c]=now;
            LL[now]=LL[fail[now]]+1;
        }
        las=tr[u][c];ans+=LL[las];
    }
}pam;
//该算法必须保证S[0]不等于字符串中的任何字符
char A[maxn],B[maxn];
int main(){
    int cnt=0;
    int T;
    while(scanf("%d",&T)==1){
        pam.init();int la=0,lb=0,lasa=0,lasb=0;
        while(T--){
            int opt=read();
            if(opt==1){
                char S[13];scanf("%s",S+1);
                A[100005+(++la)]=S[1];
                B[100005-la+1]=S[1];
                pam.ins(A,S[1]-'a',100005+la,lasa);
                if(pam.L[lasa]==la+lb) lasb=lasa;
            }
            else if(opt==2){
                char S[13];scanf("%s",S+1);
                B[100005+(++lb)]=S[1];
                A[100005-lb+1]=S[1];
                pam.ins(B,S[1]-'a',100005+lb,lasb);
                if(pam.L[lasb]==la+lb) lasa=lasb;
            }
            else if(opt==3){
                printf("%d\n",pam.e1-1);
            }
            else {
                printf("%lld\n",ans);
            }
        }
        for(int i=100005-la+1;i<=100005+lb;i++) B[i]='0';
        for(int i=100005-lb+1;i<=100005+la;i++) A[i]='0';
    }
    return 0;
}
