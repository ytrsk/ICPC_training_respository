#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=307;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[300*300];
int fa[307];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
bitset<301> S[307];
int ans[maxn],n;
int C(int x,int y){
    return (S[x]&S[y]).count();
}
int main(){
    int t=read();
    while(t--){
        n=read();int m=read();
        scanf("%s",s+1);int c=0;
        for(int i=1;i<=n;i++) fa[i]=i; 
        for(int i=1;i<=n;i++) S[i].reset(),S[i][i]=1;
        for(int i=1;i<=n-1;i++){
            for(int k=i+1;k<=n;k++){
                c++;
                S[i][k]=S[k][i]=s[c]-'0';
            }
        }

        for(int i=1;i<=n;i++){
            int mx=0;
            for(int k=1;k<=n;k++){
                if(k!=i) mx=max(mx,C(i,k));
            }
            for(int k=1;k<=n;k++){
                if(C(i,k)>=mx*2/3) fa[find(i)]=find(k);
            }
        }
        int cnt=0;
        map<int,int> aa;
        for(int i=1;i<=n;i++){
            if(aa[find(i)]) printf("%d ",aa[find(i)]-1);
            else aa[find(i)]=++cnt,printf("%d ",cnt-1);
        }
        printf("\n");
    }
    return 0;
}