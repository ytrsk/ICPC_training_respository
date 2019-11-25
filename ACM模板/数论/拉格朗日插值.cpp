#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#define rint register int
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=107;
int a[maxn][maxn],n;
struct poly{
    int num[maxn],len;
    poly(int x):len(x){
        for(int i=0;i<=len;i++) num[i]=0;
    }
    inline poly operator * (poly a){
        poly new1(len+a.len);
        for(int i=0;i<=len;i++)
        for(int k=0;k<=a.len;k++){
            new1.num[i+k]=(new1.num[i+k]+1LL*num[i]*a.num[k])%mod;
        }
        return new1;
    }
    void print(){
        for(int i=0;i<=len;i++) printf("%d ",num[i]);
        cout<<endl;
    }
};
inline int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int inv(int x){
    return pown(x,mod-2);
}
void lagarange_poly_coe(int *x,int *y,int n){
    poly coe(n);
    for(rint i=0;i<=n;i++){
        poly now(0);now.num[0]=1;
        int low=1;
        for(rint k=0;k<=n;k++){
            if(k!=i){
                poly a(1);a.num[1]=1;a.num[0]=mod-x[k];
                now=now*a;
                low=(1LL*low*(x[i]-x[k]+mod))%mod;
            }
        }
        low=inv(low);
        for(rint k=0;k<=n;k++){
            now.num[k]=(1LL*now.num[k]*y[i])%mod;
            now.num[k]=(1LL*now.num[k]*low)%mod;
            (coe.num[k]+=now.num[k])%=mod;
        }
    }
    for(rint i=0;i<=n;i++) cout<<coe.num[i]<<" ";
}
int yy[maxn],xx[maxn];
int main(){
    xx[0]=0;yy[0]=1;xx[1]=1;yy[1]=3;xx[2]=2;yy[2]=7;
    lagarange_poly_coe(xx,yy,2);
	return 0;
}
