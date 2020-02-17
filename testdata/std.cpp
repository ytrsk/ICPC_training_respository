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
int a[maxn],b[5];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=4;i++) b[i]=read();
    ll ans=0;
    for(int i=1;i<=4;i++)
    for(int i=1;i<=n;i++){
        for(int k=i+1;k<=n;k++)
        for(int z=k+1;z<=n;z++)
        for(int j=1;j<=4;j++){
            int c[5],ok=1;c[1]=a[i];c[2]=a[k];c[3]=a[z];c[4]=a[j];
            for(int A=1;A<5;A++)
            for(int B=1;B<5;B++){
                if((c[A]==c[B])!=(b[A]==b[B])) ok=0;
            }    
            if(ok) ans++;
        }
    }
    cout<<ans;
    return 0;
}