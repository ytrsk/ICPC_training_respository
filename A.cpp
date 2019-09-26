#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
void write(__int128 x){
    if(x==0){
        printf("0");
    }
    else{
        int q[60],top=0;while(x) q[++top]=x%10,x/=10;
        for(int i=top;i;i--) printf("%d",q[i]);
    }
}
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    __int128 x=0,y=0,z=0,n=read(),r=0,s=0,t=0,you=1,u=0;
    for(int i=1;i<=n;i++){
        int a=read();
        if(a==2) x++;
        else if(a==31) y++;
        else if(a==1847) z++;
        else if(a==2*31) r++;
        else if(a==31*1847) s++;
        else if(a==2*1847) t++;
        else if(a==2*31*1847) u++;
        else if(a==1) you++;
    }
    write(you*(x*y*z+r*z+s*x+t*y+u));
    return 0;
}
