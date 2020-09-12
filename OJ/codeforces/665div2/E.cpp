#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int v1[maxn],v2[maxn];
int L1[maxn],R1[maxn];
int L2[maxn],R2[maxn];
void update1(int x,int y){
    if(x==0) return;
    for(int i=x;i<=1000000;i+=lowbit(i)){
        v1[i]+=y;
    }
}
int query1(int x){
    if(x<0) return 0;
    int ans=0;
    for(int i=x;i;i-=lowbit(i)) ans+=v1[i];
    return ans;
}
void update2(int x,int y){
    if(x==0) return;
   // cout<<"update:"<<x<<" "<<y<<"\n";
    for(int i=x;i<=1000000;i+=lowbit(i)){
        v2[i]+=y;
    }
}
int query2(int x){
    if(x<0) return 0;
    int ans=0;
    for(int i=x;i;i-=lowbit(i)) ans+=v2[i];
    return ans;
}
struct node{
    int x,y;
};
vector<node> g[1000007],G[1000007],g1[1000007];
ll V,E;
map<pair<int,int>,int> aa;
void ins(int a,int b){
    if(!aa[mp(a,b)]) aa[mp(a,b)]=1,V++;
}
int main(){
    int n=read(),m=read();
    V=4,E=4;
    for(int i=1;i<=n;i++){
        int x=read();
        L1[i]=read(),R1[i]=read();
        g[L1[i]].push_back(node{x,1});
        g[R1[i]+1].push_back(node{x,-1});
        g1[L1[i]+1].push_back(node{x,1});
        g1[R1[i]].push_back(node{x,-1});
        E++;
        ins(L1[i],x);
        ins(R1[i],x);
        if(L1[i]==0) E++;
        if(R1[i]==1000000) E++;
    }
    for(int i=1;i<=m;i++){
        int x=read();
        G[x].push_back(node{(L2[i]=read()),(R2[i]=read())});
        E++;
        ins(x,L2[i]);ins(x,R2[i]);
        if(L2[i]==0) E++;
        if(R2[i]==1000000) E++;
    }
   // G[1000000].push_back(node{1,1000001});
    ll ans=2;//cout<<V<<endl;
    for(int i=0;i<=1000000;i++){
        for(int k=0;k<g[i].size();k++){
            update1(g[i][k].x,g[i][k].y);
        }
        for(auto x:g1[i]) update2(x.x,x.y);
        for(int k=0;k<G[i].size();k++){
            V+=query2(G[i][k].y-1)-query2(G[i][k].x);
            E+=query1(G[i][k].y-1)-query1(G[i][k].x);
            E+=query2(G[i][k].y)-query2(G[i][k].x-1);
            
         //   cout<<V<<" "<<query2(4)<<endl;
        }
    }
    cout<<E-V+1;
    return 0;
}