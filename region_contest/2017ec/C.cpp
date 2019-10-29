#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],b[maxn],c[maxn];
int main(){
    int t=read();
    int cnt=0;
    while(t--){
        ++cnt;
        int n=read(),sum=0;
        for(int i=1;i<=n+1;i++) a[i]=read(),sum+=a[i];
        for(int i=1;i<=n;i++){
            b[i]=read(),c[i]=read();
        }
        int x=*max_element(c+1,c+n+1);
        printf("Case #%d: %d.0\n",cnt,x+sum);
    }

    return 0;
}
