#include <bits/stdc++.h>
#include <ext/rope>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
using namespace __gnu_cxx;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[2000007];
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    int q=read();
    int now=0;
    while(q--){
        char S[10];scanf("%s",S+1);
        if(S[1]=='M'){
            now=(now+read()+len)%len;
        }
        else{
            int x=read();
            if(now>=0){
                if(x<=len-now) printf("%c\n",s[x+now]);
                else printf("%c\n",s[x-(len-now)]);
            }
            else{
                int b=abs(now);
                if(x<=b) printf("%c\n",s[len-b+x]);
                else printf("%c\n",s[x-b]);
            }
        }
    }
    return 0;
}