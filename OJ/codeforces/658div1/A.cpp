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
char s[maxn],S[maxn];
int q[maxn<<1];
int main(){
    int t=read();
    while(t--){
        int n=read();
        scanf("%s",s+1);
        scanf("%s",S+1);
        int len=strlen(s+1);
        int rev=0,tag=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            int x=(i%2==0)?n-(i/2)+1:i/2+1; 
            rev^=1;
            int c=(s[x]-'0')^rev;
            if(c^(S[n-i+1]-'0')) q[++cnt]=1;
            q[++cnt]=n-i+1;
        }
        printf("%d ",cnt);
        for(int i=1;i<=cnt;i++) printf("%d ",q[i]);
        printf("\n");
    }
    return 0;
}