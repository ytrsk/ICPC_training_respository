#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=400007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],num[80000007];
ll shu[87];
int main(){
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        for(int k=0,x=2;k<=24,4*1e7>=x;k++,x*=2){
            num[x+a[i]%x]++;
        }
    }
    for(int i=1;i<=80000000;i++) num[i]=num[i]+num[i-1];
    for(int i=1;i<=n;i++){
        for(int k=0,x=2;k<=24,4*1e7>=x;k++,x*=2){
            if(a[i]>>k&1){
                shu[k]+=num[x+x-a[i]%x-1]-num[x-1]+num[2*x-1]-num[2*x+x/2-a[i]%x-1];
            }
            else{
                shu[k]+=num[x+x-a[i]%x-1]-num[x+x/2-a[i]%x-1];
            }
            if((a[i]<<1)>>k&1) shu[k]--; 
        }
    }
    int ans=0;
    for(int i=0;i<=25;i++){
        if((shu[i]/2)%2==1) ans|=(1<<i);
    }
    cout<<ans;
    return 0;
}