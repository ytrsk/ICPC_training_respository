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
int now[maxn];
vector<int> g[maxn];
int mu[maxn],phi[maxn],sum[maxn];
int len,p[maxn],vis[maxn];
int V[maxn],L[maxn],R[maxn];
int main(){
    int t=read();
    mu[1]=1;phi[1]=1;
    for(int i=2;i<=200000;i++){
        if(!phi[i]) p[++len]=i,mu[i]=-1,phi[i]=i-1;
        for(int k=1;k<=len&&i*p[k]<=200000;k++){
            if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=p[k];
            else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=mu[i];break;}
        }
    }
    for(int i=2;i<=200000;i++){
        if(!vis[i]){
            g[i].push_back(i);
            for(int k=2*i;k<=200000;k+=i) vis[k]=1,g[k].push_back(i);
        }
    }
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) if(!vis[i]) now[i]=i;
        for(int i=1;i<=n;i++) V[i]=0;
        int top=0;
        for(int i=n;i;i--){
            if(V[i]) continue;
            for(int k=g[i].size()-1;k>=0;k--){
                while(now[g[i][k]]<=n&&(now[g[i][k]]<i&&V[now[g[i][k]]])){
                    now[g[i][k]]+=g[i][k];
                }
                if(now[g[i][k]]<i&&now[g[i][k]]<=n&&!V[now[g[i][k]]]){
                    V[now[g[i][k]]]=1;
                    ++top;
                    L[top]=i;
                    R[top]=now[g[i][k]];
                    break;
                }
            }
        }
        printf("%d\n",top);
        for(int i=1;i<=top;i++){
            printf("%d %d\n",L[i],R[i]);
        }
    }
    return 0;
}