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
int now=0;char s[maxn];
int main(){
    int n=read(),m=read(),K=read();
    for(int i=1;i<=K;i++){
        int x=read(),y=read();
    }
    for(int i=1;i<=n-1;i++) s[++now]='U';
    for(int i=1;i<=m-1;i++) s[++now]='L';
    for(int i=1;i<=K;i++){
        int x=read(),y=read();
    }
    int opt=0;
    for(int i=1;i<=n;i++){
        if(!opt){
            for(int k=1;k<m;k++) s[++now]='R';
        }
        else{
            for(int k=1;k<m;k++) s[++now]='L';
        }
        if(i<n) s[++now]='D';
        opt^=1;
    }
    printf("%d\n",now);s[++now]='\0';
    printf("%s",s+1);
    return 0;
}