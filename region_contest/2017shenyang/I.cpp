#include <bits/stdc++.h>
#define mp make_pair
#define __int128 long long
using namespace std;
typedef pair<int,int> pii;
const int maxn=100007;
const int inf=1<<29;
__int128 read(){
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;

}
int q[70],top=0;
__int128 a,b,c,d;
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);
    int t=read();
    while(t--){
        a=read(),b=read(),c=read(),d=read();
        __int128 x=a+b+c+d;
        if(!x) printf("0\n");
        else{
            top=0;
            while(x){
                q[++top]=x%10;
                x/=10;
            }
            for(int i=top;i;i--){
                printf("%d",q[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
