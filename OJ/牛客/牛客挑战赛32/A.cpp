#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
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
char s[maxn];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n=read();
    for(int i=1;i<=n;i++){
        cin>>s+1;
        int len=strlen(s+1);
        if(len>=2&&s[len]=='K'&&s[len-1]=='A'){
            for(int k=1;k<=len-2;k++) printf("%c",s[k]);
            return 0;
        }
    }
    return 0;
}
