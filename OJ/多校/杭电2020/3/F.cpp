#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int len,num[23];
ll C[2003][2003];
int a[12];
ll dp[15][23];
inline ll Solve(int x,int y){
   // cout<<x<<" "<<y<<" "<<a[9]<<endl;
    ll ans=0;
    for(int i=a[y]+x;i>=a[y];i--){
        int now=x-(i-a[y]);
        for(int k=0;k<=x;k++) dp[0][k]=0;
        dp[0][0]=C[x][now];
     //   cout<<dp[0][now]<<" "<<now<<" "<<ans<<endl;
       // cout<<now<<" "<<x<<" "<<ans<<endl;
        for(int k=0;k<=9;k++){
            if(k!=y&&a[k]>=i) return ans;
        }
        int last=0;
        for(int k=0;k<=9;k++){
            if(k==y) continue;
            for(int z=0;z<=now;z++) dp[k+1][z]=0;
            for(int z=0;z<i-a[k];z++){
                for(int e=z;e<=now;e++){
                    dp[k+1][e]+=dp[last][e-z]*C[e][z];
                }
            }
            last=k+1;
        }
    //    cout<<dp[last][now]<<" "<<i<<endl;
        ans+=dp[last][now];
    }
    return ans;
}
inline ll solve(ll x,int y){
    if(x==0) return 0;
    len=0;ll ans=1;
    int mx=0;
    for(int i=0;i<=9;i++) a[i]=0;
    while(x) num[++len]=x%10,x/=10,a[num[len]]++,mx=max(mx,a[num[len]]);
    for(int i=0;i<=9;i++){
        if(a[i]==mx&&i!=y||i==y&&a[i]!=mx) ans=0;
    }
    for(int i=len;i;i--){
        for(int k=0;k<num[i];k++){
            if(i==len&&k==0){
                for(int j=1;j<=i-1;j++){
                    for(int z=1;z<=9;z++){
                        for(int r=0;r<=9;r++) a[r]=0;
                        a[z]++;
                        ans+=Solve(j-1,y);
                    //    cout<<Solve(j-1,y)<<" "<<j-1<<" "<<z<<endl;
                    }
                }
            }
            else{
                for(int z=0;z<=9;z++) a[z]=0;
                for(int z=len;z>i;z--){
                    a[num[z]]++;
                }
                a[k]++;
                ans+=Solve(i-1,y);
            }
        }
    }
    return ans;
}
int main(){
    C[0][0]=1;
    for(int i=1;i<=2000;i++){
        C[i][0]=1;
        for(int k=1;k<=2000;k++) C[i][k]=C[i-1][k]+C[i-1][k-1];
    }
    cout<<C[48][5]<<endl;
    int t=read();
    while(t--){
        ll l=read(),r=read(),x=read();
        printf("%lld\n",solve(r,x)-solve(l-1,x));
    }
    return 0;
}