
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
int a[1007];
int main(){
    int n=read();
    for(int i=1;i<=n;i++)
    for(int k=1;k<=n;k++){
        int x=read();
        for(int z=0;z<=28;z++){
            if(x>>z&1){
                a[i]|=(1<<z);
                a[k]|=(1<<z);
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}