#include <bits/stdc++.h>
#include "lcs.h"
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int A[maxn];
void find_permutation(int n,int res[]){
    res[0]=0;
    rep(i,1,n-1){
        int l=0,r=i-1,ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            A[0]=i;A[1]=res[mid];
            if(get_lcs(2,A)==2){
                r=mid-1;ans=mid;
            }
            else l=mid+1;
        }
        if(ans==-1) res[i]=i;
        else{
            dep(k,i,ans+1) res[k]=res[k-1];
            res[ans]=i;
        }
    }
}
int main(){
    int n=read();
    
    return 0;
}