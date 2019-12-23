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
char s[107];
int main(){
    int n=read();
    while(n--){
        char s[107];cin>>s+1;
        int len=strlen(s+1),tot=0,ok=0,ok2=0,ok1=0;
        for(int i=1;i<=len;i++){
            int x=s[i]-'0';
            tot+=x;
            if(x==0) ok++;
            else if(x%2==1) ok1=1;
            else ok2=1;
        }
        if(tot%3||!ok||ok==1&&ok1&&!ok2) cout<<"cyan\n";
        else cout<<"red\n";
    }
    return 0;
}