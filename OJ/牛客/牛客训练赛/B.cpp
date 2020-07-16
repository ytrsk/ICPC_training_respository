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
char s[maxn];
int main(){
    int mx=0;
    scanf("%s",s+1);
    int len=strlen(s+1);
    int ch=s[1]-'0';
        int ans=0,cnt=1;
        for(int k=1;k<=len;k++){
            if(((s[k]-'0')^1)==ch){
                ans++;ch=-1;
            }
            else ch=s[k]-'0';
        }
        cout<<ans;
    return 0;
}