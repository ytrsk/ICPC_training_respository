#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int e1,head[maxn],to[maxn<<1],nex[maxn<<1],w[maxn<<1];
void addedge(int u,int v,int x){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;w[e1]=x;
}
ll ans=0;
int mn[maxn],mx[maxn];
int U[maxn],V[maxn],top=0;
void dfs(int u,int fa,int x){
    int sz=0;vector<int> g1,g2;
    mn[u]=mx[u]=u;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa){
            dfs(v,u,w[i]^1);
            if(w[i]==1) g1.push_back(v);
            else g2.push_back(v);
        }
    }
    for(int i=0;i<g1.size()-1;i++){
        ++top;U[top]=mx[g1[i]];V[top]=mn[g1[i+1]];
    }
    if(g1.size()) mn[u]=mn[g1[0]];
    for(int i=0;i<g2.size()-1;i++){
        ++top;U[top]=mx[g2[i]];V[top]=mn[g2[i+1]];
    }
    if(g2.size()) mx[u]=mx[g2[g2.size()-1]];
}
void Dfs(int u,int fa,int a,int b,int x){
    vector<int> g1,g2;vector<int> r1,r2;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa){
            if(w[i]==1) g1.push_back(v);
            else g2.push_back(v);
        }
    }
    if(a) r1.push_back(a);
    for(int i=0;i<g1.size();i++){
        r1.push_back(mn[g1[i]]);
        r2.push_back(mx[g1[i]]);
    }
    if(x==1){
        if(a) r1.push_back(a);
        if(b) r2.push_back(b);
        if(g1.size()){
            ++top;U[top]=mx[g1[g1.size()-1]];V[top]=a;
        }
    }
    r1.push_back(u);r2.push_back(u);
    for(int i=0;i<g2.size();i++){
        r1.push_back(mn[g2[i]]);
        r2.push_back(mx[g2[i]]);
    }    
    if(x==0){
        if(a) r1.push_back(a);
        if(b) r2.push_back(b);
        if(g2.size()){
            ++top;U[top]=mx[g2[g2.size()-1]];V[top]=a;
        }
    }
    g1.clear();g2.clear();
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa){
            int na=r1[0],nb=r2[r2.size()-1];
            if(mn[v]==na) na=r1[1];
            if(mx[v]==nb) nb=r2[r2.size()-2];
            Dfs(v,u,na,nb,w[i]^1);
        }
    }
}
int you[maxn];
int main(){
    int t=read();
    while(t--){
        ans=0;top=0;
        int n=read();
        e1=0;
        for(int i=1;i<=n;i++) head[i]=0,you[i]=0;
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            you[u]=1;addedge(u,v,0);addedge(v,u,1);
        }
        dfs(1,0,-1);Dfs(1,0,0,0,-1);
        
    }
    return 0;
}