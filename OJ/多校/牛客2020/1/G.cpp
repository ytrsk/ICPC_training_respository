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
const int mod=998244353;
const long long mod3=1LL*mod*mod-1;
struct nd{
    ll x,y,z;
    nd operator * (nd a) const{
        return nd{(x*a.x+y*a.z+z*a.y)%mod,(z*a.z+y*a.x+x*a.y)%mod,
        (z*a.x+x*a.z+y*a.y)%mod};
    }
}v[maxn];
ll e[21][maxn];
ll pre[maxn];
int main(){
    pre[0]=1;
    for(int i=1;i<=300;i++) pre[i]=(pre[i-1]<<1)%mod3;
    int n=read(),m=read(),q=read();
    unsigned z=read(),a=read(),b=read();
    for(int i=1;i<=n;i++){
        z=z*a+b;
        v[i].x=z%mod;
        z=z*a+b;
        v[i].y=z%mod;
        z=z*a+b;
        v[i].z=z%mod;
    }
    for(int i=1;i<=q;i++){
        for(int k=1;k<=n;k++){
            e[i][k]=0;
            for(int j=0;j<m;j++){
                z=z*a+b;
                e[i][k]=(e[i][k]+(__int128)z*pre[32*j]%mod3)%mod3;
            }
        }
    }
    for(int i=1;i<=q;i++){ 
        nd ans=nd{1,0,0};
        for(int k=1;k<=n;k++){
            nd now=v[k];
            while(e[i][k]){
                if(e[i][k]&1) ans=ans*now;
                now=now*now;
                e[i][k]>>=1;
            }
        }
        printf("%d %d %d\n",ans.x,ans.y,ans.z);
    }
    return 0;
}