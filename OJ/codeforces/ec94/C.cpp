#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[100007];
int ans[100007];
int main(){
    int t=read();
    while(t--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        int x=read();
        fill(ans+1,ans+n+1,1);
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                if(i>=x+1) ans[i-x]=0;
                if(i+x<=n) ans[i+x]=0;
            }
        }
        int ok=1;
        for(int i=1;i<=n;i++){
            int now=(i>=x+1&&ans[i-x]==1)||(i+x<=n&&ans[i+x]==1);
            if(now!=s[i]-'0') ok=0;
        }
        if(!ok) printf("-1\n");
        else{
            for(int i=1;i<=n;i++){
                printf("%d",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}