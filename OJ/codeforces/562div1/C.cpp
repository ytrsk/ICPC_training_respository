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
int a[21][300007],v[300007];
int mn[300007][21],pos[300007][21];
int main(){
    int n=read(),q=read();
    for(int i=1;i<=n;i++) v[i]=read();
    for(int i=1;i<=n;i++){
        for(int k=0;k<=20;k++){
            if(v[i]>>k&1) a[k][++a[k][0]]=i;
        }
    }
    for(int i=n;i;i--){
        for(int k=0;k<20;k++){
            if(v[i]>>k&1) mn[i][k]=i;
            else mn[i][k]=inf;
        }
        for(int k=0;k<=20;k++){
            int r=0;                
            if(v[i]>>k&1){
                int x=upper_bound(a[k]+1,a[k]+a[k][0]+1,i)-a[k];
                if(x!=a[k][0]+1) r=a[k][x];
            }
            if(r){
                for(int z=0;z<=20;z++){
                    mn[i][z]=min(mn[i][z],mn[r][z]);
                }
            }
        }
    }
    while(q--){
        int x=read(),y=read();
        int ok=0;
        for(int i=0;i<=20;i++){
            if((v[y]>>i&1)&&mn[x][i]<=y) ok=1;
        }
        if(ok) printf("Shi\n");
        else printf("Fou\n");
    }
    return 0;
}