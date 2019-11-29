#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[107];
int main(){
    int cnt=0;
    int t=read();
    while(t--){
        int x=read();for(int i=1;i<=48;i++) a[i]=x;x=read();
        for(int i=49;i<=56;i++) a[i]=x;x=read();
        for(int i=57;i<=60;i++) a[i]=x;x=read();
        for(int i=61;i<=62;i++) a[i]=x;
        x=read();a[63]=x;
        int n=read();long long ans=0;
        for(int i=1;i<=n;i++){
            x=read();ans+=a[x];
        }
        ++cnt;
        printf("Case #%d: %lld\n",cnt,ans*10000);
    }
    return 0;
}
