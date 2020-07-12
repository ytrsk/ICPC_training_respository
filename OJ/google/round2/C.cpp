#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(register auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(register auto i=(x);i>=(y);--i)
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll X[maxn],Y[maxn];
int you[10],n,cnt;
int top=0;
int s[10007][11];
int vis[1<<7][8],Vis[8];
void dfs(int o){
    if(o==n+1){
        ++top;
        rep(i,1,n) s[top][i]=you[i];
        return ;
    }
    dfs(o+1);
    if(!you[o])
    for(int i=o+1;i<=n;i++){
        if(!you[i]){
            you[i]=o;you[o]=i;dfs(o+1);you[i]=you[o]=0;
        }
    }
}
inline ll cross(ll x1,ll y1,ll x2,ll y2){
    return x1*y2-x2*y1;
}
inline ll dot(ll x1,ll y1,ll x2,ll y2){
    return x1*x2+y1*y2;
}
int main(){
    int T=read();int e=0;
    while(T--){
        n=read();
        rep(i,1,n){
            X[i]=read();Y[i]=read();
        }
        int ANS=1;
        top=0;dfs(1);
        if(n-1){
            rep(pre1,1,n){
                rep(pre2,1,n){
                    if(pre1==pre2) continue;
                    ll xx=(X[pre2]-X[pre1]),yy=(Y[pre2]-Y[pre1]);
                    rep(a0,1,n){    
                        rep(F,1,top){
                            int now=a0;
                            int ans=1;
                            rep(i,0,(1<<n)-1){
                                rep(k,1,n) vis[i][k]=0;
                            }
                            rep(i,1,n) Vis[i]=0;
                            Vis[now]=1;
                            int aa=(1<<(now-1));
                            if(s[F][now]){
                                now=s[F][now];                            
                                while(1){
                                    __int128 mn=(__int128)inf*inf;int pos=0;
                                    aa|=(1<<(now-1));
                                    ans+=!Vis[now];Vis[now]=1;
                                    if(vis[aa][now]) break;
                                    else vis[aa][now]=1;
                                    rep(i,1,n){
                                        if(now!=i&&cross(xx,yy,X[i]-X[now],Y[i]-Y[now])==0){
                                            ll x=dot(xx,yy,X[i]-X[now],Y[i]-Y[now]);
                                            if(x<mn&&x>=0){
                                                mn=x;pos=i;
                                            }
                                        }
                                    }
                                    if(pos){
                                        if(!Vis[pos]) Vis[pos]=1,ans++,aa|=(1<<(pos-1));
                                        if(s[F][pos]) now=s[F][pos];
                                        else break;
                                    }
                                    else break;
                                }
                                ANS=max(ANS,ans);
                            }                            

                        }
                    }
                }
            }
        }
        else{
            ANS=1;
        }
        printf("Case #%d: %d\n",++e,ANS);
    }
    return 0;
}