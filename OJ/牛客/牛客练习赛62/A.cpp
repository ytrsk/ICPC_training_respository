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
int u[maxn],v[maxn];
vector<int> g[maxn];
set<int> s[maxn];
int main(){
    int t=read();
    while(t--){
        map<int,int> you;
        int n=read(),m=read(),ok=0;
        for(int i=1;i<=n;i++) s[i].clear(),g[i].clear();
        for(int i=1;i<=m;i++){
            u[i]=read(),v[i]=read();
            if(u[i]>v[i]) swap(u[i],v[i]);
            g[u[i]].push_back(v[i]);s[u[i]].insert(v[i]);
        }
        int ss=sqrt(m);
        for(int i=1;i<=n;i++){
            for(int k=0;k<g[i].size();k++){
                int x=g[i][k];
                if(g[x].size()>ss){
                    for(int z=k+1;z<g[i].size();z++){
                        int y=g[i][z];
                        if(s[x].find(y)!=s[x].end()){
                            ok=1;break;
                        }
                    }
                }
                else{
                    for(int z=0;z<g[x].size();z++){
                        int y=g[x][z];
                        if(s[i].find(y)!=s[i].end()){
                            ok=1;break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(ok) break;
            for(int k=i+1;k<=n;k++){
                if(ok) break;
                if(s[i].find(k)==s[i].end()){
                    for(int z=k+1;z<=n;z++){
                        if(s[i].find(z)==s[i].end()&&s[k].find(z)==s[k].end()){
                            ok=1;break;
                        }
                    }
                }
                
            }
        }
        if(ok) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}