#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[maxn];
int num[maxn],tag[maxn],top;
int calc(char  x){
    return x=='L'?0:1;
}
int main(){
    int t=read();
    while(t--){
        int n=read();
        scanf("%s",s+1);
        int now=0;top=0;
        for(int i=1;i<=n;i++){
            ++now;
            if(i==n||s[i]!=s[i+1]){
                num[++top]=now;tag[top]=calc(s[i]);
                now=0;
            }
        }
        if(top>1){
            if(tag[1]==tag[top]){
                num[1]+=num[top];top--;
            }
            int ans=0;
            for(int i=1;i<=top;i++){
                if(num[i]>=3){
                    ans+=(num[i]-3)/3+1;
                }
            }
            printf("%d\n",ans);
        }
        else{
            printf("%d\n",(num[1]-1)/3+1);
        }
    }
    return 0;
}