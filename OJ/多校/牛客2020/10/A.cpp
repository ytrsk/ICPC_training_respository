#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int vis[maxn],you[maxn];
vector<int> g[maxn],ans;
int nex[maxn],d[maxn],n;
bool solve(int x){
    ans.clear();
    for(int i=1;i<=n;i++) vis[i]=0;
    while(!vis[x]){
        vis[x]=1;
        ans.push_back(x);
        if(!vis[(x*2)%n]) x=x*2%n;
        else x=x*3%n;
    }
    if(ans.size()==n-1) return 1;
    else return 0;
}
int main(){
    int t=read();
    while(t--){
        n=read();
        if(n==3){
            printf("1 2\n");continue;
        }
        int top=0;
        for(int i=1;i<=n;i++) vis[i]=0,you[i]=0,d[i]=0;
        for(int i=1;i<n;i++){
            if(!vis[i]){
                ++top;you[i]=top;
                int x=i;
                while(!vis[x]){
                    vis[x]=1;
                    g[top].push_back(x);
                    x=(2*x)%n;
                }
            }
        }
        for(int i=1;i<=top;i++){
            nex[i]=you[g[i][0]*3%n];
            d[nex[i]]++;
        }
        int now=1;
        for(int i=1;i<=top;i++){
            if(d[i]==0) now=g[i][0];
        }
        if(!solve(now)) printf("-1\n");
        else{
            for(auto v:ans){
                printf("%d ",v);
            }
            printf("\n");
        }
    }
    return 0;
}