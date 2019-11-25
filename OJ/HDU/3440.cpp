#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
#pragma GCC optimize(3,"Ofast","inline")
const int maxn=200007;
const ll inf=(1LL<<60);
//d[i]-d[j]>=w add(j,i,w) maxlen min(d[i])
//d[i]-d[j]<=w add(j,i,w) minlen max(d[i])
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int n,e1,nex[maxn],head[maxn],to[maxn],w[maxn],inq[maxn],cnt[maxn],s;
ll d[maxn];
inline void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
inline bool spfa(){
    queue<int> q;q.push(s);
    for(int i=1;i<=n;i++) inq[i]=cnt[i]=0,d[i]=inf;
    inq[s]=1;d[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();inq[u]=0;
       // printf("asd%d\n",u);
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
         //   printf("qq%d %d\n",u,w[i]);
            if(d[v]>d[u]+w[i]){
                d[v]=d[u]+w[i];
                if(!inq[v]){
                    inq[v]=1;q.push(v);
                    cnt[v]++;
                    if(cnt[v]>n){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
inline void init(){
    for(int i=1;i<=n;i++) head[i]=0;e1=0;
}
pii a[maxn];
int now[maxn];
int main(){
  //  cin.tie(0);ios_base::sync_with_stdio(false);
    int T=read();
    int cnt=0;
    while(T--){
        int N=read(),D=read();
        for(int i=1;i<=N;i++) {int x=read();a[i]=mp(x,i);}
        sort(a+1,a+N+1);int t;
        for(int i=1;i<=N;i++) now[a[i].second]=i;
        n=N;if(a[N].second<a[1].second) s=N,t=1;else s=1,t=N;
        init();
        for(int i=2;i<=N;i++){
            if(a[i].second>a[i-1].second) addedge(i-1,i,D);
            else addedge(i,i-1,D);
        }
        for(int i=2;i<=N;i++){
            addedge(now[i],now[i-1],-1);
        }
        if(spfa()) {
    //        for(int i=1;i<=N;i++) printf("%d %d\n",i,d[i]);
            printf("Case %d: %d\n",++cnt,d[t]);
        }
        else printf("Case %d: -1\n",++cnt);
    }
    return 0;
}
