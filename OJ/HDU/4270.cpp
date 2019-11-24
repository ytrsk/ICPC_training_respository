#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int Len;char s[maxn];
struct SAM{
    int e1,last;
    int tr[maxn<<1][26];
    int you[maxn<<1],del[maxn<<1];
    int len[maxn<<1],fa[maxn<<1],mn[maxn<<1],pos[maxn<<1],id[maxn<<1];
    int op[maxn][2],Last[maxn],suf[maxn<<1];
    int newnode(){
        ++e1;memset(tr[e1],0,sizeof(tr[e1]));pos[e1]=del[e1]=0;
        return e1;
    }
    inline void init(){
        e1=0;last=newnode();
    }
    void add(int x,int y){
        int now=newnode(),p;
        op[y][0]=now;suf[now]=1;
        len[now]=len[last]+1;
        pos[now]=y;
        for(p=last;p&&(!tr[p][x]||del[tr[p][x]]);p=fa[p]) tr[p][x]=now;
        if(!p) fa[now]=1;
        else{
            int q=tr[p][x];
            if(len[q]==len[p]+1) fa[now]=q;
            else{
                int np=newnode();op[y][1]=np;suf[np]=1;
                len[np]=len[p]+1;
                memcpy(tr[np],tr[q],sizeof(tr[q]));
                fa[np]=fa[q];
                for(;p&&tr[p][x]==q;p=fa[p]) tr[p][x]=np;
                fa[q]=fa[now]=np;pos[np]=pos[now];
            }
        }
        last=now;
        Last[y]=now;
    }
}S;
unordered_map<int,int> you;
void solve(int n){
    you.clear();
    int now=S.last;
    while(now!=1) you[now]=1,now=S.fa[now];
}
int main(){
    scanf("%s",s+1);int T=read();Len=strlen(s+1);S.init();
    S.Last[0]=1;
    for(int i=1;i<=Len;i++) S.add(s[i]-'a',i);
    int Now=Len;solve(Now);
    while(T--){
        int opt=read();
        if(opt==1){
            scanf("%s",s+1);
            Len=strlen(s+1);
            for(int i=1;i<=Len;i++) ++Now,S.add(s[i]-'a',Now);
            solve(Now);
        }
        else if(opt==2){
            int now=1;
            int x=read(),r=0;
            while(x--){
                if(you[now]) break;
                int ok=0;
                for(int i=0;i<26;i++){
                    if(S.tr[now][i]&&!S.del[S.tr[now][i]]){
                        now=S.tr[now][i];ok=1;++r;
                        break;
                    }
                }
                if(!ok) break;
            }
            printf("%d\n",you[now]?Now-r+1:S.pos[now]-r+1);
        }
        else{
            int x=read();
            for(int i=Now-x+1;i<=Now;i++) S.del[S.op[i][0]]=S.del[S.op[i][1]]=1;
            Now-=x;S.last=S.Last[Now];solve(Now);
        }
    }
    return 0;
}
