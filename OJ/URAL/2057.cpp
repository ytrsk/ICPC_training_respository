#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}

int tr[maxn][27];
int fail[maxn],L[maxn],e1,las,LL[maxn],sz[maxn],num[maxn];
void init(){
    L[0]=0;fail[0]=1;L[1]=-1;fail[1]=0;e1=1;las=0;
    memset(tr[0],0,sizeof(tr[0]));
    memset(tr[1],0,sizeof(tr[1]));
}
char s[maxn];
int new_node(int x){
    ++e1;
    memset(tr[e1],0,sizeof(tr[e1]));L[e1]=x;
    return e1;
}
int val[maxn],d[maxn],top[maxn];int dpmx[maxn],gmx[maxn],dpmn[maxn],gmn[maxn];
void ins(int c,int n){
    int u=las;
    while(s[n-L[u]-1]!=s[n]) u=fail[u];
    if(!tr[u][c]){
        int now=new_node(L[u]+2);
        int v=fail[u];
        while(s[n-L[v]-1]!=s[n]) v=fail[v];
        fail[now]=tr[v][c];
        tr[u][c]=now;
        gmx[now]=-inf;gmn[now]=inf;
        d[now]=L[now]-L[fail[now]];
        if(d[now]==d[fail[now]]) top[now]=top[fail[now]]; 
        else top[now]=fail[now];
    }
    las=tr[u][c];sz[las]++;
    LL[n]=L[las];
}
int mx[maxn<<2],mn[maxn<<2];
void pushup(int o){
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
    mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void update(int o,int l,int r,int x,int y,int z){
    if(l==r){
        mx[o]=y;mn[o]=z;return;
    }
    int m=(l+r)>>1;
    if(x<=m) update(o<<1,l,m,x,y,z);
    else update(o<<1|1,m+1,r,x,y,z);
    pushup(o);
}
pii merge(pii a,pii b){
    return mp(max(a.first,b.first),min(a.second,b.second));
}
pii query(int o,int l,int r,int ql,int qr){
    if(ql>qr) return mp(-inf,inf);
    if(l==ql&&r==qr){
        return mp(mx[o],mn[o]);
    }
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return merge(query(o<<1,l,m,ql,m),query(o<<1|1,m+1,r,m+1,qr));
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr);
}
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    init();
    for(int i=1;i<=n;i++) ins(s[i]-'a',i);
    int now=0;
    update(1,1,n+1,1,0,0);
    for(int i=1;i<=n;i++){
        int ch=s[i]-'a'; 
        while(s[i-L[now]-1]!=s[i]) now=fail[now];
        now=tr[now][ch];dpmx[i]=-inf;dpmn[i]=inf;
        pii x=query(1,1,n+1,1,i-L[now]);
        dpmx[i]=max(dpmx[i],x.first);dpmn[i]=min(dpmn[i],x.second);
        for(int k=now;k>1;k=top[k]){
            pii Now=query(1,1,n+1,i-L[top[k]]-d[k]+2,i-L[top[k]]);
            gmx[k]=Now.first;
            gmn[k]=Now.second;
            if(d[k]==d[fail[k]]) gmx[k]=max(gmx[k],gmx[fail[k]]),gmn[k]=min(gmn[k],gmn[fail[k]]);
            dpmx[i]=max(dpmx[i],gmx[k]);
            dpmn[i]=min(dpmn[i],gmn[k]);
        }
        dpmn[i]++;dpmx[i]++;
        update(1,1,n+1,i+1,dpmx[i],dpmn[i]);
    }
    if(dpmx[n]<0) printf("-1");
    else printf("%d %d",dpmn[n],dpmx[n]); 
    return 0;
}
