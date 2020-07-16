#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
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
int a[maxn];
map<int,int> aa;
int you[100007];
int main(){
    int n=read();
    int mn=inf;
    rep(i,1,n) a[i]=read(),mn=min(mn,a[i]);
    rep(i,0,30) aa[1<<i]=i;
    int mx=0;
    for(int i=1;i<=n;i++){
        if(a[i]%mn){
            printf("-1");return 0;
        }
        int x=a[i]/mn;
        if(!aa.count(x)){
            printf("-1");return 0;
        }
        you[aa[x]]++;mx=max(mx,aa[x]);
    }
    int ans=0;
    rep(i,0,mx){
        if(i==mx&&you[i]==1) break;
        if(you[i]%2){
            ans++;you[i]++;
        }
        if(you[i]){
            you[i+1]+=you[i]/2;
            mx=max(mx,i+1);
        }
    }
    cout<<ans;
    return 0;
}