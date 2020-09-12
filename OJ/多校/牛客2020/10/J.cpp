#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int head[maxn],to[maxn<<1],nex[maxn<<1],to[maxn<<1],e1,from[maxn<<1];
int dp[507][507],A[507],B[507];
int Head[maxn],To[maxn<<1],Nex[maxn<<1],To[maxn<<1],E1,From[maxn<<1];
int sz[maxn<<1],Sz[maxn<<1],n;
void addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
void Addedge(int u,int v){
    ++E1;Nex[E1]=Head[u];Head[u]=E1;To[E1]=v;
}
void predfsA(int u,int fa,int x){
    sz[x]++;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        predfsA(v,u,i);
        sz[x]+=sz[i];
    }
    if(x) sz[((x-1)^1)+1]=n-sz[x];
}
void predfsB(int u,int fa,int x){
    Sz[x]++;
    for(int i=Head[u];i;i=Nex[i]){
        int v=To[i];
        if(v==fa) continue;
        predfsB(v,u,i);
        Sz[x]+=Sz[i];
    }
    if(x) Sz[((x-1)^1)+1]=n-Sz[x];
}
int id[maxn<<1],Id[maxn<<1];
int cmpA(int a,int b){
    return sz[a]<sz[b];
}
int cmpB(int a,int b){
    return Sz[a]<Sz[b];
}
int main(){
    n=read();
    for(int i=1;i<=n;i++) A[i]=read();
    for(int i=1;i<=n;i++) B[i]=read();
    for(int i=1;i<=n;i++){
        if(A[i]==0){
            addedge(A[i],i);
            addedge(i,A[i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(B[i]==0){
            Addedge(i,B[i]);
            Addedge(B[i],i);
        }
    }
    predfsA(1,0,0);
    predfsB(1,0,0);
    for(int i=1;i<=2*(n-1);i++){
        id[i]=Id[i]=i;
    }
    sort(id+1,id+2*(n-1)+1,cmpA);
    sort(Id+1,Id+2*(n-1)+1,cmpB);
    for(int i=1;i<=2*(n-1);i++){
        for(int k=1;k<=2*(n-1);k++){
            
        }
    }
    return 0;
}