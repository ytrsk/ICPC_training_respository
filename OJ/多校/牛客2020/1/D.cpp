#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1007;
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
struct matrix{
    int v[maxn][maxn],n,m;
    matrix(int n,int m):n(n),m(m){
        for(int i=1;i<=n;++i)
        for(int k=1;k<=m;++k)
        v[i][k]=0;
    }
    int* operator [] (int idx){
        return v[idx]; 
    }
    matrix operator * (matrix a){
        matrix ans(n,a.m);
        for(int i=1;i<=n;i++){
            for(int k=1;k<=m;k++){
                
            }
        }
    }
    void clear(){
        memset(a,0,sizeof(a));
    }
};
int main(){
    int n=read();
    return 0;
}