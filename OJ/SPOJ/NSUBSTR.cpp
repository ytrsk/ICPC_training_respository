#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=250007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct SAM{
    int e1,last;
    int tr[maxn<<1][30];
    int you[maxn<<1];
    int len[maxn<<1],fa[maxn<<1],mn[maxn<<1];
    int newnode(){
        ++e1;memset(tr[e1],0,sizeof(tr[e1]));
        return e1;
    }
    inline void init(){
        e1=0;last=newnode();
    }
    void add(int x){
        int now=newnode(),p;
        len[now]=len[last]+1;
        for(p=last;p&&!tr[p][x];p=fa[p]) tr[p][x]=now;
        you[now]=1;
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
}S;
char s[maxn];
int len,num[maxn],id[maxn<<1];
void topsort(){
    for(int i=1;i<=S.e1;i++) num[S.len[i]]++;
    for(int i=1;i<=len;i++) num[i]+=num[i-1];
    for(int i=1;i<=S.e1;i++) id[num[S.len[i]]--]=i;
    for(int i=S.e1;i;i--){
        S.you[S.fa[id[i]]]+=S.you[id[i]];
    }
}
int f[maxn];
int main(){
    scanf("%s",s+1);
    len=strlen(s+1);
    S.init();
    for(int i=1;i<=len;i++) S.add(s[i]-'a');
    topsort();
    for(int i=2;i<=S.e1;i++) f[S.len[i]]=max(f[S.len[i]],S.you[i]);
    for(int i=len;i>1;i--) f[i-1]=max(f[i],f[i-1]);
    for(int i=1;i<=len;i++) printf("%d\n",f[i]);
    return 0;
}
