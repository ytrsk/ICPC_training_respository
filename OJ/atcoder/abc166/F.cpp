#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[10];
char s[10];
int tag[maxn];vector<int> g;
int main(){
    int n=read(),ok=1;
    rep(i,0,2) a[i]=read();
    rep(i,1,n){
        char s[10];
        scanf("%s",s+1);
        if(s[1]=='A'){
            tag[i]=s[2]=='B'?2:0;
        }
        else tag[i]=1;
        int x,y;
        if(tag[i]==0) x=0,y=2;
        else if(tag[i]==1) x=1,y=2;
        else x=0,y=1;
        if(!a[x]&&!a[y]) ok=0;
        else{
            int now=a[x]<a[y]?x:y;
            a[now]++;a[x+y-now]--;
            g.push_back(now);
        }
    }
    if(!ok){
        printf("No");return 0;
    }
    else printf("Yes\n");
    for(auto i:g) printf("%c\n",'A'+i);
    return 0;
}