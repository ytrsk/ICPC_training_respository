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
char s[100007];
int main(){
    int t=read(),cnt=0;
    while(t--){
        ++cnt;
        int n=read();
        int type,ans=0;
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);
            if(s[1]=='l'){
                scanf("%s",s+1);
                if(s[1]=='d') type=16;
                else type=8;
            }
            else if(s[1]=='b') type=1;
            else if(s[1]=='c') type=1;
            else if(s[1]=='i'||s[1]=='f') type=4;
            else if(s[1]=='d') type=8;
            else type=16;
            scanf("%s",s+1);
            int len=strlen(s+1);
            if(s[len-1]==']'){
                int x=0;
                for(int k=1;k<=len;k++){
                    if(s[k]>='0'&&s[k]<='9') x=x*10+s[k]-'0';
                }
                type*=x;
            }
            //cout<<type<<endl;
            ans+=type;
        }
        printf("Case #%d: %d\n",cnt,(ans-1)/1024+1);
    }

    return 0;
}
