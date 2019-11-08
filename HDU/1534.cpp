#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
const int inf=(1LL<<29);
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
int n,e1,nex[maxn],head[maxn],to[maxn],w[maxn],inq[maxn],cnt[maxn],d[maxn],s;
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
bool spfa(){
    queue<int> q;q.push(n);
    for(int i=1;i<=n;i++) inq[i]=cnt[i]=0,d[i]=-inf;
    inq[n]=1;d[n]=0;
    while(!q.empty()){
        int u=q.front();q.pop();inq[u]=0;
       // printf("asd%d\n",u);
        for(int i=head[u];i;i=nex[i]){
            int v=to[i];
         //   printf("qq%d %d\n",u,w[i]);
            if(d[v]<d[u]+w[i]){
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
void init(){
    for(int i=1;i<=n;i++) head[i]=0;e1=0;
    for(int i=1;i<n;i++) addedge(s,i,0);
}
int a[maxn];
int main(){
  //  cin.tie(0);ios_base::sync_with_stdio(false);
    int N;
    int cnt=0;
    while((N=read())&&N){n=2*N+1;s=n;init();
        for(int i=1;i<=N;i++) a[i]=read(),addedge(2*i-1,2*i,a[i]),addedge(2*i,2*i-1,-a[i]);

        char S[10];
        while(1){
            scanf("%s",S+1);
            if(S[1]=='#') break;
            int x=read(),y=read();
            if(S[1]=='F'){
                if(S[3]=='F')addedge(2*y,2*x,0);
                else addedge(2*y-1,2*x,0);
            }
            else{
                if(S[3]=='F') addedge(2*y,2*x-1,0);
                else addedge(2*y-1,2*x-1,0);
            }
        }
        printf("Case %d:\n",++cnt);
        if(!spfa()) printf("impossible\n\n");
        else{
            for(int i=1;i<=N;i++){
                printf("%d %d\n",i,d[2*i-1]);
            }
            printf("\n");
        }
    }
    return 0;
}
