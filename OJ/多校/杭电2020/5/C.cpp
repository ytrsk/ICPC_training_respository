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
int pos[1000007],a[1000007];
vector<int> v[1000007],V[1000007];
int main(){
    int t=read();
    while(t--){
        int n=read(),K=read();
        int cnt=0;
        for(int i=1;i<=2*n;i++) v[i].resize((1<<K)+1);
        for(int i=1;i<=n;i++){
            for(int k=1;k<=(1<<K);k++){
                v[2*i-1][k]=++cnt;
            }
            for(int k=1;k<=(1<<K);k++){
                v[2*i][k]=++cnt;
            }
        }
        for(int i=1;i<=cnt;i++) a[i]=read();
        int h=2*n,w=(1<<K);
        for(int i=1;i<=K;i++){
            for(int k=1;k<=h;k++) V[k].resize((w/2)+1);
            for(int k=1;k<=h;k++){
                for(int z=1;z<=w/2;z++){
                    V[k][z]=v[h-k+1][w/2-z+1];
                }
            }
            for(int k=h+1;k<=h*2;k++){
                v[k].resize(w/2+1);
                for(int z=1;z<=w/2;z++){
                    v[k][z]=v[k-h][z+w/2];
                }
                v[k-h]=V[k-h];
            }
            h*=2;w/=2;
        }
        for(int i=1;i<=h;i++){
            pos[v[i][1]]=a[i];
        }
        for(int i=1;i<=cnt;i++) printf("%d%c",pos[i],i==cnt?'\n':' ');
    }
    return 0;
}