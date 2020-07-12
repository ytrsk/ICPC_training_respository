#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,a[maxn];
int A[maxn],B[maxn];
void suan(int x,int *A){
    rep(i,1,n){
        int tot=x;
        if(tot<=i-1) A[i]=i;
        else {
            tot-=max(0,i-2);
            int now=i,Now=max(0,i-2)+1;
            while(now<tot){
                tot-=now;
                Now+=now;
                now=Now;
            }
            A[i]=now-tot+1;
        }
    }
}
int b[maxn],vis[maxn];
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
int tmp[maxn],ans[maxn];
int main(){
    n=read();ll m=read();
    suan(n,A);
    ll y=m/(n-1);
    if(m%(n-1)) suan(m%(n-1)+1,B);
    else rep(i,1,n) B[i]=i;
    if(y){
        for(int i=1;i<=n;i++){
            vector<int> g;
            if(!vis[i]){
                int x=i;
                while(!vis[x]){
                    g.push_back(x);
                    vis[x]=1;x=A[x];
                }
                int len=g.size();
                int r=gcd((int)g.size(),y);
                if(r==1){
                    rep(k,0,len-1){
                        tmp[k]=g[(__int128)k*y%len];
                    }
                    rep(k,0,len-1){
                        A[tmp[k]]=tmp[(k+1)%len];
                    }
                }
                else{
                    rep(k,0,len-1){
                        int now=g[k];
                        int nex=(k+r)%len;
                        A[now]=g[nex];  
                    }
                }
            }
        }
    }
    else{
        rep(i,1,n) A[i]=i;
    }
    rep(i,1,n) ans[B[A[i]]]=i;
    rep(i,1,n) printf("%d ",ans[i]);
    return 0;
}