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
int a[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read(),x=read(),y=read();
        for(int i=n-1;i;i--){
            if((y-x)%i==0){
                int d=(y-x)/i;
                for(int k=n;k>=2;k--){
                    if(y-d*(k-1)>0){
                        for(int now=y-d*(k-1),cnt=1;cnt<=n;cnt++,now+=d)
                        printf("%d ",now);
                        break;
                    } 
                }
                break;
            }
        }
        printf("\n");
    }
    return 0;
}