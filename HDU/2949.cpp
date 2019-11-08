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
char s[maxn];
int main(){
  //  cin.tie(0);ios_base::sync_with_stdio(false);
    int N;
    while((N=read())&&N){
        for(int i=1;i<=N;i++){
            scanf("%s",s+1);
        }
    }
    int cnt=0;
    return 0;
}
