#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1000007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int Len;long long ans;
struct SAM{
    int e1,last;
    int tr[maxn<<1][30];
    int you[maxn<<1];
    int len[maxn<<1],fa[maxn<<1],mn[maxn<<1];
    int newnode(){
        ++e1;memset(tr[e1],0,sizeof(tr[e1]));you[e1]=0;
        return e1;
    }
    inline void init(){
        e1=0;last=newnode();
    }
    void add(int x){
        if(tr[last][x]){
            int p=last,q=tr[p][x];
            if(len[q]==len[p]+1) last=q;
            else{
                int np=newnode();
                len[np]=len[p]+1;
                memcpy(tr[np],tr[q],sizeof(tr[q]));
                fa[np]=fa[q];
                for(;p&&tr[p][x]==q;p=fa[p]) tr[p][x]=np;
                fa[q]=np;last=np;
            }
            return;
        }
        int now=newnode(),p;
        len[now]=len[last]+1;
        for(p=last;p&&!tr[p][x];p=fa[p]) tr[p][x]=now;
        if(!p) fa[now]=1;
        else{
            int q=tr[p][x];
            if(len[q]==len[p]+1) fa[now]=q;
            else{
                int np=newnode();
                len[np]=len[p]+1;
                memcpy(tr[np],tr[q],sizeof(tr[q]));
                fa[np]=fa[q];
                for(;p&&tr[p][x]==q;p=fa[p]) tr[p][x]=np;
                fa[q]=fa[now]=np;
            }
        }
        last=now;
    }
    int num[maxn],id[maxn<<1];
    void topsort(){
        for(int i=0;i<=Len;i++) num[i]=0;
        for(int i=1;i<=e1;i++) num[len[i]]++;
        for(int i=1;i<=Len;i++) num[i]+=num[i-1];
        for(int i=1;i<=e1;i++) id[num[len[i]]--]=i;
        for(int i=e1;i>1;i--){
            int x=id[i];
            if(you[x])you[fa[x]]=len[fa[x]];
            ans+=len[x]-max(len[fa[x]],you[x]);
        }
    }
}S;
char ss[maxn];
int main(){
   // freopen("in.txt","r",stdin);
    int t;cin>>t;
    int cnt;
    while(t--){
        ++cnt;
        int n;cin>>n;
        scanf("%s",ss+1);
        S.init();
        Len=strlen(ss+1);
        for(int i=1;i<=Len;i++) S.add(ss[i]-'a');
        int now=1,len=0;
        ans=0;
        while(n--){
            scanf("%s",ss+1);now=1;len=0;
            int ll=strlen(ss+1);
            for(int i=1;i<=ll;i++){
                int x=ss[i]-'a';
                while(!S.tr[now][x]&&now>1) now=S.fa[now],len=S.len[now];
                if(S.tr[now][x]) now=S.tr[now][x],len++;
                S.you[now]=max(S.you[now],len);
            }
        }
        S.topsort();
        printf("Case %d: %I64d\n",cnt,ans);
    }
    return 0;
}
