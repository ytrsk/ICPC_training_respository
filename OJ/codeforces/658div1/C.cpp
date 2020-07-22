#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
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
int a[maxn];
int vis[maxn];
int ans[maxn];
stack<int> q[maxn];
int cl=0;
struct node{
    int sz,x;
    node(int sz,int x):sz(sz),x(x){}
    bool operator < (node a) const{
        if(sz!=a.sz) return sz<a.sz;
        else return (x==cl)<(a.x==cl);
    }
};
int main(){
    int t=read();
    while(t--){
        priority_queue<node> p;
        int n=read(),x=read(),y=read();
        rep(i,1,n+1) vis[i]=0;
        int ex=0;
        for(int i=1;i<=n;i++) a[i]=read(),vis[a[i]]++;
        if(y==0){
            printf("NO\n");continue;
        }
        else y--;
        for(int i=1;i<=n+1;i++) if(!vis[i]){
            ex=i;break;
        }
        ans[x]=a[x];
        if(x==n-1) cl=a[n];
        for(int i=1;i<=n+1;i++){
            while(!q[i].empty())
            q[i].pop();
        }
        for(int i=1;i<x;i++){
            q[a[i]].push(i);
        }
        for(int i=1;i<=n+1;i++){
            if(q[i].size())p.push(node(q[i].size(),i));
        }
        while(p.size()>=2){
            node x=p.top();p.pop();
            node yy=p.top();p.pop();
            int X=q[x.x].top(),Y=q[yy.x].top();
            if(y>=2){
                ans[X]=a[Y];
                ans[X]=a[Y];
                y-=2;
            }
            else if(y==1){
                ans[X]=a[Y];
                ans[Y]=ex;
                y--;
            }
            else{
                ans[X]=ex;ans[Y]=ex;
            }
            q[x.x].pop();q[yy.x].pop();
            x.sz--;yy.sz--;
            if(x.sz) p.push(x);
            if(yy.sz) p.push(yy);
        }
        if(p.size()){
            node X=p.top();
            for(int i=x+1;i<=n;i++){
                if(X.sz==0){
                    if(y) ans[i]=a[i],y--;
                    else ans[i]=ex;
                }
                else{
                    if(a[i]==X.x){
                        if(y>=1){
                            ans[i]=a[i];y--;
                        }
                        else ans[i]=ex;
                    }
                    else{
                        if(y>=2){
                            int x=q[X.x].top();q[X.x].pop();
                            X.sz--;
                            ans[x]=a[i];ans[i]=a[x];
                            y-=2;
                        }
                        else if(y==1){
                            ans[i]=a[i];y--;
                        }
                        else ans[i]=ex;
                    }
                }
            }
            while(X.sz){
                int x=q[X.x].top();q[X.x].pop();
                X.sz--;
                ans[x]=ex;
            }
            if(y){
                printf("NO\n");
            }
            else{
                printf("YES\n");
                rep(i,1,n) printf("%d ",ans[i]);
                printf("\n");
            }
        }
        else{
            if(n-x>=y){
                printf("YES\n");
                for(int i=x+1;i<=x+y;i++){
                    ans[i]=a[i];
                }
                rep(i,x+y+1,n){
                    ans[i]=ex;
                }
                rep(i,1,n) printf("%d ",ans[i]);
                printf("\n");
            }
            else printf("NO\n");
        }
    }
    return 0;
}