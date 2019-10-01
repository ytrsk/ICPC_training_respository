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
struct nd{
    int mx,lm,rm,mn,val;
    void print(){
        printf("mx:%d lm:%d rm:%d mn:%d val:%d\n",mx,lm,rm,mn,val);
    }
}seg[maxn<<2];
nd mg(nd a,nd b){
    nd N;N.mx=max(a.mx,b.mx);
    if(a.mn<b.mn){
        N.lm=a.lm;
        N.rm=max(a.rm,b.mx);
        N.val=a.val;
        N.mn=a.mn;
    }
    else if(a.mn>b.mn){
        N.rm=b.rm;
        N.lm=max(b.lm,a.mx);
        N.mn=b.mn;
        N.val=b.val;
    }
    else{
        N.lm=a.lm;
        N.rm=b.rm;
        N.mn=a.mn;
        N.val=a.val+b.val+max(a.rm,b.lm);
    }
    return N;
}
void pul(int o){
    seg[o]=mg(seg[o<<1],seg[o<<1|1]);
}
int tag[maxn<<2];
void pus(int o){
    tag[o<<1]+=tag[o];
    seg[o<<1].mn+=tag[o];
    tag[o<<1|1]+=tag[o];
    seg[o<<1|1].mn+=tag[o];
    tag[o]=0;
}
void upd(int o,int l,int r,int ql,int qr,int x){
   // printf("%d %d %d\n",o,l,r);
    if(l==ql&&r==qr){
        tag[o]+=x;seg[o].mn+=x;return;
    }
    pus(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) upd(o<<1,l,m,ql,m,x),upd(o<<1|1,m+1,r,m+1,qr,x);
    else if(ql<=m) upd(o<<1,l,m,ql,qr,x);
    else upd(o<<1|1,m+1,r,ql,qr,x);
    pul(o);
}
int you[maxn],a[maxn],n;set<int> pos[maxn];
void build(int o,int l,int r){
    if(l==r){
        if(*pos[a[l]].begin()==l) seg[o].mx=you[a[l]];
        seg[o].lm=seg[o].mx;
        return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);build(o<<1|1,m+1,r);
    pul(o);
}
void ins(int x,int y){
    if(pos[a[x]].size()>1){
        if(x==*pos[a[x]].begin()){
            auto it=pos[a[x]].begin();it++;upd(1,1,n,x,(*it)-1,y);
        }
        else if(x==*pos[a[x]].rbegin()){
            auto it=pos[a[x]].rbegin();it++;
            upd(1,1,n,(*it),x-1,y);
        }
    }
}
void modify(int o,int l,int r,int x,int y){
    if(l==r){
        seg[o].lm=seg[o].mx=y;
        return;
    }
    pus(o);
    int m=(l+r)>>1;
    x<=m?modify(o<<1,l,m,x,y):modify(o<<1|1,m+1,r,x,y);
    pul(o);
}
nd query(int o,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return seg[o];
    }
    pus(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return mg(query(o<<1,l,m,ql,m),query(o<<1|1,m+1,r,m+1,qr));
    else if(ql<=m) return query(o<<1,l,m,ql,qr);
    else return query(o<<1|1,m+1,r,ql,qr);
}
int main(){
  //  cin.tie(0);ios_base::sync_with_stdio(false);
    n=read();int m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();you[a[i]]++;
        pos[a[i]].insert(i);
    }
    build(1,1,n);
    for(int i=1;i<=200000;i++){
        if(pos[i].size()>1) upd(1,1,n,*pos[i].begin(),*pos[i].rbegin()-1,1);
    }
    printf("%d\n",n-(seg[1].val+seg[1].lm+seg[1].rm));
    for(int i=1;i<=m;i++){
        int x=read(),v=read();
        ins(x,-1);
        if(x==*pos[a[x]].begin()) modify(1,1,n,x,0);
        pos[a[x]].erase(x);
        if(pos[a[x]].size()) modify(1,1,n,*pos[a[x]].begin(),pos[a[x]].size());
        a[x]=v;
        if(pos[a[x]].size()) modify(1,1,n,*pos[a[x]].begin(),0);
        pos[v].insert(x);
        modify(1,1,n,*pos[a[x]].begin(),pos[a[x]].size());
        ins(x,1);
        printf("%d\n",n-seg[1].val-seg[1].lm-seg[1].rm);
     //   query(1,1,n,1,4).print();
    }
    return 0;
}
