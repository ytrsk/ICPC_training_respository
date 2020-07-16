#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
vector<int> g[maxn];
int main(){
    int n=read();
    if(n==1) printf("1\n1");
    else if(n==2) printf("2\n1\n00");
    else if(n==3) printf("2\n00\n110");
    else if(n==4) printf("3\n00\n110\n1010");
    else{
        int now=n,t=0;
        while(now>=t){
            for(int i=1;i<=now;i++){
                if(i<=t) g[now].push_back(0);
                else g[now].push_back(1);
            }
            now--;t++;
        }
        t=1;
        while(now>=t+1){
            for(int i=1;i<=now;i++){
                if(i<=t) g[now].push_back(1);
                else g[now].push_back(0);
            }
            now--;t++;
        }
        printf("%d\n",n-now);
        for(int i=now+1;i<=n;i++){
            for(int k=0;k<g[i].size();k++) printf("%d",g[i][k]);
            printf("\n");
        }
    }
    return 0;
}