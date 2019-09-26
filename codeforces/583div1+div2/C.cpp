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
char s[200007];
int len,a[200007];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    cin>>len>>s+1;
    //len=strlen(s+1);
    int x=0;
    for(int i=1;i<=len;i++){
        if(s[i]=='(') a[i]=1;
        else a[i]=-1;
        x+=a[i];
    }
    if(x!=0){
        cout<<"No";
    }
    else{
        int fi=1,x=0,ok=1;
        for(int i=1;i<=len;i++){
            if(a[i]==-1&&fi){
                fi=0;continue;
            }
            x+=a[i];
            if(x<0) ok=0;
        }
        cout<<(ok?"Yes":"No");
    }
    return 0;
}
