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
int n,m;
int id(int x,int y){
    return (x-1)*m+y;
}
char s[1000007];
int a[1000007];
int to[1000007];
int st[1000007][21];
int a1[1000007],a2[1000007];
int main(){
    int t=read();
    while(t--){
        n=read(),m=read();
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);
            for(int k=1;k<=m;k++){
                a[id(i,k)]=s[k]-'0';
                a1[id(i,k)]=a2[id(i,k)]=0;
            }
        }  
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);
            for(int k=1;k<=m;k++){
                if(s[k]=='U') to[id(i,k)]=id(i-1,k);
                if(s[k]=='L') to[id(i,k)]=id(i,k-1);
                if(s[k]=='R') to[id(i,k)]=id(i,k+1);
                if(s[k]=='D') to[id(i,k)]=id(i+1,k);
            }
        }
        for(int i=1;i<=n*m;i++) st[i][0]=to[i];
        for(int i=1;i<=20;i++){
            for(int k=1;k<=n*m;k++){
                st[k][i]=st[st[k][i-1]][i-1];
            }
        }
        for(int i=1;i<=n*m;i++){
            int x=st[i][20];
            a1[x]++;a2[x]|=!a[i];
          //  cout<<st[i][0]<<" "<<st[i][1]<<" "<<i<<endl;
        }
        int ans1=0,ans2=0;
        for(int i=1;i<=n*m;i++){
            if(a1[i]){
                ans1++;
                if(a2[i]) ans2++;
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}