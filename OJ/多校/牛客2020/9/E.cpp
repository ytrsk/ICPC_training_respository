#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int top,sz1[maxn],sz2[maxn],num[maxn];
map<int,int> aa;
const int mod=998244353;
int mul(int a,int b){
    return 1LL*a*b%mod;
}
int pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
int PreA1[100007],PreA2[100007],PreB1[100007],PreB2[100007];
inline void pre(int x,int *Pre1,int *Pre2){
    Pre1[0]=1;Pre2[0]=1;
    for(int i=1;i<=100000;i++) Pre2[i]=1LL*Pre2[i-1]*x%mod;
    x=pown(x,100000);
    for(int i=1;i<=100000;i++) Pre1[i]=1LL*Pre1[i-1]*x%mod;
}

inline int solve(int x,int *Pre1,int *Pre2){
    return mul(Pre1[x/100000],Pre2[x%100000]);
}
int main(){
    int a=read(),b=read(),c=read(),d=read(),x=read(),y=read();
    int len=sqrt(x+0.5),X=x,Y=y;
    for(int i=2;i<=len;i++){
        if(X%i==0){
            int a=0;
            while(X%i==0){
                X/=i;a++;
            }
            aa[i]=a;
        }
    }
    if(X>1) aa[X]=1;
    len=sqrt(Y+0.5);
    for(int i=2;i<=len;i++){
        if(Y%i==0){
            int a=0;
            while(Y%i==0){
                Y/=i;a++;
            }
            if(aa.count(i)){
                ++top;sz1[top]=aa[i];sz2[top]=a;num[top]=i;
            }
        }
    }
    if(Y>1){
        if(aa.count(Y)){
            ++top;sz1[top]=aa[Y];sz2[top]=1;num[top]=Y;
        }
    }
    //cout<<top<<endl;
    //for(int i=1;i<=top;i++){
    //    cout<<sz1[i]<<" "<<sz2[i]<<" "<<num[i]<<endl;
  //  }
    int ans=1;
    for(int i=1;i<=top;i++){
        pre(pown(num[i],sz2[i])%mod,PreB1,PreB2);
        pre(pown(num[i],sz1[i])%mod,PreA1,PreA2);
        int Ans=1;
        for(int k=a;k<=b;k++){
            int st=(sz1[i]*k-1)/sz2[i]+1;
      //     cout<<st<<" "<<solve(1LL*(d-st+1)*k%(mod-1),PreA1,PreA2)<<" "<<pown(num[i],sz1[i])<<" "<<d<<endl;
            if(st>c){
                int R=min(d,st-1);
                Ans=mul(Ans,solve(1LL*(c+R)*(R-c+1)/2%(mod-1),PreB1,PreB2));
            }
            if(st<=d){
                Ans=mul(Ans,solve(1LL*(d-max(st,c)+1)*k%(mod-1),PreA1,PreA2));
            }
        }
        ans=mul(ans,Ans);
    }
    printf("%d",ans);
    return 0;
}