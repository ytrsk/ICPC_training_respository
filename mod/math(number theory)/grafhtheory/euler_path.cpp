#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
const int inf=(1LL<<29);
map<int,int> head,de;
int to[maxn<<1],next1[maxn<<1],vis[maxn<<1];
int ans[maxn],e1,a[maxn],b[maxn],ee;
void addedge(int u,int v){
    ++e1;next1[e1]=head[u];head[u]=e1;to[e1]=v;
}
void euler_path(int u){
    for(int &i=head[u];i;i=next1[i]){
        if(vis[i]) continue;
        vis[i]=vis[((i-1)^1)+1]=1;
        euler_path(to[i]);
    }
    ans[++ee]=u;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    int n,m;cin>>n;
    for(int i=1;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++) cin>>b[i];
    for(int i=1;i<n;i++){
        if(a[i]>b[i]){
            cout<<-1;return 0;
        }
        addedge(a[i],b[i]);addedge(b[i],a[i]);
        de[a[i]]++;de[b[i]]++;
    }
    int sum=0,now=0;
    for(auto it=de.begin();it!=de.end();++it){
        if((*it).second&1){
            sum++;now=(*it).first;
        }
    }
    if(sum==0||sum==2){
        euler_path(sum==0?(*de.begin()).first:now);
        if(ee!=n) cout<<-1;
        else for(int i=1;i<=ee;i++) cout<<ans[i]<<" ";
    }
    else{
        cout<<-1;
    }
    return 0;
}
