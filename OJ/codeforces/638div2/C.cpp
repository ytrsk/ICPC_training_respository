#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[100007];
int you[27];
char t[100007];
int main(){
    int T=read();
    while(T--){
        memset(you,0,sizeof(you));
        int n=read(),m=read();
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            you[s[i]-'a']++;
        }
        int pos=0,now=m;
        int Now=1;
        int fi=-1,ed=-1;
        while(pos<26&&Now<=m){
            if(you[pos]){
                if(fi==-1) fi=pos;
                you[pos]--;
                if(Now==m) printf("%c",'a'+pos),ed=pos;
                Now++;
            }
            else pos++;
        }
        if(fi!=ed){
            printf("\n");continue;
        }
        while(pos<26){
            if(you[pos]){
                int x=you[pos]/m;
                int OK=0;
                for(int i=pos+1;i<26;i++) if(you[i]) OK=1;
                if(OK){
                    while(pos<26){
                        while(you[pos]--) printf("%c",pos+'a');
                        pos++; 
                    }
                    break;
                }
                else{
                    for(int i=(you[pos]-1)/m+1;i>=1;i--) printf("%c",pos+'a');
                }
                break;
            }
            else pos++;
        }
        printf("\n");
    }
    return 0;
}