#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
char s[maxn];
int main(){
    int t=read();
    while(t--){
        scanf("%s",s+1);
        int len=strlen(s+1);
        for(int i=1;i<=len;i++){
            if(s[i]=='?') {
                for(char k='a';k<='c';k++){
                    if(k!=s[i-1]&&k!=s[i+1]){
                        s[i]=k;break;
                    }
                }
            } 
        }
        int ok=0;
        for(int i=1;i<len;i++) if(s[i]==s[i+1]) ok=1;
        if(ok) cout<<-1<<"\n";
        else printf("%s\n",s+1);
    }
    return 0;
}