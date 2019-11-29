#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
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
    int len[maxn<<1],fa[maxn<<1];
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
        if(!p) fa[now]=1;
        else{
            int q=tr[p][x];
            if(len[q]==len[p]+1) fa[now]=q;
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
}S[11];
char s[11][maxn],ss[maxn];
int n;
int len[11],now[11];
int main(){
    while(scanf("%s",ss+1)==1){
        strcpy(s[++n]+1,ss+1);
    }
    for(int i=1;i<n;i++){
        now[i]=1;
        S[i].init();
        int len=strlen(s[i]+1);
        for(int k=1;k<=len;k++) S[i].add(s[i][k]-'a');
    }
    int Len=strlen(s[n]+1);
    int mx=0;
    for(int i=1;i<=Len;i++){
        int x=s[n][i]-'a';
        int mn=1e7;
        for(int k=1;k<n;k++){
            while(!S[k].tr[now[k]][x]&&now[k]>1)
            now[k]=S[k].fa[now[k]],
            len[k]=S[k].len[now[k]];
            if(S[k].tr[now[k]][x]) len[k]++,now[k]=S[k].tr[now[k]][x];
            mn=min(mn,len[k]);
        //    cout<<i<<" "<<k<<" "<<len[k]<<endl;
        }
        mx=max(mx,mn);
    }
    cout<<mx;
    return 0;
}
