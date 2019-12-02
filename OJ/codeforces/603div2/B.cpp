#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
char s[16][20];
int vis[10007];
int d(int x){
    return x-'0';
}
int you[16];
int now[10];
int main(){
    int t=read();
    while(t--){
        memset(vis,0,sizeof(vis));
        memset(now,0,sizeof(now));
        int n=read(),cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
            int x=d(s[i][1])*1000+d(s[i][2])*100+d(s[i][3])*10+d(s[i][4]);
            now[d(s[i][1])]=1;
            if(!vis[x]) vis[x]=1,you[i]=0;
            else{
                you[i]=1;
            }
        }
        for(int i=1;i<=n;i++){
            if(you[i]){
                cnt++;
                for(int k=0;k<10;k++){
                    if(!now[k]){
                        s[i][1]='0'+k;
                        now[k]=1;break;
                    }
                }
            }
        }
        cout<<cnt<<"\n";
        for(int i=1;i<=n;i++){
            printf("%s\n",s[i]+1);
        }
    }
    return 0;
}