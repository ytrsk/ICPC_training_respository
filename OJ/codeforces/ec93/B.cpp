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
char s[107];
int top,q[maxn];
int main(){
    int t=read();
    while(t--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        int cnt=0,now=1,ans=0;top=0;
        rep(i,1,n){
            if(s[i]=='1'){
                cnt++;
                if(i==n||s[i+1]!='1') {
                    if(now) q[++top]=cnt;
                    cnt=0;
                }
            }
        }
        sort(q+1,q+top+1);
        reverse(q+1,q+top+1);
        rep(i,1,top) if(i%2) ans+=q[i];
        printf("%d\n",ans);
    }
    return 0;
}