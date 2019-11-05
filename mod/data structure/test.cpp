#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define MAX 1001000
inline int read()
{
    int x=0;bool t=false;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=true,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return t?-x:x;
}
struct Line{int v,next;}e[MAX<<1];
int h[MAX],cnt=1;
inline void Add(int u,int v){e[cnt]=(Line){v,h[u]};h[u]=cnt++;}
int n,md[MAX],dep[MAX],hson[MAX],ans[MAX];
void dfs1(int u,int ff)
{
    dep[u]=md[u]=dep[ff]+1;
    for(int i=h[u];i;i=e[i].next)
    {
        int v=e[i].v;if(v==ff)continue;
        dfs1(v,u);md[u]=max(md[u],md[v]);
        if(md[v]>md[hson[u]])hson[u]=v;
    }
}
int tmp[MAX],*f[MAX],*id=tmp;
void dfs(int u,int ff)
{
    f[u][0]=1;
    if(hson[u])f[hson[u]]=f[u]+1,dfs(hson[u],u),ans[u]=ans[hson[u]]+1;
    for(int i=h[u];i;i=e[i].next)
    {
        int v=e[i].v;if(v==ff||v==hson[u])continue;
        f[v]=id;id+=md[v]-dep[v]+1;dfs(v,u);
        for(int j=0;j<=md[v]-dep[v];++j)
        {
            f[u][j+1]+=f[v][j];
            if(f[u][j+1]>f[u][ans[u]]||(f[u][j+1]==f[u][ans[u]]&&ans[u]>j+1))
                ans[u]=j+1;
        }
    }
    if(f[u][ans[u]]==1)ans[u]=0;
}
int main()
{
    n=read();
    for(int i=1;i<n;++i)
    {
        int u=read(),v=read();
        Add(u,v);Add(v,u);
    }
    dfs1(1,0);f[1]=id;id+=md[1];dfs(1,0);
    for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
    return 0;
}
————————————————
版权声明：本文为CSDN博主「小蒟蒻yyb」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_30974369/article/details/81673990
