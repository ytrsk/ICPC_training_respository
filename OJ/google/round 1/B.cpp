#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[107],tmp[107];
int top;char S[100007];
int ml,mr;
char sl[10007],sr[10007];
int main(){
    int t=read();int cnt=0;
    while(t--){
        int n=read();top=0;ml=mr=0;
        int ok=1;
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);
            int len=strlen(s+1);
            int L=1,R=len;
            if(s[1]!='*'){
                while(s[L]!='*') ++L;
                for(int i=1;i<=min(ml,L-1);i++){
                    if(s[i]!=sl[i]) ok=0;
                }
                for(int i=ml+1;i<=L-1;i++) sl[i]=s[i]; 
                ml=max(ml,L-1);
            }
            if(s[len]!='*'){
                while(s[R]!='*') R--;
                for(int i=1;i<=min(mr,len-R);i++){
                    if(s[len-i+1]!=sr[i]) ok=0;
                }
                for(int i=mr+1;i<=len-R;i++) sr[i]=s[len-i+1];
                mr=max(mr,len-R);
            }
            for(int i=L+1;i<=R-1;i++){
                if(s[i]!='*') S[++top]=s[i];
            }
        }
        printf("Case #%d: ",++cnt);
        if(ok){
            for(int i=1;i<=ml;i++) printf("%c",sl[i]);
            for(int i=1;i<=top;i++) printf("%c",S[i]);
            for(int i=mr;i;i--) printf("%c",sr[i]);
            printf("\n");
        }
        else printf("*\n");
    }
    return 0;
}