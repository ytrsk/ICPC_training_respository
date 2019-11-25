#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=150007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[maxn];
int Len;
struct SAM{
    int e1,last;
    int tr[maxn<<1][30];
    int you[maxn<<1];
    int len[maxn<<1],fa[maxn<<1];
    int newnode(){
        ++e1;memset(tr[e1],0,sizeof(tr[e1]));
        return e1;
    }
    inline void init(){
        e1=0;last=newnode();
    }
    void add(int x,int y){
        int now=newnode(),p;
        len[now]=len[last]+1;
        for(p=last;p&&!tr[p][x];p=fa[p]) tr[p][x]=now;
        you[now]=1;pos[now]=y;
        if(!p) fa[now]=1;
        else{
            int q=tr[p][x];
            if(len[q]==len[p]+1) p==last?now=q:fa[now]=q;
            else{
                int np=p==last?now:newnode();
                len[np]=len[p]+1;
                memcpy(tr[np],tr[q],sizeof(tr[q]));
                fa[np]=fa[q];
                for(;p&&tr[p][x]==q;p=fa[p]) tr[p][x]=np;
                fa[q]=np;if(now!=np) fa[now]=np;
            }
        }
        last=now;
    }
    int num[maxn],id[maxn<<1],mn[maxn<<1];
    long long cnt[maxn<<1],sum[maxn<<1];
    int pos[maxn<<1];
    vector<pair<int,int>> g[maxn<<1];
    void topsort(){
        for(int i=1;i<=e1;i++) num[len[i]]++;
        for(int i=1;i<=Len;i++) num[i]+=num[i-1];
        for(int i=1;i<=e1;i++) id[num[len[i]]--]=i;
        for(int i=e1;i-1;i--){
            int x=id[i];
            you[fa[x]]+=you[x];
            pos[fa[x]]=pos[x];
            mn[x]=len[fa[x]]+1;
            cnt[x]=1LL*(len[x]-mn[x]+1);
            sum[x]+=cnt[x];
            sum[fa[x]]+=sum[x];
            g[fa[x]].push_back(make_pair(s[pos[x]-len[fa[x]]]-'a',x));
            sort(g[x].begin(),g[x].end());
        }
        sort(g[1].begin(),g[1].end());
        cnt[1]=0;
    }
    void dfs(int now,long long x){
        if(x<=cnt[now]){
            for(int i=pos[now];i>=pos[now]-mn[now]-x+2;i--) printf("%c",s[i]);
            putchar('\n');
            return;
        }
        x-=cnt[now];
        for(int i=0;i<g[now].size();i++){
            int z=g[now][i].second;
            if(x<=sum[z]){
                dfs(z,x);break;
            }
            else x-=sum[z];
        }
    }
}S;

int main(){
    scanf("%s",s+1);
    Len=strlen(s+1);reverse(s+1,s+Len+1);
    S.init();
    for(int i=1;i<=Len;i++) S.add(s[i]-'a',i);
    S.topsort();
    int n=read();
    for(int i=1;i<=n;i++){
        long long x;scanf("%lld",&x);
        S.dfs(1,x);
    }
    return 0;
}
