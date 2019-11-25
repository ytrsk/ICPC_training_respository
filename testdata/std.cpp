#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define ls ch[0][rt]
#define rs ch[1][rt]
char buf[2100000],*p1=buf,*p2=buf;
int read()
{
    int x=0;
    char ch=gc();
    while(ch<'0'||ch>'9')
        ch=gc();
    while(ch>='0'&&ch<='9')
    {
        x=x*10+(ch&15);
        ch=gc();
    }
    return x;
}
int Max(int x,int y){return x>y?x:y;}
int Min(int x,int y){return x<y?x:y;}
using std::nth_element;
int ch[2][200100],v[200100],x[2][200100],y[2][200100],c[2][200100],pcnt=0;
int sz[200100],root=0;
long long sum[200100];
int Newnode(int X,int Y,int z)
{
    ++pcnt;
    sum[pcnt]=v[pcnt]=z;
    x[0][pcnt]=x[1][pcnt]=c[0][pcnt]=X;
    y[0][pcnt]=y[1][pcnt]=c[1][pcnt]=Y;
    return pcnt;
}
int a[200100],cnt=0;
void dfs(int rt)
{
    if(ls)
        dfs(ls);
    a[++cnt]=rt;
    if(rs)
        dfs(rs);
}
inline bool cmp0(int a,int b)
{return c[0][a]<c[0][b];}
inline bool cmp1(int a,int b)
{return c[1][a]<c[1][b];}
void maintain(int &rt)
{
    sz[rt]=sz[ls]+1+sz[rs];
    sum[rt]=sum[ls]+v[rt]+sum[rs];
    x[0][rt]=Min(c[0][rt],Min(x[0][ls],x[0][rs]));
    x[1][rt]=Max(c[0][rt],Max(x[1][ls],x[1][rs]));
    y[0][rt]=Min(c[1][rt],Min(y[0][ls],y[0][rs]));
    y[1][rt]=Max(c[1][rt],Max(y[1][ls],y[1][rs]));
}
void build(int &rt,int l,int r,int d)
{
    if(l>r)
    {
        rt=0;
        return;
    }
    int mid=(l+r)>>1;
    nth_element(a+l,a+mid,a+r+1,d?cmp1:cmp0);
    rt=a[mid];
    build(ls,l,mid-1,!d);
    build(rs,mid+1,r,!d);
    maintain(rt);
}
void Insert(int &rt,int nd,int d)
{
    if(!rt)
    {
        rt=nd;
        return;
    }
    Insert(ch[c[d][nd]>=c[d][rt]][rt],nd,!d);
    maintain(rt);
}
int Cnt=0;
void Find(int &rt,int nd,int d)
{
    if(rt==nd)
        return;
    if(Max(sz[ls],sz[rs])>sz[rt]*.85)
    {
        cnt=0;
        dfs(rt);
        build(rt,1,cnt,d);
        return;
    }
    Find(ch[c[d][nd]>=c[d][rt]][rt],nd,!d);
}
int ask(int rt,int lx,int ly,int rx,int ry)
{
    if(lx<=x[0][rt]&&rx>=x[1][rt]&&ly<=y[0][rt]&&ry>=y[1][rt])
        return sum[rt];
    if(rx<x[0][rt]||lx>x[1][rt]||ry<y[0][rt]||ly>y[1][rt])
        return 0;
    return ask(ls,lx,ly,rx,ry)+((c[0][rt]>=lx&&c[0][rt]<=rx&&c[1][rt]>=ly&&c[1][rt]<=ry)?v[rt]:0)+ask(rs,lx,ly,rx,ry);
}
int main()
{
#ifdef wjyyy
    freopen("a.in","r",stdin);
#endif
    x[0][0]=y[0][0]=0x7fffffff;
    int op,n=read(),X,Y,z,x_,y_,lstans=0;
    while(op!=3)
    {
        op=read();
        if(op==1)
        {
            X=read()^lstans;
            Y=read()^lstans;
            z=read()^lstans;
            Insert(root,Newnode(X,Y,z),0);
            Find(root,pcnt,0);
        }
        else if(op==2)
        {
            X=read()^lstans;
            Y=read()^lstans;
            x_=read()^lstans;
            y_=read()^lstans;
            lstans=ask(root,X,Y,x_,y_);
            printf("%d\n",lstans);
        }
    }
    return 0;
}