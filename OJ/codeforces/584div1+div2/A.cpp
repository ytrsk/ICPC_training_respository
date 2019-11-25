#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int a[107],you[107];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);int ans=0;
    for(int i=1;i<=n;i++){
        if(!you[i]){
            ans++;
            for(int k=1;k<=n;k++){
                if(a[k]%a[i]==0) you[k]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
