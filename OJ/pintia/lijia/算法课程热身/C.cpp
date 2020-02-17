#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
const int maxn=100007;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[maxn];int len;char Now[maxn];
int ll[maxn],rr[maxn],rt,e1,now;
void dfs(int &u){
    ++now;
    if(now>len||s[now]=='#') return;
    else u=s[now]-'A'+1;
    dfs(ll[u]);dfs(rr[u]);
    if(ll[u]==0&&rr[u]==0) e1++; 
}
void Dfs(int u){
    if(!u) return;
    Dfs(ll[u]);cout<<(char)('A'+u-1);Dfs(rr[u]);
}
int main(){
    cin>>s+1;
    len=strlen(s+1);
    dfs(rt);
    Dfs(rt);cout<<"\n";
    cout<<e1;
    return 0;
}