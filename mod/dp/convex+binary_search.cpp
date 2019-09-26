#include <stdio.h>
#include <algorithm>
#include <iostream>
#define make_pair mp
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int maxn=100007;
const int inf=(1LL<<29);
int a[maxn],sum[maxn],q[maxn],ql,qr;
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
        ql=1,qr=0;
        double tot=-1e9;
        for(int i=m;i<=n;i++){
            while(ql<qr&&1LL*(sum[q[qr]]-sum[q[qr-1]])*(i-m-q[qr])>=1LL*(sum[i-m]-sum[q[qr]])*(q[qr]-q[qr-1])) qr--;
            q[++qr]=i-m;
            int l=ql,r=qr,ans=0;
            while(l<=r){
                int mid=(l+r)>>1;
                if(mid==qr||1LL*(sum[q[mid+1]]-sum[q[mid]])*(i-q[mid+1])>=1LL*(sum[i]-sum[q[mid+1]])*(q[mid+1]-q[mid])){
                    r=mid-1;ans=mid;
                }
                else l=mid+1;
            }
            tot=max(tot,1.0*(sum[i]-sum[q[ans]])/(i-q[ans]));
        }
        printf("%d\n",(int)(tot*1000.0));
    }
    return 0;
}
