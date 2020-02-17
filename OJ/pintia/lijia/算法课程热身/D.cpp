#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
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
char s[200007];
int main(){
    cin>>s+2;
    s[1]='+';
    int len=strlen(s+1);
    int now=0,t=2,z=0;
    for(int i=1;i<len-1;i=t,t=i+1){
        int pos=0;
        for(;s[t]>='0'&&s[t]<='9'&&t<len;++t) pos=pos*10+s[t]-'0';
        if(s[i]=='+') now+=pos;
        else if(s[i]=='-') now-=pos;
        else if(s[i]=='*') now*=pos;
        else if(s[i]=='/'){
            if(pos==0) z=1;
            else now/=pos;
        }
        else if(s[i]!='='&&s[i]!=' '){
            z=1;
        }
    }
    if(!z) cout<<now;
    else cout<<"ERROR";
    return 0;
}