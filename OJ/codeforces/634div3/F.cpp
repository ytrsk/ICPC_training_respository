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
char s[10][10];
int main(){
    int t=read();
    while(t--){
        for(int i=1;i<=9;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=9;i++)
        for(int k=1;k<=9;k++)
        if(s[i][k]=='1') s[i][k]='2';
        for(int i=1;i<=9;i++) printf("%s\n",s[i]+1);
    }
    return 0;
}