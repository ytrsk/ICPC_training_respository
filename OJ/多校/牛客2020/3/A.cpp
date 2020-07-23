#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=2000007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[maxn];
int sub[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        scanf("%s",s+1);
        int ans=0,mx=0;
        sub[n+1]=0;
        for(int i=1;i<=n;i++) sub[i]=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='3'||s[i]=='2') ans++;
            else sub[i]++;
        }
        int now=0;
        for(int i=n;i;i--) sub[i]+=sub[i+1];
        int Ans=ans;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'){
                now++;
                mx=max(mx,min(now,sub[i+1])+Ans);
            }
            else if(s[i]=='0'){
                if(now) now--,Ans++;
            }
        }
        printf("%d\n",max(mx,Ans));
    }
    return 0;
}