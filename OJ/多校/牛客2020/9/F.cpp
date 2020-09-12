#include <bits/stdc++.h>
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
struct node{
    int id,x;
    bool operator < (node a) const{
        return x<a.x;
    }
}nd[maxn<<1];
int sz[maxn<<3],e1=0,ee,rt;
int ha[maxn<<1],len;
inline void pushup(int o){
    sz[o]=sz[o<<1]+sz[o<<1|1];
}
inline void ins(int o,int l,int r,int x,int c){
    if(l==r){
        sz[o]+=c;return;
    }
    int m=(l+r)>>1;
    if(x<=m) ins(o<<1,l,m,x,c);
    else ins(o<<1|1,m+1,r,x,c);
    pushup(o);
}
int you[maxn];
inline int query(int o,int l,int r,int x){
    if(l==r){
        if(sz[o]>=x) return l;
        else return -1;
    }
    int m=(l+r)>>1;
    if(sz[o<<1|1]>=x) return query(o<<1|1,m+1,r,x);
    else return query(o<<1,l,m,x-sz[o<<1|1]);
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        int x=read();
        while(x--){
            int y=read();
            nd[++e1]=node{i,y};
        }
    }
    sort(nd+1,nd+e1+1);
    for(int i=1;i<=e1;i++) ha[++len]=nd[i].x;
    len=unique(ha+1,ha+len+1)-ha-1;
    for(int i=1;i<=e1;i++) nd[i].x=lower_bound(ha+1,ha+len+1,nd[i].x)-ha;
    int ans=inf;
    for(int i=1;i<=e1;i++){
        if(you[nd[i].id]){ins(1,1,len,you[nd[i].id],-1);}
        you[nd[i].id]=nd[i].x;
        ins(1,1,len,you[nd[i].id],1);
        if(sz[1]>=m) ans=min(ans,ha[nd[i].x]-ha[query(1,1,len,m)]);
    }
    cout<<ans;
    return 0;
}