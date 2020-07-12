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
char s[100007];
int main(){
    int t=read();
    while(t--){
        scanf("%s",s+1);
        int len=strlen(s+1);
        int vis[2];vis[0]=vis[1]=0;
        for(int i=1;i<=len;i++){
            vis[s[i]-'0']=1;
        }
        if(!vis[1]||!vis[0]){
            printf("%s",s+1);
        }
        else{
            for(int i=1;i<=len;i++){
                printf("10");
            }
        }
        printf("\n");
    }
    return 0;
}