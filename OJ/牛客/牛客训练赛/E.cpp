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
int les[maxn],a[maxn];
struct node{
    int l,r,x,id;
    bool operator < (node a) const{
        return l<a.l;
    }
}p[maxn];
int ans[maxn];
vector<int> g[maxn],fac[maxn],G[maxn];
int main(){
    int n=read(),q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=100000;i++) les[i]=-1;
    for(int i=2;i<=100000;i++)
    for(int k=i;k<=100000;k+=i) g[k].push_back(i);
    for(int i=1;i<=q;i++){
        int l=read(),r=read(),x=read();
        p[i]=node{l,r,x,i};
    }
    for(int i=1;i<=q;i++) G[p[i].r].push_back(i);
    for(int i=1;i<=n;i++){
        for(int k=0;k<g[a[i]].size();k++){
            les[g[a[i]][k]]=max(les[g[a[i]][k]],i);
        }
        for(int k=0;k<G[i].size();k++){
            int Ans=1,num=p[G[i][k]].x;
            for(int z=g[num].size()-1;~z;z--){
                int x=g[num][z];
                if(les[x]>=p[G[i][k]].l) {Ans=x;break;}
            }
            ans[G[i][k]]=Ans;
        }
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}