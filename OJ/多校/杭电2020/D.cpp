#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=300007;
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
    L[0]=0;fail[0]=1;L[1]=-1;fail[1]=0;e1=1;las=0;sz[1]=0;
    memset(tr[0],0,sizeof(tr[0]));
    memset(tr[1],0,sizeof(tr[1]));
}
char s[maxn];
int new_node(int x){
    ++e1;sz[e1]=0;
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
ll ans=0;
void count(){
    for(int i=e1;i>1;i--) sz[fail[i]]+=sz[i],ans+=sz[i];
}
int mn=inf,cnt=0,fi=1;
void dfs(int o,int len){
    if(o==len+1){
        init();
        for(int i=1;i<=len;i++) ins(s[i]-'a',i);
        ans=0;
        count();
     //   cout<<ans<<endl;
      //  cout<<ans<<endl;
        if(ans<mn) mn=ans,cnt=1;
        else if(ans==mn) cnt++;
        return;
    }
    for(int i=0;i<26;i++){
        s[o]='a'+i;
        dfs(o+1,len);
    }
}
//该算法必须保证S[0]不等于字符串中的任何字符
int main(){
    mn=inf;cnt=0;dfs(1,2);cout<<cnt<<endl;
    mn=inf;cnt=0;dfs(1,3);cout<<cnt<<endl;
    mn=inf;cnt=0;dfs(1,4);cout<<cnt<<endl;
    mn=inf;cnt=0;dfs(1,5);cout<<cnt<<endl;
    return 0;
}
