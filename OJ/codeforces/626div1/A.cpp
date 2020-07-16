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
char s[1000007];
int main(){
    int n=read();
    scanf("%s",s+1);
    int x=0,y=0,now=0,tx=0,ty=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='('){
            if(y) y--,now++;
            else x++;
            tx++;
        }
        else{
            if(x) x--;
            else y++,now++;
            ty++;
        }
    }
    if(tx^ty) cout<<-1;
    else printf("%d",now);
    return 0;
}