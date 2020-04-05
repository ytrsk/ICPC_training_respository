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
char s[107];
int main(){
    int t=read(),cnt=0;
    while(t--){
        scanf("%s",s+1);
        printf("Case #%d: ",++cnt);
        int len=strlen(s+1),now=0;
        for(int i=1;i<=len;i++){
            int x=s[i]-'0';
            while(now<x){
                now++;printf("(");
            }            
            while(now>x){
                now--;printf(")");
            }
            printf("%d",x);

        }
        while(now) now--,printf(")");
        printf("\n");
    }
    return 0;
}