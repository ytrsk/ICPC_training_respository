#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=300007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[300007];
int val[maxn];
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++) val[i]=0;
    for(int i=1;i<=len;i++){
        for(int k=1;k<=10;k++){
            if(i-k>=1&&i+k<=len){
                if(s[i-k]==s[i+k]&&s[i-k]==s[i]){
                    val[i+k]=max(val[i+k],i-k);
                }
            }
        }
    }
    int now=0;ll ans=0;
    for(int i=1;i<=len;i++){
        now=max(now,val[i]);
        ans+=now;
    }
    cout<<ans;
    return 0;
}