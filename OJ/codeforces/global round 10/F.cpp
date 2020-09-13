#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int mu[maxn],phi[maxn],sum[maxn];
int len,p[maxn];
int vis[maxn];
int main(){
    mu[1]=1;phi[1]=1;
    for(int i=2;i<=100000;i++){
        if(!phi[i]) p[++len]=i,mu[i]=i,phi[i]=i-1;
        for(int k=1;k<=len&&i*p[k]<=100000;k++){
            if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=p[k];
            else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=mu[i]*p[k];break;}
        }
    }
    for(int i=2;i<=100000;i++) vis[mu[i]]++;
    asd
    return 0;
}