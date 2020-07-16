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
char s[107],s1[107];
char pre[107];
int vis[107];
int main(){
    int n=read();
    cin>>s+1;
    int len=strlen(s+1);
    for(char ch='z';ch>='a';ch--){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=len;i++){
            if(s[i]==ch){
                if(vis[i-1]) vis[i]=1;
                if(i>1&&s[i-1]==ch-1||i<len&&s[i+1]==ch-1) vis[i]=1;
            }
        }
        for(int i=len-1;i;i--) if(s[i]==ch&&vis[i+1]) vis[i]=1;
        int top=0;
        for(int i=1;i<=len;i++) if(!vis[i]) s1[++top]=s[i];
        for(int i=1;i<=top;i++) s[i]=s1[i];
        len=top;
    }
    cout<<n-len;
    return 0;
}