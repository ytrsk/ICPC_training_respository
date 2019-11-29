#include <stdio.h>
#include <algorithm>
#include <queue>
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
int e1,head[maxn],to[maxn],nex[maxn],in[maxn];
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int ans[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read(),m=read();
        for(int i=1;i<=n;i++) head[i]=in[i]=0;e1=0;
        for(int i=1;i<=m;i++){
            int u=read(),v=read();
            addedge(v,u);in[u]++;
        }
        priority_queue<int> q;
        for(int i=1;i<=n;i++){
            if(!in[i]) q.push(i);
        }
        int cnt=n;
        while(!q.empty()){
            int u=q.top();q.pop();ans[u]=cnt--;
            for(int i=head[u];i;i=nex[i]){
                int v=to[i];
                in[v]--;
                if(!in[v]) q.push(v);
            }
        }
        if(cnt) printf("-1\n");
        else{
            for(int i=1;i<=n;i++) printf("%d ",ans[i]);
            printf("\n");
        }
    }

    return 0;
}
