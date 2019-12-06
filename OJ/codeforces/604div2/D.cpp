#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int main(){
    int a=read(),b=read(),c=read(),d=read();
    if(b>=a&&c>=d){
        b-=a;c-=d;
        if(abs(b-c)<=1){
            printf("YES\n");
            if(b==c){
                for(int i=1;i<=a;i++){
                    printf("0 1 ");      
                }
                for(int i=1;i<=b;i++){
                    printf("2 1 ");
                }
                for(int i=1;i<=d;i++){
                    printf("2 3 ");
                }
            }
            else if(b<c){
                for(int i=1;i<=a;i++){
                    printf("0 1 ");
                }
                for(int i=1;i<=d;i++){
                    printf("2 3 ");
                }
                printf("2 ");
                for(int i=1;i<=b;i++){
                    printf("1 2 ");
                }
            }
            else{
                printf("1 ");
                for(int i=1;i<=a;i++){
                    printf("0 1 ");
                }                
                for(int i=1;i<=c;i++){
                    printf("2 1 ");
                }
                for(int i=1;i<=d;i++){
                    printf("2 3 ");
                }

            }
        }
        else printf("NO\n");
    }
    else if(a==b+1&&c==0&&d==0){
        
        printf("YES\n0 ");
        for(int i=1;i<=b;i++){
            printf("1 0 ");
        }
    }
    else if(d==c+1&&a==0&&b==0){
        printf("YES\n3 ");
        for(int i=1;i<=c;i++) printf("2 3 ");
    }
    else printf("NO");
    return 0;
}