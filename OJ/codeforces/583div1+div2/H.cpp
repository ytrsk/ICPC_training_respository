#include <bits/stdc++.h>
using namespace std;
const int maxn=200007;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
vector<int> g[maxn];
int dep[maxn],p[maxn];
int q[maxn],top,you[maxn],col[maxn];
int mx=0,m;
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    p[u]=fa;
    mx=max(mx,dep[u]);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa||you[v]) continue;
        dfs(v,u);
    }
}
void Col(int u,int now,int d){
    col[u]=now;
    now+=d;
    now=(now+m-1)%m+1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!col[v]) Col(v,now,d);
    }
}
int main(){
    int n=read();m=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        g[u].push_back(v);g[v].push_back(u);
    }
    dfs(1,0);
    int A=max_element(dep+1,dep+n+1)-dep;
    dfs(A,0);
    int B=max_element(dep+1,dep+n+1)-dep;
    while(B!=A){
        q[++top]=B;B=p[B];
    }
    q[++top]=A;
    for(int i=top;i;i--) you[q[i]]=1,col[q[i]]=(top-i)%m+1;
    if(top<m){
        printf("Yes\n");
        for(int i=1;i<=n;i++) printf("1 ");
        return 0;
    }
    else if(m==2){
        printf("Yes\n");
        for(int i=1;i<=n;i++) printf("%d ",dep[i]%2+1);
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(you[i]){
            int a=dep[i]-1,b=top-dep[i];
            mx=0;dfs(i,0);
            if(mx==1) continue;
            if(mx-1+a>=m-1&&mx-1+b>=m-1){
                printf("No");return 0;
            }
            if(a>b){
                Col(i,col[i],1);
            }
            else{
                Col(i,col[i],-1);
            }
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++) printf("%d ",col[i]);
    return 0;
}
