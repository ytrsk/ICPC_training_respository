#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[200007];
int a0[maxn],a1[maxn],L[maxn<<2],R[maxn<<2],num[maxn<<2];
struct node{
    int L,R,num,len;
    node(){}
    node(int L,int R,int num,int len):L(L),R(R),num(num),len(len){};
}nd[maxn<<2];
node merge(node a,node b){
    node c;
    c.num=a.num+b.num;
    if(b.L&&a.R){
        if(b.L%2) c.num--;
        if(a.R%2) c.num--;
        c.num+=(b.L+a.R)%2;
    }
    if(b.len==b.R) c.R=a.R+b.len;
    else c.R=b.R;
    if(a.len==a.L) c.L=a.len+b.L;
    else c.L=a.L;
    return c;
}
void build(int o,int l,int r){
    nd[o].len=r-l+1;
    if(l==r){
        if(s[l]=='0') nd[o].L=nd[o].R=0,nd[o].num=0; 
        else nd[o].L=nd[o].R=1,nd[o].num=1;
        return;
    }
    int m=(l+r)>>1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
    nd[o]=merge(nd[o<<1],nd[o<<1|1]);
}
int ri[maxn],le[maxn];
node update(int o,int l,int r,int ql,int qr,int x){
    if(l==ql&&r==qr){
        return nd[o];
    }
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) return merge(update(o<<1,l,m,ql,m,x),update(o<<1|1,m+1,r,m+1,qr,x));
    else if(ql<=m) return update(o<<1,l,m,ql,qr,x);
    else return update(o<<1|1,m+1,r,ql,qr,x);
}
int n;
int check(int l,int r){
    if(a1[r]-a1[l-1]==r-l+1) return (r-l+1)%2;
    else{
        int x=(s[l]=='1')?ri[l]+1:l,y=(s[r]=='1')?le[r]-1:r;
        int now=update(1,1,n,x,y,0).num;
        if(s[l]=='1'&&(x-l)%2) now++;
        if(s[r]=='1'&&(r-y)%2) now++;
        return now;
    }
}
int main(){
    n=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        a0[i]=a0[i-1]+(s[i]=='0');
        a1[i]=a1[i-1]+(s[i]=='1');
    }
    for(int i=n;i;i--){
        if(i<n&&s[i+1]=='1') ri[i]=ri[i+1];
        else ri[i]=i;
    }
    for(int i=1;i<=n;i++){
        if(i>1&&s[i-1]=='1') le[i]=le[i-1];
        else le[i]=i;
    }
    int q=read();
    for(int i=1;i<=q;i++){
        int l=read(),r=read(),len=read();
        int ok=0;
        if(a0[l+len-1]-a0[l-1]==a0[r+len-1]-a0[r-1]&&a1[l+len-1]-a1[l-1]==a1[r+len-1]-a1[r-1]){
            if(check(l,l+len-1)==check(r,r+len-1)) ok=1;
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}