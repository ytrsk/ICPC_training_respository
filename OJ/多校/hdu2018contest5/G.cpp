#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=200007;
int n,lg[maxn];
unsigned x,y,z,w;
unsigned rng61(){
    x^=(x<<11);
    x^=(x>>4);
    x^=(x<<5);
    x^=(x>>14);
    w=x^(y^z);
    x=y;y=z;z=w;
    return z;
}
unsigned int f[15000007];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int val[maxn][30];
int main(){
    int T=read();
    while(T--){
        int n=read(),m=read();
        for(int i=1;i<=n;i++) lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
        for(int i=1;i<=n;i++) for(int k=0;k<=lg[n];k++) val[i][k]=0;
        x=read(),y=read(),z=read();
        for(int i=1;i<=3*m;i++) f[i]=rng61();
        for(int i=1;i<=m;i++){
            int X=f[3*i-2]%n+1,Y=f[3*i-1]%n+1;
            int l=min(X,Y),r=max(X,Y),v=f[3*i]%(1<<30);
            int len=lg[r-l+1];
            val[l][len]=max(val[l][len],v);
            val[r-(1<<len)+1][len]=max(val[r-(1<<len)+1][len],v);
        }
        for(int i=lg[n];i>=1;i--){
            for(int k=1;k+(1<<i)-1<=n;k++){
                val[k][i-1]=max(val[k][i-1],val[k][i]);
                val[k+(1<<i-1)][i-1]=max(val[k+(1<<i-1)][i-1],val[k][i]);
            }
        }
        long long now=0;
        for(int i=1;i<=n;i++) now^=(1LL*i*val[i][0]);
        printf("%lld\n",now);
    }
	return 0;
}
