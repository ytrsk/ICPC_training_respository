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
int v[maxn],c[maxn],pre[maxn],mn[maxn];
vector<int> g[maxn],Ans[maxn];
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        int x=read();pre[x]++;
    }
    for(int i=1;i<=m;i++) c[i]=read();
    int l=1,r=2*n,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        for(int i=1;i<=m;i++) v[i]=pre[i];
        for(int i=1;i<=mid;i++) g[i].clear(),mn[i]=0;
        int pos=1,ok=1;
        for(int i=m;i;i--){ 
            int now=pos;    
            if(i==m||c[i]>c[i+1]) now=1;
            if(v[i]){
                while(now<=mid){
                    int x=min(c[i]-mn[now],v[i]);
                    mn[now]+=x;v[i]-=x;
                    while(x--) g[now].push_back(i);
                    if(!v[i]) break;
                    now++;
                }
                pos=now;
                if(v[i]){
                    ok=0;break;
                }
            }
            pos=now;
        }
        if(ok){
            r=mid-1;ans=mid;
            for(int i=1;i<=mid;i++) Ans[i].assign(g[i].begin(),g[i].end());
        }
        else l=mid+1;
    }
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++){
        printf("%d ",Ans[i].size());
        assert(Ans[i].size()>0);
        for(auto k:Ans[i]) printf("%d ",k);
        printf("\n");
    }
    return 0;
}