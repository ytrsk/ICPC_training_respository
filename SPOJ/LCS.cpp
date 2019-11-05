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
long long ans=0;
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
}S;
char s1[maxn],s2[maxn];
int main(){
    scanf("%s%s",s1+1,s2+1);
    int l1=strlen(s1+1),l2=strlen(s2+1);
    S.init();
    for(int i=1;i<=l1;i++) S.add(s1[i]-'a');
    int now=1,len=0,mx=0;
    for(int i=1;i<=l2;i++){
        int x=s2[i]-'a';
        while(!S.tr[now][x]&&now!=1) now=S.fa[now],len=S.len[now];
        if(S.tr[now][x]) now=S.tr[now][x],len++;
        mx=max(mx,len);
    }
    cout<<mx;
    return 0;
}
