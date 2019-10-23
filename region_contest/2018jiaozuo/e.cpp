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
ll gcd(ll a,ll b){
    return b?a:gcd(b,a%b);
}
int vis[maxn];
int main(){
    for(int i=2;i<=1e3;i++){
        if(!vis[i]) printf("%d,",i);
        for(int k=i<<1;k<=1e5;k+=i) vis[k]=1;
    }
    return 0;
}
