#include <bits/stdc++.h>
#define mp make_pair
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
#include <bits/stdc++.h>
using namespace std;
const int maxn=400007;
struct NODE{
    int ch[26];
    int len,fa,sz;
    void cl(){
        len=0;sz=0;memset(ch,0,sizeof(ch));
    }
    NODE(){memset(ch,0,sizeof(ch));len=0;sz=0;}
}dian[maxn<<1];
int las=1,tot=1;
vector<int> g[maxn];
void add(int c,int pos){
    int p=las;int np=las=++tot;
    dian[tot].cl();
    dian[np].len=dian[p].len+1;
    for(;p&&!dian[p].ch[c];p=dian[p].fa)dian[p].ch[c]=np;
    if(!p)dian[np].fa=1;
    else{
        int q=dian[p].ch[c];
        if(dian[q].len==dian[p].len+1)dian[np].fa=q;
        else{
            int nq=++tot;dian[nq]=dian[q];
            dian[nq].cl();
            dian[nq].len=dian[p].len+1;
            dian[q].fa=dian[np].fa=nq;
            for(;p&&dian[p].ch[c]==q;p=dian[p].fa)dian[p].ch[c]=nq;

        }
    }
}
char s[maxn];int len;
char a[maxn];
int main(){
    int t;cin>>t;
    while(t--){
        scanf("%s",s+1);
        tot=las=1;
        dian[1].cl();
        len=strlen(s+1);
        for(int i=1;i<=len;i++) add(s[i]-'a');
        for(int i=2;i<=tot;i++) dian[dian[i].fa].sz+=dian[i].sz;
        int m;cin>>m;
        for(int i=1;i<=m;i++){
            scanf("%s",a+1);
            int L=strlen(a+1);
            int now=1;
            int ok=1;
            for(int k=1;k<=L;k++){
                if(dian[now].ch[a[k]-'a']){
                    now=dian[now].ch[a[k]-'a'];
                }
                else{
                    ok=0;break;
                }
            }
            if(ok) printf("%d\n",dian[now].sz);
            else printf("1\n");
        }
    }
    return 0;
}
