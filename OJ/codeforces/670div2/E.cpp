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
int B(int x){
    printf("B %d\n",x);
    fflush(stdout);
    scanf("%d",&x);return x;
}
int A(int x){
    printf("A %d\n",x);
    fflush(stdout);
    scanf("%d",&x);return x;
}
int main(){ 
    int n;scanf("%d",&n);
    mu[1]=1;phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!phi[i]) p[++len]=i,mu[i]=i,phi[i]=i-1;
        for(int k=1;k<=len&&i*p[k]<=n;k++){
            if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=p[k];
            else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=mu[i]*p[k];break;}
        }
    }
    int cnt=0;
    for(int i=2;i<=n;i++) vis[mu[i]]++;
    ll num=1;
    ll ed=len;
    for(int i=1;i<=len;i++){
        ll x=p[i];
        while(x*p[i]<=n) x*=p[i];
        int ok=0;
        while(x!=1){
            if(B(x)!=vis[x]) 
            if(!ok) num*=x,ok=1;
            x/=p[i];
        }
        if(i%100==0&&num==1&&1LL*p[i]*p[i]>n){
            if(A(1)!=len-i+1){
                ed=min(ed,1LL*i);
            }
        }
    }
    if(num>1){
        int ok=0;
        for(int i=1;i<=len;i++){
            ll x=p[i];
            while(x*p[i]<=n) x*=p[i];
            while(x!=1){
                if(A(x)==1){
                    while(num%p[i]==0) num/=p[i];
                    ok=1;num*=x;break;
                }
                x/=p[i];
            }
            if(ok) break;
        }
        printf("C %lld\n",num);fflush(stdout);
    }
    else{
        for(int i=1;i<=len;i++){
            if(1LL*p[i]*p[i]>n) break;
            if(A(p[i])==1){
                printf("C %lld\n",p[i]);fflush(stdout);return 0;
            }
        }
        for(int i=ed;i>=max(1LL,ed-100+1);i--){
            ll x=p[i];
            while(x*p[i]<=n) x*=p[i];
            while(x!=1){
                if(A(x)==1){
                    printf("C %lld\n",x);fflush(stdout);return 0;
                }
                x/=p[i];
            }
        }
        printf("C %lld\n",1);fflush(stdout);return 0;
    }
    return 0;
}