#include <bits/stdc++.h>
using namespace std;
const int maxn=200007;
int e1,tr[maxn*30][2],rt,sum[maxn*30][2];
int newnode(){
    ++e1;sum[e1][0]=sum[e1][1]=tr[e1][0]=tr[e1][1]=0;
    return e1;
}
inline void insert(int x,int o){
    int u=rt;
    for(int i=29;~i;--i){
        sum[u][o]++;
        int c=(x>>i)&1;
        if(!tr[u][c]) tr[u][c]=newnode();
        u=tr[u][c];
    }
    sum[u][o]++;
}
inline void del(int x,int o){
    int u=rt;
    for(int i=29;~i;--i){
        int c=(x>>i)&1;
        sum[u][o]--;
        u=tr[u][c];
    }
    sum[u][o]--;
}
inline int you(int o){
    int u=rt,ans=0;
    for(int i=29;~i;--i){
        if(sum[tr[u][0]][o]) u=tr[u][0];
        else u=tr[u][1],ans|=1<<i;
    }
    return ans;
}
inline int query(int x,int o){
    int u=rt,ans=0;
    for(int i=29;~i;--i){
        int c=(x>>i)&1;
        if(sum[tr[u][c]][o^1]){
            //printf("%d %d %d\n",c,i,ans);
            ans|=c<<i;u=tr[u][c];
        }
        else{
         //   printf("%d %d %d %d\n",c^1,i,ans,sum[tr[u][c^1]][o^1]);
            ans|=(c^1)<<i;u=tr[u][c^1];
        }
    }
    return ans;
}
int top,ans[maxn];
inline int solve(int u,int o,int last){
    while(1){
        int v=query(u,o);
      //  printf("%d %d\n",u,v);
        if(v==last){
        //    printf("asd");
            ans[++top]=u^v;
            del(u,o);del(v,o^1);
            return 1;
        }
        if(solve(v,o^1,u)) return 1;
    }
}
int a[maxn],b[maxn];
int main(){
    freopen("1.in","r",stdin);
    int t;cin>>t;
    while(t--){
        e1=rt=newnode();top=0;
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),insert(a[i],0);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),insert(b[i],1);
        while(top<n){
            solve(you(0),0,-1);
        }
        for(int i=1;i<=top;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
