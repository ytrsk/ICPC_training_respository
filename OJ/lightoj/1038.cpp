#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
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
double dp[maxn];
int a[maxn];
vector<int> g[maxn];
int main(){
    int t=read();
    int cnt=0;
    for(int i=1;i<=100000;i++)
        for(int k=2*i;k<=100000;k+=i){
            g[k].push_back(i);
        }
    for(int i=2;i<=100000;i++){
        //(x-1)*y=x+sum
        double x=0;
        int len=g[i].size();
        len=g[i].size();
        for(int k=0;k<len;k++) x+=dp[g[i][k]];
        dp[i]=(x+len+1)/len;
    }
    while(t--){
        int n=read();
        printf("Case %d: %.8f\n",++cnt,dp[n]);
    }
    return 0;
}
