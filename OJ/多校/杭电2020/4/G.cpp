#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =210, M=100010;
struct node
{
    int to, next;;
}edge[M],e[M];
int stk[N],stk2[N],head[N],low[N],belg[N];
int id[N],vis[N],h[N], t, que[N],dui[N];
int cn,cm,tot,scc,lay;
int Garbowbfs(int cur,int lay)
{
    stk[++cn]=cur; stk2[++cm]=cur;
    low[cur]=++lay;
    for(int i=head[cur];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!low[v]) Garbowbfs(v,lay);
        else if(!belg[v])
            while(low[stk2[cm]]>low[v]) cm--;
    }
    if(stk2[cm]==cur)
    {
        cm--;
        scc++;
        do
            belg[stk[cn]]=scc;
        while(stk[cn--]!=cur) ;
    }
    return 0;
}

bool Garbow(int n)
{
    scc=lay=0;
    memset(belg,0,sizeof(belg));
    memset(low,0,sizeof(low));
    for(int i=0;i<n;i++)//顶点从0开始（若是1需要修改）
        if(!low[i]) Garbowbfs(i,lay);
    for(int i=0;i<n;i+=2)
    {
        if(belg[i]==belg[i+1]) return 0;
        dui[belg[i]]=belg[i+1];
        dui[belg[i+1]]=belg[i];
    }
    return 1;
}
void addedge(int i,int j)
{
    edge[tot].to=j; edge[tot].next=head[i];head[i]=tot++;
}
void add_e(int i,int j)
{
    e[t].to=j; e[t].next=h[i];h[i]=t++;
}
void init()
{
    tot=t=0;
    memset(head,-1,sizeof(head));
    memset(h,-1,sizeof(h));
    memset(vis,-1,sizeof(vis));
    memset(id,0,sizeof(id));
}
void topo()
{
    int i,k,j=0;
    for(i=0;i<scc;i++)
        if(id[i]==0) que[j++]=i;
    for(i=0;i<j;i++)
    {
        int u=que[i];
        if(vis[u]==-1)
        {
            vis[u]=1;
            vis[dui[u]]=0;
        }
        for(k=h[u];k!=-1;k=e[k].next)
        {
            int v=e[k].to;
            id[v]--;
            if(id[v]==0)
                que[j++]=v;
        }
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    int n,m,i,j,k;
    char ch1,ch2;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(!n) break;
        init();
        while(m--)
        {
            scanf("%d%c %d%c",&i,&ch1,&j,&ch2);
            if(ch1=='w') i=2*i;
            else i=2*i+1;
            if(ch2=='w') j=2*j;
            else j=2*j+1;
            addedge(i,j^1);
            addedge(j,i^1);
        }
        addedge(0,1);
        n*=2;
        if(Garbow(n)==0) {printf("bad luck\n"); continue;}
        for(i=0;i<n;i++)//反向图
        {
            for(k=head[i];k!=-1;k=edge[k].next)
            {
                int u=belg[i], v=belg[edge[k].to];
                if(u!=v)
                {
                    add_e(v,u);
                    id[u]++;
                }
            }
        }
        topo();
        for(i=2;i<n;i+=2)
        {
            k=belg[i];
            if(vis[k]==1)printf("%dh ",i/2);
            else printf("%dw ",i/2);
        }
        printf("\n");
    }
    return 0;
}