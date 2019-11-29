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
int a[maxn];
int you[53][53][53];
int main(){
    int t=read();
    int zz[4];
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++)
        for(int k=i;k<=n;k++)
        for(int z=k;z<=n;z++){
         //   cout<<i<<" "<<k<<" "<<z<<endl;
            bitset<88> bit[11];
            bit[0].set(0);
            for(register int e=1;e<=n;++e){
                if(e!=i&&e!=k&&e!=z){
                    for(register int r=10;r;--r){
                        bit[r]|=bit[r-1]<<a[e];
                    }
                }
            }
            if(bit[10][87]) you[i][k][z]=1;
            else you[i][k][z]=0;
        }
        int m=read();
        for(int i=1;i<=m;i++){
            zz[1]=read();zz[2]=read();zz[3]=read();
            sort(zz+1,zz+4);
            if(you[zz[1]][zz[2]][zz[3]]) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
