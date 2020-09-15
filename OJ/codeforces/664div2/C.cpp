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
int a[207],b[207];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    for(int i=0;i<(1<<9);i++){
        int ok=1;
        for(int k=1;k<=n;k++){
            int OK=0;
            for(int z=1;z<=m;z++){
                int x=(a[k]&b[z]);
                if((x&i)==x){
                    OK=1;
                }
            }
            if(!OK) ok=0;
        }
        if(ok){
            printf("%d",i);return 0;
        }
    }
    return 0;
}