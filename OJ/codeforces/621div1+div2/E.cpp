#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=5007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int mod=1e9+7;
int a[maxn],f[maxn],h[maxn];
int tot[maxn],you[maxn];
void add(int &x,int y){
    (x+=y)%=mod;
}
int ans[maxn];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) f[i]=read(),h[i]=read();
    for(int i=1;i<=n;i++) tot[f[i]]++;
    for(int i=1;i<=n;i++){
        you[f[i]]++;int now=1;
        for(int k=1;k<=n;k++){
            if(k!=f[i]){
                you[k]=
            }
            else{
                
            }
        }
    }
    return 0;
}