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
char s[1007];
int prex[1007],prel[1007];
int main(){
    int t=read();
    while(t--){
        scanf("%s",s+1);
        int len=strlen(s+1);
        int totx=0,totl=0;
        rep(i,1,len){
            totx+=s[i]=='x';
            totl+=s[i]=='l';
            prex[i]=prex[i-1]+(s[i]=='x');
            prel[i]=prel[i-1]+(s[i]=='l');
        }
        int ans=0;
        if(totx<=2){
            printf("0\n");continue;
        }
        ans=totx-2;
        rep(i,1,len){
            if(prex[i]>=3&&s[i]=='x'){
                ans=min(ans,prex[i]-3+max(0,prel[len]-prel[i]-1));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}