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
int a[maxn],b[maxn];
int main(){
    int t=read();
    int cnt=0;
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) a[i]=read(),b[i]=0;
        int last=0,ok=1;++cnt;
        a[n+1]=0;a[n+2]=0;
        for(int i=1;i<=n+2;i++){
            if(a[i]<0){
                ok=0;break;
            }
            last+=b[i];
            if(a[i]>last){
                a[i+1]-=a[i]-last;a[i+2]-=a[i]-last;
                b[i+3]+=a[i]-last;
            }
            else if(a[i]<last) last=a[i];
        }
        if(ok) printf("Case #%d: Yes\n",cnt);
        else printf("Case #%d: No\n",cnt);
    }
    return 0;
}
